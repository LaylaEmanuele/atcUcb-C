/*Algoritmo tempoVida;
S�ntese
 Objetivo: Saber quanto tempo a pessoa j� viveu.
 Entrada : Ano de nascimento e ano atual.
 Sa�da : O nome da pessoa e n�mero de dias que ela viveu aproximadamente. 
*/

#include <conio.h> //leitura e escrita.
#include <stdio.h> //entrada e sa�da.
#include <stdlib.h> //emulador.
#include <math.h> //c�lculos.
#include <locale.h> //idioma. 

main(){
	int nascimento, atual, calculo1,calculo2, dias;
	char nome[50];
	setlocale(LC_ALL, "Portuguese");
	printf("Digite seu nome: \n");
	gets(nome);
	printf("Digite o ano do seu nascimento: ");
	scanf("%i", &nascimento);
	printf("Informe o ano atual: ");
	scanf("%i", &atual);
	calculo1 = atual - nascimento;
	calculo2 = calculo1 * 365;
	dias = calculo2;
	
	system("cls");
	printf("O tempo que voc� est� vivo em dias �: %i ", dias);
	getch();
}


