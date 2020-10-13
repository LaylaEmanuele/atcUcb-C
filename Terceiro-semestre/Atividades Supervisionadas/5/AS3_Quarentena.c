/*S�ntese
	Objetivo: "Lista de produtos feita atrav�s de uma LDE com descritor".
	Autora: Layla Emanuele.
	Data: 08/04/2020
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
	struct tNo *prev;
};

struct tDescritor{
	struct tNo *ini;
	struct tNo *fim; 
	int qtd;
};

//Prot�tipos das fun��es 
void inicializar(struct tDescritor *);	
int menu();
void incluir(struct tNo *, struct tDescritor *);
void listar(struct tDescritor );
struct tNo *consultar(int , struct tDescritor );
void alterar(struct tNo *, char []);
void excluir(struct tDescritor *, int );
void liberar(struct tDescritor *);

int main (void){
	int op, pesqCod;
	struct tNo *no, *consulta, *p;
	struct tDescritor lista;
	char novaD[50];
	setlocale(LC_ALL,"Portuguese"); 	

	inicializar(&lista);
	
	do{
		system("cls");
		
		printf("Quantidade de elementos na lista: %d\n", lista.qtd);
	
	
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
					printf("C�digo: %d\n", consulta->dado.codigo);
					printf("Descri��o: %s\n", consulta->dado.descricao);
				}
				getch();
			break;
			 	
			case 4:
				printf("Qual o c�digo a ser consultado?\n");
				scanf("%d", &pesqCod);
			
				consulta = consultar(pesqCod, lista); //retornando um ponteiro 
			
				if(consulta == NULL)
					printf("C�digo n�o encontrado!");
				else{
					printf("Descri��o: %s \n", consulta->dado.descricao);
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
				
				if(consulta == NULL){
					printf("C�digo n�o encontrado!");
					getch();
				}else
					excluir(&lista, pesqCod);		
		
				getch();
				
			break;
		}
	}while(op!=0);
	
	liberar(&lista);
	
	return 0;
}

void inicializar(struct tDescritor *list){	
	(*list).ini = (*list).fim = NULL;
	(*list).qtd = 0;
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

void incluir(struct tNo *novo, struct tDescritor *list){
	struct tNo *p = (*list).ini, *q;
	
	if(((*list).ini == NULL) || (novo->dado.codigo <= (*list).ini->dado.codigo)){ //lista vazia e inicio 
		if((*list).ini == NULL)//exclusivo de lista vazia 
			(*list).fim = novo;	
		else
			(*list).ini->prev = novo;
				
		novo->next = (*list).ini;
		(*list).ini = novo;	
		novo->prev = NULL;
	}
	else{ //meio e fim 
		if(novo->dado.codigo > (*list).fim->dado.codigo){ //fim 
			(*list).fim->next = novo;
			novo->prev = (*list).fim;
			novo->next = NULL;
			(*list).fim = novo;
		}
		else{
			while((p != NULL) && (p->dado.codigo <= novo->dado.codigo)){ //meio
				q = p;
				p = p->next; 
			}
			q->next = novo;
			novo->next = p;	
			novo->prev = q;	
		}
	}
	(*list).qtd++;
}

void listar(struct tDescritor list){
	struct tNo *p = list.ini;
	
	while(p!= NULL){
		printf("C�digo: %d\n", p->dado.codigo);
		printf("Descri��o: %s\n", p->dado.descricao);
		
		p = p->next;
	}
	getch();
}	

struct tNo *consultar(int pesq, struct tDescritor list){
	struct tNo *p = list.ini;
	
	while(p!= NULL){
		if(p->dado.codigo == pesq)
			return p;
		p = p->next;
	}
	
	return p;
}	
	
void alterar(struct tNo *consult, char novaD[]){
	strcpy(consult->dado.descricao, novaD);
}

void excluir(struct tDescritor *list, int pesq){
	struct tNo *p = (*list).ini, *q;
	
	if((*list).qtd == 1) //unico
		(*list).ini = (*list).fim = NULL; 
	else	
		if(p->dado.codigo == pesq ){ //inicio
			(*list).ini = p->next;	
			(*list).ini->prev = NULL;
	
		}
		else{ //meio e fim 
			p = (*list).ini;
			
			while(p->dado.codigo != pesq){
				q = p;
				p = p->next;
			}
			q->next = p->next;
			
			if(q->next == NULL)
				(*list).fim = q;
			else
				p->next->prev = q;	 
		}
	free(p);	
	(*list).qtd--;
}	

void liberar(struct tDescritor *list){
	struct tNo *p = (*list).ini, *q;
	
	while(p!=NULL){
		q = p;
		p = p->next;
		free(q);
	}
	inicializar(list);
}

