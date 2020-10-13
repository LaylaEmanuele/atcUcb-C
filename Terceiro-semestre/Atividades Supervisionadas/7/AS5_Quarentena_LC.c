/*S�ntese
	Objetivo: "Lista de produtos feita atrav�s de uma Lista Circular, ordenada de forma n�o decrescente".
	Autora: Layla Emanuele.
	Data: 22/04/2020
*/	

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//Declara��es de tipos de vari�veis 

struct tProduto{
	int codigo;
	char descricao[50];
};

struct tNo{
	struct tProduto dado;
	struct tNo *next;
};

//Prot�tipos das fun��es 
void inicializar(struct tNo **); 
int menu();
void incluir(struct tNo *, struct tNo **);
void listar(struct tNo *);
struct tNo *consultar(int , struct tNo *);
struct tNo *comparaD(struct tNo *, char [], int );
void alterar(struct tNo *, char []);
int excluir(struct tNo **, int , struct tNo *);
void liberar(struct tNo **);

int main (void){
	int op, pesqCod;
	struct tNo *no, *lista=NULL, *consulta, *p;
	char novaD[50], descricao[50], word[40];
	setlocale(LC_ALL,"Portuguese"); 	
	
	inicializar(&lista);
	
	do{
		system("cls");
		
		op = menu();
		
		system("cls");
		
		switch(op){
			case 1:
				no = malloc(sizeof(struct tNo));
				
				printf("*******Inclus�o*******\n");
				
				printf("Qual o c�digo do produto?\n");
				scanf("%d", &(no->dado.codigo));
			
				printf("Qual a descri��o do produto?\n");
				fflush(stdin);
				gets(no->dado.descricao);
				
				incluir(no, &lista);
			break;
				
			case 2:
				listar(lista);
			break;
					
			case 3:
				printf("Qual o c�digo a ser consultado?\n");
				scanf("%d", &pesqCod);
				
				consulta = consultar(pesqCod, lista); //retornando um ponteiro 
				
				if(consulta == NULL)
					printf("C�digo n�o encontrado!");
				else{
					strcpy(word, consulta->dado.descricao);
					do{
						printf("Descri��o: %s\n", consulta->dado.descricao);
						consulta = consulta->next;					
					}while((consulta != NULL) && (consulta->dado.codigo == pesqCod) && ((strcmp(consulta->dado.descricao, word)) != 0));
				}
				getch();
			break;
			 	
			case 4:
				printf("Qual o c�digo a ser consultado?\n");
				scanf("%d", &pesqCod);
			
				consulta = consultar(pesqCod, lista); //retornando um ponteiro 
				p = consulta;
				if(consulta == NULL)
					printf("C�digo n�o encontrado!");
				else{
					strcpy(word, consulta->dado.descricao);
					do{
						printf("Descri��o: %s\n", consulta->dado.descricao);
						consulta = consulta->next;					
					}while((consulta != NULL) && (consulta->dado.codigo == pesqCod) && ((strcmp(consulta->dado.descricao, word)) != 0));
				
					printf("Informe qual descri��o ser� alterada:\n");
					fflush(stdin);
					gets(descricao);
					
					consulta = comparaD(p, descricao, pesqCod);
					
					printf("Qual a nova descri��o?\n");
					fflush(stdin);
					gets(novaD);
				 	alterar(consulta, novaD);
				
			    	printf("Descri��o do produto alterado com sucesso!");
				}
				getch();
				
			break;	
			
			case 5: 
				printf("Qual c�digo ser� exclu�do?\n");
				scanf("%d", &pesqCod);
				consulta = consultar(pesqCod, lista); //retornando um ponteiro 
				p = consulta;
				
				if(consulta == NULL)
					printf("C�digo n�o encontrado!");
				else{
					strcpy(word, consulta->dado.descricao);
					do{
						printf("Descri��o: %s\n", consulta->dado.descricao);
						consulta = consulta->next;					
					}while((consulta != NULL) && (consulta->dado.codigo == pesqCod) && ((strcmp(consulta->dado.descricao, word)) != 0));
				
					printf("Informe qual descri��o ser� exclu�da:\n");
					fflush(stdin);
					gets(descricao);
					
					consulta = comparaD(p, descricao, pesqCod);
					if(consulta == NULL )
						printf("Descri��o incompat�vel!!");
					else
						excluir(&lista, pesqCod, consulta);	
				}
				getch();	
		
			break;
		}
	}while(op!=0);
	
	liberar(&lista);
	
	return 0;
}

void inicializar(struct tNo **list){	
	(*list) = NULL;
}

int menu(){
	int op;
	
	printf("*********MENU*********\n");
	printf("1 - Inclus�o\n");
	printf("2 - Listagem\n");
	printf("3 - Consulta\n");
	printf("4 - Altera��o\n");
	printf("5 - Exclus�o\n");
	printf("0 - Sair\n");
	printf("Op��o desejada:\n");
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

void listar(struct tNo *list){
	struct tNo *p = list;
	
	if(p == NULL)
		return;
	do{
		p = p->next;
		printf("C�digo: %d\n", p->dado.codigo);
		printf("Descri��o: %s\n", p->dado.descricao);
	}while(p != list); 
	 
	getch();
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
	
struct tNo *comparaD(struct tNo *p, char descricao[], int pesq){
	while((p != NULL) && (p->dado.codigo == pesq)){
		if((strcmp(p->dado.descricao, descricao)) == 0)
			return p;
		p = p->next;
	}	
	return NULL;
}	

void alterar(struct tNo *consult, char novaD[]){
	strcpy(consult->dado.descricao, novaD);
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

void liberar(struct tNo **list){
	struct tNo *p = *list, *q;
	
	if(p!= NULL){
		q = p; 
		p = p->next;
		q->next = NULL;
	}
	
	while(p!=NULL){
		q = p;
		p = p->next;
		free(q);
	}
}
