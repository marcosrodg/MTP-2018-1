#include <stdio.h>


int main()
{	
	char numero[256], cont[256]={48};
	int i= 0,j = 0;
	
	printf("Digite a sequencia a ser convertida :");
	scanf("%s",&numero);
	
	while(numero[i] != '\0')
	{
		if(numero[i] <= '9')
		{
			if( numero[i] >= '0')
			{
				cont[j] = numero[i];
				j++;
			}
		}
		i++;
	}
	printf("%s",cont);
	
	return 0;
}
