/* Algoritmo: rolos;
S�ntese
 Objetivo: Auxiliar um construtor a descobrir a quantidade de rolos e a quantidade de metros avulsos de fios que ele precisa adquirir.
 Entrada: Quantidade de metros.
 Sa�da: Quantidade de rolos e o que sobra.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas fun��es de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que voc� est� programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para fun��es matem�ticas b�sicas.

main ()
{
	int  tamanhoDoRolo, quantoRolo, restoRolo;
	setlocale(LC_ALL, "Portuguese");	
 	printf("Digite a quantidade de metros:\n");
	scanf("%i",&tamanhoDoRolo);
	quantoRolo = tamanhoDoRolo / 50;
	restoRolo = tamanhoDoRolo % 50;
	system("cls");
	printf("Quantidade de rolos �:  %i", quantoRolo);
	printf("\nRestar�: %i metros de rolo", restoRolo);
	getch();
}
