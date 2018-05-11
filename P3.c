//Marcos Vinicius Souza Rodrigues
//11711ECP008

#include <stdio.h>

int decimal1;
int decimal2;
int bin1[32] = {0};
int bin2[32] = {0};
int resultado[32] = {0};
int nb;
int arrastar;

void dec2bin1(int decimal)
{
	int i, resultado = 0;
    
    resultado=decimal;
    if(decimal<0)
    {
	    resultado=-resultado;
	    
		for(i=0;resultado!=0;i++)
		{
	        bin1[i]=resultado%2;
	        resultado=(resultado - bin1[i])/2;
	    }
	    
	    for(i=0;i<32;i++)
	    	bin1[i]=!bin1[i];
    	
    	for(i=31;i!=0;i--)
    	{
    		if(bin1[i]==0)
    		{
    			bin1[i]=1;
    			break;
			}
			else
			bin1[i]=0;
		}
		
		for(i=0;i<32;i++)
	    	bin1[i]=!bin1[i];
	}
	if(decimal>=0)
	{
		for(i=0;resultado!=0;i++)
		{
	        bin1[i]=resultado%2;
	        resultado=(resultado - bin1[i])/2;
	    }
	}
}

void dec2bin2(int decimal)
{
	int i, resultado = 0;
    
    resultado=decimal;
    if(decimal<0)
    {
	    resultado=-resultado;
	    
		for(i=0;resultado!=0;i++)
		{
	        bin2[i]=resultado%2;
	        resultado=(resultado - bin2[i])/2;
	    }
	    
	    for(i=0;i<32;i++)
	    	bin2[i]=!bin2[i];
    	
    	for(i=31;i!=0;i--)
    	{
    		if(bin2[i]==0)
    		{
    			bin2[i]=1;
    			break;
			}
			else
			bin2[i]=0;
		}
		
		for(i=0;i<32;i++)
	    	bin2[i]=!bin2[i];
	}
	if(decimal>=0)
	{
		for(i=0;resultado!=0;i++)
		{
	        bin2[i]=resultado%2;
	        resultado=(resultado - bin2[i])/2;
	    }
	}
}

void NOT()
{
	int i = 0, aux=0;
	
	printf("NOT %d (", decimal1);
	for(i = 31; i >= 0; i--)
		printf("%d", bin1[i]);
	
	printf(") : ");
	
	for(i = 0; i < 32; i++)
	{
		if(bin1[i] == 1)
			bin1[i]= 0;
		else
			bin1[i] = 1;
	}

	printf("%d (",~decimal1);

	for(i = 31; i >= 0; i--)
		printf("%d", bin1[i]);
		
	printf(")");
}

