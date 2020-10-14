/*S�ntese
	Objetivo: Realizar o somat�rio de 1 at� N por meio de uma fun��o recursiva.
	Data: 04/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int somar(int numero, int j, int soma){
	if(j>numero)
		return soma;
	
	soma+=j;
	j++;
	
	somar(numero,j,soma);
}

int main(void){
	int numero, j=1, soma=0;

	setlocale(LC_ALL,"Portuguese");
	
	printf("Digite o n�mero que deseja realizar a soma:\n");
	scanf("%d",&numero);	
	
	soma=somar(numero,j, soma);
	printf("O resultado da soma �: %d", soma);
	
	return 0;
}
