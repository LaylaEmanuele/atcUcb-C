/* Algoritmo DDD;
S�ntese 
 Objetivo: Informar de qual regi�o � o DDD.
 Entrada: O n�mero de telefone.
 Sa�da: Qual lugar � o DDD.
*/

#include <conio.h> //leitura e escrita
#include <stdio.h> //entrada e saida
#include <stdlib.h> //emulador
#include <math.h> //c�lculos
#include <locale.h> //idiomas

main(){
	setlocale(LC_ALL, "Portuguese");
	int ddd, telefone;
	printf("Informe seu DDD: ");
	scanf("%i", &ddd);
	printf("Informe seu n�mero de telefone: ");
	scanf("%i", &telefone);
	
	system("cls");
	
	if(ddd == 61){
		printf("O DDD � de Bras�lia.");
	}
	if(ddd == 71){
		printf("O DDD � de Salvador.");
	}
	if(ddd == 11){
		printf("O DDD � de S�o Paulo.");
	}
	if(ddd == 21){
		printf("O DDD � de Rio de Janeiro.");
	}
	if(ddd == 32){
		printf("O DDD � de Juiz de Fora.");
	}
	if(ddd == 19){
		printf("O DDD � de Campinas.");
	}
	if(ddd == 27){
		printf("O DDD � de Campinas.");
	}
	if(ddd == 31){
		printf("O DDD � de Belo Horizonte");
	}
	getch();
}


