/*S�ntese
	Objetivo: Imprimir na tela em ordem crescente os n�mero de 0 at� N.
	Data: 05/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void mostrar(int num, int i){
	if(i>num)
		return;
		
	printf("%d ", i);
	mostrar(num,i+1);
}

int main (void){
	int numero, i=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Insira o n�mero desejado: ");
	scanf("%d",&numero);
	
	mostrar(numero, i);
	
	return 0;
}
