/*S�ntese
	Objetivo: Informar quantas vezes um d�gito aparece em um n�.
	Data: 04/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int pesquisar(int num, int pesq, int ocorre){
	
	if(num==0)
		return ocorre;
	if(num%10==pesq)
		ocorre++;
	num=num/10;	
	pesquisar(num, pesq, ocorre); 
}

int main(void){
	int numero, pesquisa, ocorrencias=0; //refere-se ao n� digitado e ao n� a ser pesquisado, respectivamente 

	setlocale(LC_ALL,"Portuguese");

	printf("Digite o n�mero:\n");
	scanf("%d",&numero);
	printf("Insira o n�mero a ser pesquisado dentro do n�mero j� informado:\n");
	scanf("%d",&pesquisa);
	
	ocorrencias=pesquisar(numero, pesquisa, ocorrencias);	
	printf("O n�mero de ocorr�ncias do n�mero a ser pesquisado foi: %d", ocorrencias);
	
	return 0;
}
