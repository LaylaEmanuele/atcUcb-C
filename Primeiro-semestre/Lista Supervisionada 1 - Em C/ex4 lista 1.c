/* Algoritmo: resto_quociente;
S�ntese
 Objetivo: Fazer a leitura do resto e do quociente.
 Entrada: Os dois n�meros que ser�o usados para realizar a divis�o.
 Sa�da: O resto e quociente.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas fun��es de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que voc� est� programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para fun��es matem�ticas b�sicas.

main ()
{
	int  n1, n2, resto, quociente;
	setlocale(LC_ALL, "Portuguese");	
 	printf("Informe o primeiro n�mero: \n");
	scanf("%i",&n1);
	printf("Informe o segundo n�mero: \n");
	scanf("%i",&n2);
	resto = n1 % n2;
	quociente = n1 / n2;
	system("cls");
	printf("O resto �: %i", resto);
	printf("\nO quociente �: %i", quociente);
	getch();
}

