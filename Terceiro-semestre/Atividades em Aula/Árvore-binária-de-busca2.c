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
};

struct tNo {
	struct tNo *esq;
	struct tNo *dir;
	struct tProduto dado;
};

//Prot�tipos das fun��es
void inicializar(struct tNo **);
int menu();
int menu2();
int verificaPF(struct tNo *, struct tNo *);
int verificaFP(struct tNo *, struct tNo *);
int verificaNA(struct tNo *, struct tNo *);
void nivel(struct tNo *, struct tNo *, int *);
int folha(struct tNo *);
void rotacaoSD(struct tNo **);
void rotacaoSE(struct tNo **);
void balancearAVL(struct tNo **);
void incluir(struct tNo **, struct tNo *);
void preordem(struct tNo *);
void emordem(struct tNo *);
void posordem(struct tNo *);
void calcH(struct tNo *, int *);
int fb(struct tNo *);
struct tNo *consultar(struct tNo *, int );
void altFB(struct tNo *, int , int );
int grau(struct tNo *);
struct tNo *menor (struct tNo *);
int excluir(struct tNo **, int );
void representa(struct tNo *);
void destruir (struct tNo *);

//Fun��o Principal
int main(void) {
	int opcao, pesqCod, altura = 0, alturaD = 0, alturaE = 0, valorFB, op, pesqCod2, resp, n = 0;
	struct tNo *arvore, *no, *p, *q, *r, *s;
	setlocale(LC_ALL,"Portuguese");

	inicializar(&arvore);

	do {
		alturaD = 0;
		alturaE = 0;
		altura = 0;

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
				q = consultar(arvore, pesqCod);

				if(q != NULL) {
					calcH(q->dir, &alturaD);
					calcH(q->esq, &alturaE);

					if(alturaD>alturaE)
						altura = alturaD;
					else
						altura = alturaE;

					valorFB = fb(q);
					altFB(q, valorFB, altura); //fun��o para mostrar em detalhes
				} else
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
				representa(arvore);
				getch();
				break;
			case 8:
				do {
					system("cls");
					op = menu2();
					system("cls");
					switch(op) {
						case 1:
							printf("-------Verifica��o Pai e Filho-------\n");
							printf("Qual o 1� c�digo a ser consultado?\n");
							scanf("%d", &pesqCod);
							printf("Qual o 2� c�digo a ser consultado?\n");
							scanf("%d", &pesqCod2);

							r = consultar(arvore, pesqCod);
							s = consultar(arvore, pesqCod2);

							resp = verificaPF(r, s);

							if(resp == 0)
								printf("Verdadeiro");
							else
								printf("Falso");
							getch();
							break;
							
						case 2:
							printf("-------Verifica��o Filho e Pai-------\n");
							printf("Qual o 1� c�digo a ser consultado?\n");
							scanf("%d", &pesqCod);
							printf("Qual o 2� c�digo a ser consultado?\n");
							scanf("%d", &pesqCod2);
							r = consultar(arvore, pesqCod);
							s = consultar(arvore, pesqCod2);

							resp = verificaFP(r, s);

							if(resp == 0)
								printf("Verdadeiro");
							else
								printf("Falso");
							getch();
							break;
							
							case 3:
							printf("-------Verifica��o Neto e Av�-------\n");
							printf("Qual o 1� c�digo a ser consultado?\n");
							scanf("%d", &pesqCod);
							printf("Qual o 2� c�digo a ser consultado?\n");
							scanf("%d", &pesqCod2);
							r = consultar(arvore, pesqCod);
							s = consultar(arvore, pesqCod2);

							resp = verificaNA(r, s);

							if(resp == 0)
								printf("Verdadeiro");
							else
								printf("Falso");
							getch();
							break;		
							
							case 4:
								printf("-------Verifica��o de N�vel-------\n");
								printf("Qual o c�digo a ser consultado?\n");
								scanf("%d", &pesqCod);
								r = consultar(arvore, pesqCod);
								nivel(arvore, r, &n);
								printf("N�vel: %d", n);
								getch();
								break;
								
							case 5:
								printf("-------Verifica��o de Profundidade-------\n");
								printf("Qual o 1� c�digo a ser consultado?\n");
								scanf("%d", &pesqCod);
								printf("Qual o 2� c�digo a ser consultado?\n");
								scanf("%d", &pesqCod2);
								
								r = consultar(arvore, pesqCod); //raiz
								s = consultar(arvore, pesqCod2); //codigo
								
								nivel(r, s, &n);
								printf("Profundidade: %d", n);
								getch();
								break;
								
							case 6:
								printf("-------Grau de um n�-------\n");
								printf("Qual o c�digo a ser consultado?\n");
								scanf("%d", &pesqCod);
								r = consultar(arvore, pesqCod);
								n = grau(r);
								printf("Grau: %d", n);
								getch();
								break;
							case 7:
								printf("-------Grau da �rvore-------\n");
								n = grau(arvore);
								printf("Grau: %d", n);
								getch();
								break;
							case 8:
								printf("-------Verifica��o se � folha-------\n");
								printf("Qual o c�digo a ser consultado?\n");
								scanf("%d", &pesqCod);
								r = consultar(arvore, pesqCod);
								resp = folha(r);
								if(resp == 0)
									printf("Verdadeiro");
								else
									printf("Falso");
								getch();
								break;
						
					} 
				
				} while(op != 0);
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
	printf("7 - Representa��o\n");
	printf("8 - Mais op��es\n");
	printf("0 - Sair\n");
	printf("Digite a op��o desejada:\n");
	scanf("%d",&op);
	return op;
}

int menu2() {
	int op;
	printf("-------Mais op��es-------\n");
	printf("1 - Verifica��o 1� Pai e 2� Filho\n");
	printf("2 - Verifica��o 1� Filho e  2� Pai\n");
	printf("3 - Verifica��o 1� Neto e 2� Av�\n");
	printf("4 - Verifica��o n�vel\n");
	printf("5 - Verifica��o profundidade\n");
	printf("6 - Grau de um n�\n");
	printf("7 - Grau da �rvore\n");
	printf("8 - Verifica��o se � folha\n");
	printf("0 - Voltar\n");
	printf("Digite a op��o desejada:\n");
	scanf("%d",&op);
	return op;
}

int verificaPF(struct tNo *cod1, struct tNo *cod2) {
	int flag;
	if((cod1->dir == cod2) || (cod1->esq == cod2)) //cod 1 � pai e cod 2 � filho
		flag = 0;
	else 
		flag = 1;
	
	return flag;
}

int verificaFP(struct tNo *cod1, struct tNo *cod2) {
	int flag;
	if((cod2->dir == cod1) || (cod2->esq == cod1)) //cod 1 � filho e cod 2 � pai
		flag = 0;
	else 
		flag = 1;
	
	return flag;
}

int verificaNA(struct tNo *cod1, struct tNo *cod2) {
	int flag;
	if((cod2->dir == NULL) || (cod2->esq == NULL))
		flag = 1;
	else if((cod2->dir->dir == cod1) || (cod2->esq->esq == cod1)) //cod 1 � neto cod 2 � av� 
		flag = 0;
	else 
		flag = 1;
	
	return flag;
}

void nivel(struct tNo *raiz, struct tNo *no, int *n){
	if(raiz->esq == NULL)
		return ;
	if(raiz->dir == NULL)
		return ;	
	if(raiz->esq != no)
		nivel(raiz->esq, no, n);
	else if(raiz->dir != no)
			nivel(raiz->dir, no, n);
	*n = *n + 1;
}

int folha(struct tNo *no){
	int flag;
	if((no->dir != NULL) || (no->esq != NULL))
		flag = 1;
	else
		flag = 0;
	return flag;
}

void rotacaoSD(struct tNo **pai) {
	struct tNo *filho = (*pai)->esq;
	(*pai)->esq = filho->dir;
	filho->dir = (*pai);
	(*pai) = filho;
}

void rotacaoSE(struct tNo **pai) {
	struct tNo *filho = (*pai)->dir;
	(*pai)->dir = filho->esq;
	filho->esq = (*pai);
	(*pai) = filho;
}

void balancearAVL(struct tNo **raiz) {
	int fat = fb(*raiz);
	if((fat != 2) && (fat != -2))
		return;
	if((fat == 2) && (fb((*raiz)->dir) == 1))	//simples esquerda
		rotacaoSE(raiz);
	else {
		if((fat == -2) && (fb((*raiz)->esq) == -1))	//simples direita
			rotacaoSD(raiz);
		else {
			if((fat == 2) && (fb((*raiz)->dir) == - 1)) { //dupla esquerda
				rotacaoSD(&((*raiz)->dir));
				rotacaoSE(raiz);
			} else { //dupla direita
				rotacaoSE(&((*raiz)->esq));
				rotacaoSD(raiz);
			}
		}
	}
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
	balancearAVL(raiz);
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

void calcH(struct tNo *raiz, int *altura) {
	if(raiz == NULL)
		return ;
	*altura = *altura + 1;
	if(raiz->esq != NULL)
		calcH(raiz->esq, altura);
	if(raiz->dir != NULL)
		calcH(raiz->dir, altura);
}

int fb(struct tNo *raiz) {
	int alturaD = 0, alturaE = 0;
	if(raiz == NULL)
		return;

	calcH(raiz->dir, &alturaD);
	calcH(raiz->esq, &alturaE);

	return alturaD - alturaE;
}

struct tNo *consultar(struct tNo *raiz, int cod) {
	if((raiz == NULL) || (raiz->dado.codigo == cod))
		return raiz;
	if(cod < raiz->dado.codigo)
		return consultar(raiz->esq, cod);
	return consultar(raiz->dir, cod);
}

void altFB(struct tNo *raiz, int valorFB, int altura) {
	printf("-------------------------\n");
	printf("C�digo->%d\n", raiz->dado.codigo);
	printf("Descri��o->%s\n", raiz->dado.descricao);
	printf("Altura->%d\n", altura);
	printf("Fator de Balanceamento->%d\n", valorFB);
	printf("-------------------------\n");
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
	int resp;
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
		resp = excluir(&((*raiz)->esq), cod);
	resp = excluir(&((*raiz)->dir), cod);
	balancearAVL(raiz);
	return resp;
}

void representa(struct tNo *raiz) {
	if(raiz == NULL)
		return;
	printf("( %d", raiz->dado.codigo);
	representa(raiz->esq);
	representa(raiz->dir);
	printf(")");
}


void destruir (struct tNo *raiz) {
	if(raiz == NULL)
		return;
	destruir(raiz->esq);
	destruir(raiz->dir);
	free(raiz);
}
