 /* Algoritmo: moduloNumero;
S�ntese
 Objetivo: Informar o m�dulo de um n�mero qualquer.
 Entrada: Um n�mero qualquer.
 Sa�da: O m�dulo do n�mero.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas fun��es de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que voc� est� programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para fun��es matem�ticas b�sicas.


main() 
{
	float n1;
	setlocale(LC_ALL, "Portuguese");	
	printf("Informe um n�mero qualquer: \n");
	scanf("%f", &n1);
	system("cls");
	if(n1 > 0) {
		printf("O m�dulo do n�mero �: %.2f", n1);
	}
	if(n1 < 0){
		n1=n1*-1;
		printf("Ent�o m�dulo do n�mero �: %.2f", n1);
	}
	getch();
}

