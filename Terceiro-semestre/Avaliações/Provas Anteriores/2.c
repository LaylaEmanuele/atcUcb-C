/* S�ntese
	Objetivo: Verificar se h� algum n�mero que seja igual a soma de outros dois 
	Autora: Layla Emanuele 
	Data: 15/06/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Declara��o de tipo 
struct tLista{
	int numero;
};

struct tNo{
	struct tLista dado;
	struct tNo *prox;
};

//Prot�tipos das fun��es
void inicializar(struct tNo **);
int menu();
void incluir(struct tNo **, struct tNo *);
void listar(struct tNo *);
char encontraSoma(struct tNo *);

//Principal
int main(){
	setlocale(LC_ALL, "Portuguese");
	struct tNo *p, *lista;
	int opcao;
	char resposta;
	inicializar(&lista);
	
	do{
		system("cls");
		opcao = menu();
		system("cls");
		switch(opcao){
			case 1:
				printf("***Inclus�o***\n");
				p = malloc(sizeof(struct tNo));
				printf("Informe o n�mero:");
				scanf("%d", &p->dado.numero);
				incluir(&lista, p);
		
				break;
				
			case 2:
				printf("***Listagem***\n");
				listar(lista);
				getch();
				
				break;
			
			case 3:
				printf("***Encontrar n�mero***\n");				
				resposta = encontraSoma(lista);
				printf("%c", resposta);
				getch();
				break;	

		}
		
		
	}while(opcao != 0);

	
	return 0;
}

//Fun��es
void inicializar(struct tNo **lst){
	(*lst) = NULL;
}

int menu(){
	int op;
	printf("***MENU***\n");
	printf("1. Inclus�o\n");
	printf("2. Listagem\n");
	printf("3. Achar soma\n");
	printf("0. Sair\n");
	scanf("%d", &op);
	return op; 
}

void incluir(struct tNo **lst, struct tNo *p){
	
	p->prox = (*lst);
	(*lst) = p;
	
}

void listar(struct tNo *lst){
	struct tNo *p = lst;
	
	while(p != NULL){
		printf("%d\n", p->dado.numero);
		p = p->prox;
	}
}

char encontraSoma(struct tNo *lst){
	char flag;
	struct tNo *p = lst, *q = p->prox;
	int num1 = 0, num2 = 0, soma = 0;
	
	while(p != NULL){	
		do{
		
			if(q->dado.numero != p->dado.numero){
				num1 = num2;
				num2 = q->dado.numero;
				soma = num1 + num2;
				
				if(soma == p->dado.numero)
					return flag = 'V'; 
				else
					flag = 'F';
			}
			q = q->prox; 		
		
		}while(q != NULL);
		q = lst;
		p = p->prox;
	}
	
	if(flag == 'V')
		return 'V';
	else 
		return 'F';		
}


