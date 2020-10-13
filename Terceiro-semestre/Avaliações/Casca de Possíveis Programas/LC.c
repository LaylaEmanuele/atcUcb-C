/*S�ntese:
	Objetivo:
	Autora: Layla Emanuele
	Data: 17/06/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Tipos de vari�veis
struct tLista {
	int
	char
};

struct tNo {
	struct tLista dado;
	struct tNo *prox;
};

//Prot�tipos das Fun��es
void inicializar(struct tNo **lst);
int menu();
void incluir(struct tNo **lst, struct tNo *novo);

//Principal
int main() {
	setlocale(LC_ALL, "Portuguese");
	struct tNo *lista, *no;
	int opcao

	inicializar(&lista);

	do {
		system("cls");
		opcao = menu();
		system("cls");

		switch(opcao) {
			case 1:
				printf("----Inclus�o----");
				no = malloc(sizeof(struct tNo));
				printf("Qual.....?");
				scanf("%d", & no->);
				incluir(&lista,no);

				break;

			case 2:
				printf("----Listagem----");
				break;

			case 3:
				printf("----Consulta----");
				break;

			case 4:
				printf("----Altera��o----");
				break;

			case 5:
				printf("----Exclus�o----");
				break;
		}

	} while(opcao != 0);




	return 0;
}

void inicializar(struct tNo **lst) {
	(*lst) = NULL;
}

int menu() {
	int op;

	printf("----MENU----\n");
	printf("1. Inclus�o\n");
	printf("2. Listagem\n");
	printf("3. Consulta\n");
	printf("4. Altera��o\n");
	printf("5. Exclus�o\n");
	printf("0. Sair\n");

	scanf("%d", &op);

	return op;
}

void incluir(struct tNo *novo, struct tNo **list){
	struct tNo *p, *q = *list;
	
	if((*list) == NULL){ // lista vazia 
		novo->next = novo;
		(*list) = novo;
	}
	else{ //meio 
		p = q->next;
		
		while((novo->dado.codigo < (*list)->dado.codigo) && (p->dado.codigo <= novo->dado.codigo)){
			q = p;
			p = p->next; 
		}
		q->next = novo;
		novo->next = p;		
		
		if(novo->dado.codigo > (*list)->dado.codigo)
			(*list) = novo;
	}
}


int excluir(struct tNo **list, int pesq, struct tNo *consult){
	struct tNo *p = *list;
	
	if(p == consult){ //�nico
		*list = NULL;	
	}
	else{ //meio 
		while(p->next != consult)
			p = p->next;
		p->next = consult->next;	
		if((*list) == consult)
			(*list) = p; 
	}
	free(consult);
	return 0;
}

struct tNo *consultar(struct tNo *lst, int codigo) {
	struct tNo *p = lst;
	while (p != NULL) {
		if (p->dado.codigo == codigo)
			return p;
		p = p->prox;
	}
	return NULL;
}

struct tNo *consultar(int pesq, struct tNo *list){
	struct tNo *p = list;
	
	if(p == NULL)
		return;
	do{
		p = p->next;
		
		if(p->dado.codigo == pesq)
			return p;
			
	}while(p != list); 

	return NULL;
}
