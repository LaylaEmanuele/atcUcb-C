/*S�ntese
	Objetivo: Imprimir na tela em ordem decrescente os n�mero de 0 at� N.
	Data: 05/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void mostrar(int i){
	if(i<0)
		return;
		
	printf("%d ", i);
	mostrar(i-1);
}

int main (void){
	int numero, i;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Insira o n�mero desejado: ");
	scanf("%d",&numero);
	i=numero;
	
	mostrar(i);
	
	return 0;
}
