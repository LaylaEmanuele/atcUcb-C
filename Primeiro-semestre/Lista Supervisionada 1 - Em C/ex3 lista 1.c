/* Algoritmo: mediaDe3Num;
S�ntese
 Objetivo: Calcular a m�dia de tr�s n�meros quaisquer.
 Entrada: Os tr�s n�meros. 
 Sa�da: A m�dia.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas fun��es de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que voc� est� programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para fun��es matem�ticas b�sicas.

main ()
{
	float n1, n2, n3, media;
	setlocale(LC_ALL, "Portuguese");	
 	printf("Informe o primeiro n�mero: \n");
	scanf("%f",&n1);
	printf("Informe o segundo n�mero: \n");
	scanf("%f",&n2);
	printf("Informe o terceiro n�mero: \n");
	scanf("%f",&n3);
	media = (n1 + n2 + n3) / 3;
	system("cls");
	printf("A m�dia dos tr�s n�meros �: %.2f", media);
	getch();
}
