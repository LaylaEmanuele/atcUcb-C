/*S�ntese
	Objetivo: Realiazar o c�lculo de uma potencia��o por meio de uma fun��o recursiva.
	Data: 04/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int potenciar(int k, int n, int j, int mult){
	
	if(j==n)
		return mult;
		
	mult=k*mult;
	j++;
	
	potenciar(k,n,j,mult);
}



int main(void){
	int k, n;	//base e expoente, respectivamente
	int multiplicacao=1, j=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Informe o n�mero que ser� a base de sua exponencia��o:\n");
	scanf("%d",&k);
	printf("Informe o n�mero que ser� a expoente de sua exponencia��o:\n");
	scanf("%d",&n);
	
	multiplicacao = potenciar(k,n,j,multiplicacao);
	printf("O resultado da potencia��o �: %d",multiplicacao);
	
	return 0;
}
