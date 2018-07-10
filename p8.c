//Marcos Vinicius Souza Rodrigues 
//11711ECP008

#include <stdio.h>
#include <stdlib.h>

void gera_numeros(float * vetor, int tamanho) 
{
    int i;
    float numero;
    for(i = 0; i < tamanho; i++)
      vetor[i] = (float) rand()/(float) RAND_MAX + 0.5f;
            
}

float somatorio(float *inicio_vet, float *fim_vet)
{
	float x;
	x = *inicio_vet;
	 
	

	if(inicio_vet != fim_vet)
	{
		return( x + somatorio(inicio_vet + 1, fim_vet));
		
    }
	else
	return (x);
	
}
float produtorio(float *inicio_vet, float *fim_vet)
{
	float x;
	x = *inicio_vet;
	 


	if(inicio_vet != fim_vet)
	{
		return( x * somatorio(inicio_vet + 1, fim_vet));
		
    }
	else
	return (x);
	
}

int main ()
{
	srand(123456);
	int opc;
	float vet[100], soma = 0, prod = 0;
	
	gera_numeros(vet, 100); 
	printf("%f\n", vet[0]);
	
    printf("\t\t##MENU PRINCIPAL##\n");
	printf("\tSelecione a opcao desejada: \n\n");
	printf("\t[1]- Somatorio \n");
	printf("\t[2]- Produtorio \n");
	scanf("%d", &opc);
	getchar();
	
	switch (opc)
	{
		case 1:
		   	soma = somatorio(vet, vet + 99);
		   	printf("%f\n", soma);
		break;
		case 2:
		    prod = produtorio(vet, vet + 99);
		   	printf("%f\n", prod);
		break;
	}

	
	return 0;
}
