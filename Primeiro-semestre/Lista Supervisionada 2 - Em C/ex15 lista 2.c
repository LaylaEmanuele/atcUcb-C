/*Algoritmo contaDeInternet;
 S�ntese
 Objetivo: Ver quanto vai precisar pagar da conta.
 Entrada : Tempo de uso.
 Sa�da : Quanto voc� vai precisar pagar.
*/
 
 #include <conio.h> //leitura e escrita 
 #include <stdlib.h> //emulador
 #include <math.h> //c�lculos
 #include <stdio.h> //entra e sa�da
 #include <locale> //idioma
 
 main(){
 	setlocale(LC_ALL, "Portuguese");
 	float tempo, mais10;
 	printf(" Digite o tempo de uso: ");
 	scanf("%f", &tempo);
 	if(tempo <= 20){
 		printf("Valor = R$ 30,00");
	 }
	 if (tempo > 20){
	 	printf("O valor a ser pago � R$ %.f", (30+(tempo-20)*3));
	 }
	 getch();
 }
