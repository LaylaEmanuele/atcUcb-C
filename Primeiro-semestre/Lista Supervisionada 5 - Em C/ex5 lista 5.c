/* Algoritmo potenciacao;
 S�ntese
 Objetivo: Fazer o c�lculo de potencia��o por meio de um sub-algoritmo utilizando procedimento.
 Entrada : O expoente e a base.
 Sa�da : O resultado do c�lculo.
*/

#include <conio.h> //leitura e escrita.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void exponencial ( float base, int expoente);

main(){
	setlocale(LC_ALL,"Portuguese");
	float base;
	int expoente;
 	printf("Informe a base do expoente: ");
	scanf("%f", &base);
	printf("Informe o expoente que � o n�mero que elevar� a base: ");
	scanf("%i", &expoente);
	exponencial(base, expoente);
	getch();
}

void exponencial ( float base, int expoente){

	float rp;
	int i;
	rp=1;

	for( i = 0; i<expoente; i++){
	
	rp=rp*base;
	}
	system("cls");
	printf("O resultado do c�lculo �: %.2f", rp);	
}