void AND()
{
	int i = 0, aux = 0;
	
	printf("%d (", decimal1);
	for(i = 31; i >= 0; i--)
		printf("%d", bin1[i]);
		
	printf(") AND ");
	printf("%d (", decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", bin2[i]);
		
	printf(") : ");
	
	for(i = 0; i < 32; i++)
	{
		if(bin1[i] == 1 && bin2[i] == 1)
			resultado[i] = 1;
		else 
			resultado[i] = 0;
	}
	
	printf("%d (",decimal1&decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", resultado[i]);
	
	printf(")");
}

void OR()
{
	int i = 0, aux = 0;
	
	printf("%d (", decimal1);
	
	for(i = 31; i >= 0; i--)
		printf("%d", bin1[i]);
			
	printf(") OR ");
	printf("%d (", decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", bin2[i]);
	
	printf(") : ");
	
	for(i = 0; i < 32; i++)
	{
		if(bin1[i] == 0 && bin2[i] == 0)
			resultado[i] = 0;
		else 
			resultado[i] = 1;
	}

	printf("%d (",decimal1|decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", resultado[i]);
	
	printf(")");
}

void XOR()
{
	int i = 0, aux = 0;
	
	printf("%d (", decimal1);
	for(i = 31; i >= 0; i--)
		printf("%d", bin1[i]);
	
	printf(") XOR ");
	printf("%d (", decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", bin2[i]);
	
	printf(") : ");
	
	for(i = 0; i < 32; i++)
	{
		if(bin1[i] == bin2[i])
			resultado[i] = 0;
		else 
			resultado[i] = 1;
	}
	
	printf("%d (",decimal1^decimal2);
	
	for(i = 31; i >= 0; i--)
		printf("%d", resultado[i]);
	
	printf(")");	
}

void RIGHTSHIFT(int arrastar)
{
	int i = 0, j = 0, aux = 0;
	
	printf("%d (", decimal1);
	
	for(i = 31; i >= 0; i--)
		printf("%d", bin1[i]);
			
	printf(") >> ");
	printf("%d (", arrastar);
	
	for(i = 31; i >= 0; i--)
		printf("%d", bin2[i]);
	
	printf(") : ");
	
	for(i = 0; i < arrastar; i++)
		resultado[i] = 0;
		
	for(i = arrastar; i < 32; i++)
	{
		resultado[i] = bin1[j];
		j++;
	}
	
	printf("%d (",decimal1>>arrastar);
	
	for(i = 31; i >= 0; i--)
		printf("%d", resultado[i]);
	
	printf(")");
}

void LEFTSHIFT(int arrastar)
{
	int i = 0, j = 0, aux = 0;
	
	printf("%d (", decimal1);
	for(i = 31; i >= 0; i--)
		printf("%d", bin1[i]);
	
	printf(") << ");
	printf("%d (", arrastar);
	for(i = 31; i >= 0; i--)
		printf("%d", bin2[i]);
	
	printf(") : ");
	
	for(i = arrastar; i < 32; i++)
	{
		resultado[i] = bin1[j];
		j++;
	}
	
	for(; j < 32; j++)
		resultado[j] = 0;
	
	printf("%d (",decimal1<<arrastar);
	
	for(i = 31; i >= 0; i--)
		printf("%d", resultado[i]);
	
	printf(")");
}

void menu( )
{
	int n,i,saida;
	
	printf("\t         MENU PRINCIPAL\n\n\n");
    printf("\t1- NOT                  2- AND\n");
    printf("\t3- OR                   4- XOR\n");
    printf("\t5- RIGHT SHIFT          6- LEFT SHIFT\n");
    printf("\t7- Sair\n");
    
	do
	{
		inicio:
		printf ("\nDigite sua opcao: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Digite um numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				NOT();
				break;
			
			case 2:	
				printf("Digite o primeiro numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				printf("Digite o segundo numero decimal: ");
				scanf("%d", &decimal2);
				getchar();
				dec2bin2(decimal2);
				AND();
				break;
			
			case 3:
				printf("Digite o primeiro numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				printf("Digite o segundo numero decimal: ");
				scanf("%d", &decimal2);
				getchar();
				dec2bin2(decimal2);
				OR();
				break;
			
			case 4:
				printf("Digite o primeiro numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				printf("Digite o segundo numero decimal: ");
				scanf("%d", &decimal2);
				getchar();
				dec2bin2(decimal2);
				XOR();
				break;
		
			case 5:
				printf("Digite o primeiro numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				printf("Digite quantidade de  bits para direita: ");
				scanf("%d", &arrastar);
				getchar();
				dec2bin2(arrastar);
				RIGHTSHIFT(arrastar);
				break;
		
			case 6:
				printf("Digite o primeiro numero decimal: ");
				scanf("%d", &decimal1);
				getchar();
				dec2bin1(decimal1);
				printf("Digite quantidade de  bits para esquerda: ");
				scanf("%d", &arrastar);
				getchar();
				dec2bin2(arrastar);
				LEFTSHIFT(arrastar);
				break;
		
			case 7:
				printf("THANK YOU!");
				saida = 0;
				break;
			
			default: 
				goto inicio;	
		}
	}while(saida!=0);
}

int main()
{
	menu();
	return 0;
}
