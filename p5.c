//Marcos Vinicius Souza Rodrigues
//11711ECP008

#include<stdio.h>

void codificao()
{
	char str[256]={'\0'};
	int *ps, i=0;
	
	printf("\nDigite uma mensagem: ");
	scanf(" %[^\n]s",&str); 
	char *pmsg=str;
	printf("Codificada: ");
	for(i=0;str[i];i++)
	{
		ps=(int *)pmsg;
		if(ps[i]!=0)
			printf("%d",ps[i]);
		if(ps[i+1]!=0)
			printf(", ");
	}
}

void decodificao()
{
	char *p;
	int q[64], i=0;
	printf("\nColoque espaco + 0 ao finalizar a entrada dos dados!");
	printf("\nDigite a mensagem para ser decodificada: ");
	
	for(i=0;i<64;i++)
	{
		scanf("%d",&q[i]);
		getchar();
		p=(char *)q;
		if(q[i]==0)
		break;
	}
	printf("decodificado: ");
	printf("%s",p);
}
 
void menu()
{
	int op,saida=0;
	


	printf("\t\t## MENU ##\n\n");
    printf("\t1- Codificar");
	printf("\t2- Decodificar\n\n");
	printf("\t\t\t3-SAIR.");

	do
	{

	    inicio:
		printf ("\n\nDigite a opcao desejada: ");
		scanf("%d",&op);
		getchar();	
		switch(op)
		{
			case 1:
				codificao();
				saida=1;
				break;
				
			case 2:
				decodificao();
				saida=2;
				break;
				
			case 3:
				printf("\nTHANK YOU!\n");
				saida=3;
				break;	
				
			default: 
			printf("Entrada invalida!");
				goto inicio;				
				
		}
	}while(saida!=3);
}

int main( )
{
	menu();
	return 0;
}
