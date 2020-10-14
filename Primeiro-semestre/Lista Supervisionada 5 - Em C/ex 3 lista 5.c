/* ALgoritmo operacaoAritmetica;
S�ntese:
  Objetivo: Realizar o c�lculo de duas opera��es matem�ticas.
  Entrada: Tr�s n�meros quaisquer.
  Sa�da: Resultado da opera��o e se o mesmo � maior, menor ou igual a zero.
*/

#include <conio.h> //leitura e escrita.
#include <stdlib.h> //emulador.
#include <stdio.h> //entrada e sa�da.
#include <math.h> //c�lculos. 
#include <locale> //idiomas.

void verificaResultado(float r);
float calc(char resposta1, char resposta2, float n1, float n2, float n3);

main(){
	float n1, n2, n3, r;
	char resposta1, resposta2;
	setlocale(LC_ALL, "Portuguese");
	printf("Informe o primeiro n�mero desejado: ");
	scanf("%f", &n1);
	printf("Informe o segundo n�mero desejado: ");
	scanf("%f", &n2);	
	printf("Informe o terceiro n�mero desejado: ");
	scanf("%f", &n3);	
	printf("Escolha o primeiro operador para realizar a opera��o metem�tica.Sendo + para adi��o, - para subtra��o, / para divis�o e * para multiplica��o :\n");
	resposta1 = getche ();
	printf("\nEscolha o segundo operador para realizar a opera��o metem�tica.Sendo + para adi��o, - para subtra��o, / para divis�o e * para multiplica��o: \n");
	resposta2 = getche ();
	r = calc(resposta1, resposta2, n1, n2, n3);
	system("cls");
	printf("\nA resposta da opera��o matem�tica �: %.2f", r);
	verificaResultado(r);
}

float calc(char resposta1, char resposta2, float n1, float n2, float n3){
	
	float calc2;
	if(resposta1 == '+' && resposta2 == '+'){
		calc2 = n1 + n2 + n3;		
	}
	else if (resposta1 == '+' && resposta2 == '-'){
		calc2 = n1 + n2 - n3;
	}
	else if (resposta1 == '+' && resposta2 == '*'){
		calc2 = n1 + (n2 * n3);
	}
	else if(resposta1 == '+' && resposta2 == '/'){
		calc2 = n1 + (n2 / n3);
	}
	else if (resposta1 == '-' && resposta2 == '-'){
		calc2 = n1 - n2 - n3;
	}
	else if (resposta1 == '-' && resposta2 == '+'){
		calc2 = n1 - n2 + n3;
	}
	else if (resposta1 == '-' && resposta2 == '*'){
		calc2 = n1 - (n2 * n3);
	}
	else if (resposta1 == '-' && resposta2 == '/'){
		calc2 = n1 - (n2 / n3);
	}
	if(resposta1 == '*' && resposta2 == '-') {
		calc2 = (n1 * n2) - n3;
	}
	else if (resposta1 == '*' && resposta2 == '+'){
		calc2 = (n1 * n2) + n3;
	} 
	else if (resposta1 == '*' && resposta2 == '-'){
		calc2 = n1 * n2 * n3;
	}
	else if (resposta1 == '*' && resposta2 == '/'){
		calc2 = n1 * n2 / n3;

	}
	else if (resposta1 == '/' && resposta2 == '-'){
		calc2 = (n1 / n2) - n3;
	}
	else if (resposta1 == '/' && resposta2 == '+'){
		calc2 = (n1 / n2) + n3;
	}
	else if(resposta1 == '/' && resposta2 == '*') {
		calc2 = n1 / n2 * n3;
	}
	else if (resposta1 == '/' && resposta2 == '/'){
		calc2 = n1 / n2 / n3;

	}
	return calc2;
}

void verificaResultado(float r){
	if(r > 0){
		printf("\nO resultado � maior. ");
	}
	else if (r < 0){
		printf("\nO resultado � menor. ");
	}
	else if(r == 0){
		printf("\nO resultado � igual a zero.");
	}
}
 
