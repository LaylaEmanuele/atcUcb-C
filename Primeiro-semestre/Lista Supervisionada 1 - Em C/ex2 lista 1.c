/* Algoritmo: areaCirculo
S�ntese
 Objetivo: Calcular a area do c�rculo.
 Entrada: O raio. 
 Sa�da: A �rea do c�rculo.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas fun��es de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que voc� est� programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para fun��es matem�ticas b�sicas.

main ()
{
	float raio, area, expoente;
	expoente = 2;
	setlocale(LC_ALL, "Portuguese");	
 	printf("Informe o valor do raio: \n");
	scanf("%f",&raio);
	area = 3.14 * pow(raio, expoente);	
	system("cls");
	printf("A �rea do c�rculo �: %.2f", area);
	getch();
}
