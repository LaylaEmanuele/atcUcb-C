/*Algoritmo tipoTriangulo;
S�ntese
 Objetivo: Verificar o tipo de tri�ngulo formado de acordo com a medida do seus lados.
 Entrada : 3 n�meros quaiquer.
 Sa�da : Qual tipo de tri�ngulo formado. 
*/
#include <locale.h> //idiomas 
#include <math.h> //c�lculos
#include <conio.h> //leitura e escrita
#include <stdio.h> //entrada e sa�da
#include <stdlib.h> //emulador 
main(){
	float n1, n2, n3;
	setlocale(LC_ALL, "Portuguese");
	printf("Digite o primeiro n�mero: \n");
	scanf("%f", &n1);
	printf("Digite o segundo n�mero: \n");
	scanf("%f", &n2);	
	printf("Digite o terceiro n�mero: \n");
	scanf("%f", &n3);	
	
	if(n1<(n2+n3) && n2<(n1+n3) && n3<(n2+n1)) {
        printf("O tri�ngulo poder� ser formado.");
        	if((n1==n2) && (n2==n3 ) && (n3==n1 )) {
       	     printf("O tri�ngulo formado � equil�tero.");
        	} 
				else if ((n1==n2) && (n2!=n3 ) && (n3!=n1 )) {
					printf("O tri�ngulo formado � is�sceles.");
        		}		 
					else if((n1!=n2) && (n2!=n3 ) && (n3!=n1 )) {
        			    printf("O tri�ngulo formado � escaleno");
        			}	 
}
    else
    printf("O tri�ngulo n�o ser� formado");
    getch();
}
