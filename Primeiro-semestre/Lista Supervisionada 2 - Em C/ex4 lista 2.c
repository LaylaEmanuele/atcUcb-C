 /* Algoritmo: nomeSexo;
S�ntese
 Objetivo: Ler o nome da pessoa e informar o sexo.
 Entrada: Nome e sexo.
 Sa�da:  Aparecer a seguinte mensagem: �Ilmo. Sr.� ou �Ilma. Sra.� e em seguida o nome da pessoa.
 */
 
#include <conio.h> //serve para que  possa usar em seus programas fun��es de leitura/escrita
#include <stdlib.h> //funciona como um emulador da prompt do sistema operacional que voc� est� programando
#include <stdio.h> // serve para entrada e saida 
#include <locale.h> // usada para acentos, locale, caracteres e etc.
#include <math.h> //usada para fun��es matem�ticas b�sicas.


main() 
{	char nome[500], sexo;
	setlocale(LC_ALL, "Portuguese");	
	printf(" Digite o seu nome: \n");
	gets(nome);
	printf(" Informe seu sexo(F/M): \n");
	sexo = getche();
	
	if(sexo>='a' && sexo <='z') {
	sexo=sexo-32;
	}
	
	system("cls");

	if( sexo =='F'){
		printf("\nIlma. Sra. %s", nome);
	}
	
	 if( sexo =='M'){
		printf("Ilmo. Sr. %s", nome);
	}
	getch();
}

