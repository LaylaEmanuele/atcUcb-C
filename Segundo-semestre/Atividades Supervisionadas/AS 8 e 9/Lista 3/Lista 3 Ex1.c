/*S�ntese
	Objetivo: Realizar a soma de um vetor por meio de uma fun��o recursiva.
	Data: 04/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 20

int somar(int numeros[], int j, int soma){
	if(j==TAM)
		return soma;
	
	soma+=numeros[j];
	j++;
	
	somar(numeros,j,soma);
}


int main(void){
	int numeros[TAM], soma=0, i, j=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	
	for(i=0;i<TAM;i++){
		printf("Digite o %d� valor: ", i+1);
		scanf("%d", &numeros[i]);
	}
			
	soma=somar(numeros,j, soma);
	printf("O resultado da soma �: %d", soma);
	
	return 0;
}
