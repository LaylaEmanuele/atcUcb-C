/*S�ntese
	Objetivo: Realizar uma multiplica��o utilizando somente soma e fun��o recursiva.
	Data: 05/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int multiplicar(int mult1, int mult2, int qtdS){
	if(qtdS==mult2)
		return 0;
	else
		return mult1+multiplicar(mult1, mult2, qtdS+1);
	
}

int main (void){
	int multiplicando, multiplicador, qtdS=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Qual o multiplicando?\n");
	scanf("%d",&multiplicando);
	
	printf("Qual o multiplicador?\n");
	scanf("%d",&multiplicador);
	
	printf("O produto �: %d", multiplicar(multiplicando, multiplicador, qtdS));
	
	return 0;
}
