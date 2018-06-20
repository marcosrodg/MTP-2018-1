//Marcos Vinicius Souza Rodrigues
//11711ECP008
#include <stdio.h>
#define J 20
int soma(int*, int);
float med(float, float);
int main()
{
	int vetor[J], qnt, som, *p;
	p = (int*)vetor;
	 
	for(int i = 0; i < J; i++)
		vetor[i] = 0;
		
	printf("Informe a quantidade de numeros do vetor (de 5 a 20): "); 
	scanf("%d", &qnt);
	getchar();
	 
	printf("Preencha com os numeros desejados: \n");	
	for(int i = 0; i < qnt; i++)
	 {
	 	printf("vetor[%d]: ", i + 1);
	   	scanf("%d", &vetor[i]);
	    getchar();
	 } 
	som = soma(p, qnt);
	float somatorio = som, tamanho = qnt;
	printf("Media: %.1f", med(somatorio, tamanho)); 
	return 0;
}
int soma (int *vetor, int qnt)
{
	int aux = 0;
	for(int i = 0; i < qnt; i++) aux += vetor[i];
	return aux;
}

float med(float som, float qnt)
 {
   return som/qnt;
 }
