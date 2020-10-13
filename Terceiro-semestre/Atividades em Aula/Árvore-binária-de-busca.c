/* S�ntese
	Objetivo: Apresentar altura de um n� e seu fb de uma �rvore bin�ria de busca
	Autora: Layla Emanuele
	Data: 20/05/2020
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//Declara��es de tipo de vari�veis
struct tProduto {
	int codigo;
	char descricao[80];
	int altura;
};

struct tNo {
	struct tNo *esq;
	struct tNo *dir;
	struct tProduto dado;
};

//Prot�tipos das fun��es
void inicializar(struct tNo **);
int menu();
void incluir(struct tNo **, struct tNo *);
void preordem(struct tNo *);
void emordem(struct tNo *);
void posordem(struct tNo *);
struct tNo *consultar(struct tNo *, int );
int grau(struct tNo *);
struct tNo *menor (struct tNo *);
int excluir(struct tNo **, int );
void destruir (struct tNo *);

int fb(struct tNo *p, int *contD, int *contE) {
	if(p->dir != NULL) {
		(*contD)++;
		fb(p->dir,contD,contE);
	} else if(p->esq != NULL) {
		(*contE)++;
		fb(p->esq,contD,contE);
	}
}

//Fun��o Principal
int main(void) {
	int opcao, pesqCod, balanceado;
	struct tNo *arvore, *no, *p;
	int contD = 0;
	int contE = 0;
	balanceado = 0;
	setlocale(LC_ALL,"Portuguese");
	printf("x");
	inicializar(&arvore);

	do {
		system("cls");
		opcao = menu();
		system("cls");
		switch(opcao) {
			case 1:
				no = malloc(sizeof(struct tNo));
				printf("-------Inclus�o-------\n");
				printf("Qual o c�digo do produto?\n");
				scanf("%d", &(no->dado.codigo));

				printf("Qual a descri��o do produto?\n");
				fflush(stdin);
				gets(no->dado.descricao);

				incluir(&arvore, no);
				break;
			case 2:
				printf("-------Listagem Pr� Ordem-------\n");
				preordem(arvore);
				getch();
				break;
			case 3:
				printf("-------Listagem Em Ordem-------\n");
				emordem(arvore);
				getch();
				break;
			case 4:
				printf("-------Listagem P�s Ordem-------\n");
				posordem(arvore);
				getch();
				break;
			case 5:
				printf("-------Consultar-------\n");
				printf("Qual o c�digo a ser consultado?\n");
				scanf("%d", &pesqCod);
				if(consultar(arvore, pesqCod) != NULL)
					printf("Encontrou");
				else
					printf("N�o encontrou");
				getch();
				break;
			case 6:
				printf("-------Exclus�o-------\n");
				printf("Qual c�digo ser� exclu�do?\n");
				scanf("%d", &pesqCod);
				if(excluir(&arvore, pesqCod))
					printf("Exclu�do");
				else
					printf("N�o foi encontrado");
				getch();
				break;
			case 7:
				printf("-------Altura de um n�-------\n");
				printf("Qual o c�digo a ser consultado?\n");
				scanf("%d", &pesqCod);

				if(consultar(arvore, pesqCod) != NULL)
					printf("A altura do n� �:%d", arvore->dado.altura);
				else
					printf("N�o encontrou");
				getch();
				break;
			case 8:
				printf("-------Fator de Balanceamento de um n�-------\n");
				printf("Qual o c�digo a ser consultado?\n");
				scanf("%d", &pesqCod);
				p = consultar(arvore, pesqCod);

				balanceado = fb(p, &contD, &contE);
				if((contD-contE) != 0 || (contD-contE) != 0)
					printf("N� n�o balanceado");
				else
					printf("Est� balanceado");
				getch();
				break;

		}
	} while(opcao!=0);

	destruir(arvore);

	return 0;
}

//Fun��es
void inicializar(struct tNo **raiz) {
	(*raiz) = NULL;
}

int menu() {
	int op;
	printf("-------Menu-------\n");
	printf("1 - Inclus�o\n");
	printf("2 - Listagem Pr� Ordem\n");
	printf("3 - Listagem Em Ordem\n");
	printf("4 - Listagem P�s Ordem\n");
	printf("5 - Consulta\n");
	printf("6 - Exclus�o\n");
	printf("7 - Altura de um n�\n");
	printf("7 - Fator de Balanceamento de um n�\n");
	printf("0 - Sair\n");
	printf("Digite a op��o desejada:\n");
	scanf("%d",&op);
	return op;
}

void incluir(struct tNo **raiz, struct tNo *p) {
	
	if((*raiz) == NULL) { //sem n�s na arvore
		(*raiz) = p;
		p->esq = p->dir = NULL;
	} else {
		if(p->dado.codigo < (*raiz)->dado.codigo) {
			incluir(&((*raiz)->esq), p);
		} else
			incluir(&((*raiz)->dir), p);
	}
	(*raiz)->dado.altura = 0;
	(*raiz)->dado.altura++;
}

void preordem(struct tNo *raiz) {
	if(raiz == NULL)
		return;
	printf("->%d\n", raiz->dado.codigo);
	printf("->%s\n", raiz->dado.descricao);
	preordem(raiz->esq);
	preordem(raiz->dir);
}

void emordem(struct tNo *raiz) {
	if(raiz == NULL)
		return;
	emordem(raiz->esq);
	printf("->%d\n", raiz->dado.codigo);
	printf("->%s\n", raiz->dado.descricao);
	emordem(raiz->dir);

}

void posordem(struct tNo *raiz) {
	if(raiz == NULL)
		return;
	posordem(raiz->esq);
	posordem(raiz->dir);
	printf("->%d\n", raiz->dado.codigo);
	printf("->%s\n", raiz->dado.descricao);
}

struct tNo *consultar(struct tNo *raiz, int cod) {
	if((raiz == NULL) || (raiz->dado.codigo == cod))
		return raiz;
	if(cod < raiz->dado.codigo)
		consultar(raiz->esq, cod);
	return consultar(raiz->dir, cod);
}

int grau(struct tNo *raiz) {
	if((raiz->esq == NULL) && (raiz->dir == NULL))
		return 0;
	if((raiz->esq != NULL) && (raiz->dir != NULL))
		return 2;
	return 1;
}

struct tNo *menor (struct tNo *raiz) {
	if((raiz == NULL) || (raiz->esq == NULL))
		return raiz;
	menor(raiz->esq);

}

int excluir(struct tNo **raiz, int cod) {
	struct tNo *p;
	if((*raiz) == NULL)
		return 0;
	if((*raiz)->dado.codigo == cod) {
		if(grau(*raiz) == 0) { //grau = 0
			free(*raiz);
			*raiz = NULL;
		} else {
			if(grau(*raiz) == 1) { //grau igual a 1
				p = (*raiz);
				if((*raiz)->esq !=NULL)
					(*raiz) = (*raiz)->esq;
				else
					(*raiz) = (*raiz)->dir;
				free(p);
			} else { //grau igual 2
				p = menor((*raiz)->dir);
				(*raiz)->dado.codigo = p->dado.codigo;
				excluir(&((*raiz)->dir), p->dado.codigo);
			}
		}
		return 1;
	}
	if(cod < (*raiz)->dado.codigo)
		return excluir(&((*raiz)->esq), cod);
	return 	excluir(&((*raiz)->dir), cod);
}

void destruir (struct tNo *raiz) {
	if(raiz == NULL)
		return;
	destruir(raiz->esq);
	destruir(raiz->dir);
	free(raiz);
}
