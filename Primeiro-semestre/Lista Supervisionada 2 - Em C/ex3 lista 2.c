 /* Algoritmo: ladoTriangulo;
S�ntese
 Objetivo:Verificar se os 3 n�meros podem ser o lado de um tri�ngulo.
 Entrada: 3 n�meros quaiquer.
 Sa�da: Se podem ser o n�o um tri�ngulo.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas fun��es de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que voc� est� programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para fun��es matem�ticas b�sicas.


main() 
{
	float n1,n2,n3;
	setlocale(LC_ALL, "Portuguese");	
	printf(" Digite o primeiro n�mero: \n");
	scanf("%f", &n1);
	printf(" Digite o segundo n�mero: \n");
	scanf("%f", &n2);
	printf(" Digite o terceiro n�mero: \n");
	scanf("%f", &n3);
	system("cls");
	if((n1<n2+n3) &&(n2<n1+n3 ) &&(n3<n2+n1)) {
		printf("O tri�ngulo pode ser formado.");
	}
	else{
		printf("O tri�ngulo n�o ser� formado.");
	}
	getch();
}

