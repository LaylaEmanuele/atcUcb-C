/* Algoritmo numeroMaior;
S�ntese
 Objetivo: Mostrar qual � o maior n�mero.
 Entrada : 3 n�meros quaisquer.
 Sa�da : O maior n�mero entre os tr�s.
*/
 #include <conio.h> //leitura e escrita 
 #include <stdio.h> //entrada e sa�da 
 #include <stdlib.h> //emulador
 #include <locale.h> //idiomas
 #include <math.h> //c�lculos
 
 main(){
    float n1, n2, n3;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o primeiro n�mero: \n");
    scanf("%f", &n1);
     printf("Digite o segundo n�mero: \n");
    scanf("%f", &n2);
     printf("Digite o terceiro n�mero: \n");
    scanf("%f", &n3);
     if ((n1>n2) && (n1>n3)){
         printf("O %.2f � o maior.", n1);
     }
     if ((n2>n1) && (n2>n3)){
         printf("O %.2f � o maior.", n2);
     }
    if ((n3>n2) && (n3>n1)){
        printf("O %.2f � o maior.", n3);
    }
    if ((n1==n2) && (n1==n3)){
        printf("Os n�meros %.2f s�o os maiores.", n1);
    }
	getch();
 }
