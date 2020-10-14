/*S�ntese:
	Objetivo: LSE modularizada de produtos
	Data: 17/10/2019
	Autores: Gabriel Raposo e Layla Emanuele.

*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Declaracao de tipo
struct tProduto {
	int codigo;
	char descricao[20];
	float valor;
};

struct tNo {
	struct tProduto dado;
	struct tNo *prox;
};

// Prototipos de funcao
int menu(void);
void incluir(struct tNo **lis, struct tNo *novo);
void listar(struct tNo *lis);
struct tNo* consultar(int cod, struct tNo *lis);
int alterar(int cod, struct tNo *lis);

//--- Main ---------------------------------------------------------------
int main(void) {
	setlocale(LC_ALL,"Portuguese");
	struct tNo *lista=NULL;
	struct tNo *p, *q, *pesquisa;
	int opcao, pesqCod, encontrou;
	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch (opcao) {
			case 1:
				printf("\n\n*** Inclusao ***\n");
				p = malloc(sizeof(struct tNo));

				printf("Digite o c�digo do produto: ");
				scanf("%d", &( (*p).dado.codigo ));
				printf("Digite a descri��o do produto: ");
				fflush(stdin);
				gets( (*p).dado.descricao );
				printf("Digite o valor do produto: ");
				scanf("%f", &((*p).dado.valor) );
				incluir(&lista,p);
				break;
				
			case 2:
				
				printf("\n\n*** Listagem ***\n");
				listar(lista);
				printf("\nPressione qualquer tecla para continuar");
				getch();
				break;

			case 3:
				printf("\n\n*** Consulta ***\n");				

				printf("Qual o c�digo do produto que deseja encontrar?\n");
				scanf("%d",&pesqCod);
				pesquisa=consultar(pesqCod,lista);				

				if(pesquisa == NULL)
					printf("Produto n�o encontrado!");
				else
					printf("Produto encontrado!");	
					
				printf("\nPressione qualquer tecla para continuar");
				getch();	
				break;

			case 4:

				printf("\n\n*** Consulta ***\n");
				printf("Qual o c�digo do produto que deseja alterar as informa��es?\n");
				scanf("%d",&pesqCod);
				encontrou=alterar(pesqCod, lista);


				if(encontrou !=1)
					printf("Produto n�o encontrado!");
				else
					printf("Produto alterado com sucesso!");
					
				printf("\nPressione qualquer tecla para continuar");
				getch();	
				break;
		}
	} while (opcao != 0);
	
	p = lista;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	return 0; 
}

//--- Menu ---------------------------------------------------------------
int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Inclusao\n");
	printf("2. Listagem\n");
	printf("3. Consulta\n");
	printf("4. Altera��o\n");
	printf("5. Exclus�o\n");
	printf("0. Sair\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

//--- Inclus�o -----------------------------------------------------------
void incluir(struct tNo **lis, struct tNo *novo){
	novo->prox = *lis;
	*lis = novo;	
}

//--- Listagem -----------------------------------------------------------
void listar(struct tNo *lis){
	while (lis != NULL) {
		printf("--> %s\n", lis->dado.descricao);
		lis = lis->prox;
	}
}

//--- Consulta -----------------------------------------------------------
 struct tNo* consultar(int cod, struct tNo *lis){
	while (lis != NULL) {
		if(lis->dado.codigo == cod)
			return lis;
		
		lis = lis->prox;
	}
	
	return NULL;
}

//--- Alterar ------------------------------------------------------------
int alterar(int cod, struct tNo *lis){
	
	while (lis != NULL) {
		if(lis->dado.codigo == cod){
			printf("Digite a nova descri��o do produto: ");
			fflush(stdin);
			gets(lis->dado.descricao );
			printf("Digite o novo valor do produto: ");
			scanf("%f", &(lis->dado.valor) );
			return 1;
		}
		lis = lis->prox;
	}
	
	return 0;
}
