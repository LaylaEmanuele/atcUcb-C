/* Algoritmo: levarMulta
S�ntese
 Objetivo: Informar se ao motorista se ele se multado ou n�o.
 Entrada: Velocidade e plava do carro.
 Sa�da: Se foi multado ou n�o.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas fun��es de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que voc� est� programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para fun��es matem�ticas b�sicas.


main() 
{
	float velocidadeCarro;
	char placadoCarro[7];
	setlocale(LC_ALL, "Portuguese");	
	printf("Informe a placa do carro: \n");
	gets(placadoCarro);
	printf("Informe a velocidade do carro: \n");
	scanf("%f",&velocidadeCarro);

	system("cls");
	if(velocidadeCarro >= 80) {
		printf("O carro %s ser� multado!", placadoCarro);
	}
	else{
		printf("O carro %s n�o vai ser multado!", placadoCarro);
	}
	getch();
}

