/* Algoritmo parOuImpar;
S�ntese
 Objetivo: Determinar se um n�mero inteiro � par ou �mpar.
 Entrada: Um n�mero qualquer.
 Sa�da: Se o n�mero � par ou �mpar.	
*/

#include <conio.h> //possibilita fazer a leitura a escrita
#include <math.h> //fazer c�lculos
#include <stdlib.h> //emulador para o sistema operacional 
#include <stdio.h> //entrada e sa�da
#include <locale.h> //para idiomas 

main()
 {
	int n1, parImpar;
	setlocale(LC_ALL ,"Portuguese");
	printf("Informe o n�mero: ");
	scanf("%i", &n1);
	parImpar = n1 % 2;
	
	system("cls");
	if(parImpar == 0){
		printf("O n�mero informado � par!");
	}
	else {
		printf("O n�mero informado � �mpar!");
	}
	getch();
}

