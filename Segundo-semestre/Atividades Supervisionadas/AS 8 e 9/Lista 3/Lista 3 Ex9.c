/*S�ntese
	Objetivo: Encontrar o valor de N-�simo termo de um tetranacci.
	Data: 05/09/2019
	Autores: Gabriel Raposo e Layla Emanuele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int tetranacciar(int n, int i, int termos[]){
	
	if(i==n)
		return termos[i-1];
	termos[i]=termos[i-4]+termos[i-3]+termos[i-2]+termos[i-1];
	
	tetranacciar(n,i+1,termos);
}

int main (void){
	int numero, i=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Digite o N-�simo termo que voc� deseja encontrar: ");
	scanf("%d",&numero);
	
	if(numero<3)
		printf("O N-�simo termo que voc� deseja encontrar � o: 0.");
	else
		if(numero==3)
			printf("O N-�simo termo que voc� deseja encontrar � o: 1.");	
	else{
		int termos[numero];
		termos[0]=0;
		termos[1]=0;
		termos[2]=0;
		termos[3]=1;
		i=4;
		printf("O %d-�simo termo que voc� deseja encontrar � o: %d", numero, tetranacciar(numero,i,termos));
	}
	return 0;
}
