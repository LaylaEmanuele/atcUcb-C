/* Algoritmo  qualNumeroMenor;
S�ntese
 Objetivo: Encontrar o menor n�mero entre os n�meros informados.
 Entrada: Tr�s n�meros quais quer.
 Sa�da: Uma mensagem informando qual o menor n�mero.
*/

#include <math.h> //para c�lculos b�sicos
#include <conio.h> //leitura e escrita
#include <stdio.h> //entrada e sa�da
#include <stdlib.h> //emulador
#include <locale.h> //idioma

main (){
	setlocale(LC_ALL, "Portuguese");
	float n1, n2, n3;
	printf("Digite o primeiro n�mero: ");
	scanf("%f", &n1);
	printf("Digite o segundo n�mero: ");
	scanf("%f", &n2);
	printf("Digite o terceiro n�mero: ");
	scanf("%f", &n3);
	
	system("cls");
	
	if((n1 < n2) && (n1 < n3)){
		printf("O n�mero %.2f � o menor", n1);
	}
	if((n2 < n1) && (n2 < n3)){
		printf("O n�mero %.2f � o menor", n2);
	}
	if((n3 < n2) && (n3 < n1)){
		printf("O n�mero %.2f � o menor", n3);
	}
	getch();	
}
