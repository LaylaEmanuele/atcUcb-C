/* Algoritmo diferancaNumero;
S�ntese 
 Objetivo:  Apresentar a diferen�a do maior pelo menor.
 Entrada: Os dois n�meros quaisquer.
 Sa�da: Uma mensagem apresentando a diferen�a deles.
*/

#include <math.h> //c�lculos
#include <conio.h> //leitura e escrita 
#include <stdlib.h> //emulador 
#include <stdio.h> //entrada e sa�da
#include <locale.h> //idiomas 

main(){
	setlocale(LC_ALL, "Portuguese");
	float n1, n2;
	printf("Digite o primeiro n�mero: ");
	scanf("%f", &n1);
	printf("Digite o segundo n�mero: ");
	scanf("%f", &n2);
	
	system ("cls");
	if(n1 > n2){
		printf("A diferen�a �: %.2f ", n1-n2);
	}
	if(n1 < n2){
		printf("A diferen�a �: %.2f", n2-n1);
	}
	getch();
}

