/*S�ntese:
   Objetivo: Criar uma lista(modularizada) de livros com seus dados (struct[codigo, valor, nome]) podendo se fazer: altera��o da lista, deletar os dados inseridos, backup, restau��o, ordena��o e pesquisa bin�ria.
   Data: 07/10/2019
   Autora: Layla Emanuele.
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM 10

struct tLivros{						//declara��o do tipo de vari�vel
	char nome[50];
	int ano;
	float valor;
};

int menu(){
	int opcaoE;
	
	printf("----------MENU---------\n");
	printf("1- Adicionar um novo livro\n");
	printf("0- Para sair\n");
	scanf("%d",&opcaoE);
	
	return opcaoE;
}

int adicionar(int flag, struct tLivros livros[], int *qtd){
	int armazenaQtd=0;
	armazenaQtd=*qtd;
	
	printf("Insira o nome do livro:\n");
	fflush(stdin);
	gets(livros[*qtd].nome); 
	*qtd++;
	
	if(*qtd!=armazenaQtd)
		flag=1;
	
	return flag;
}


int main(){
	struct tLivros livros[TAM];
	int opcao, flag=0, adiciona, qtd=0;
	
	do{
		opcao = menu();
		
		system("cls");
		
		switch(opcao){
			
			case 1:
				opcao == '1';
				adiciona=adicionar(flag, livros, &qtd);
				if(flag!=0)
					printf("Os dados do novo livro foram armazenados");
			
			
		}
			
		
	}while(opcao!=0);
	
	
	
	
	return 0;
}






