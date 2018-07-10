#include<stdio.h>

void bin(unsigned int numero)
{
	int nb, i;
	
	for(nb = 0; numero >= (1 << nb); nb++)	{
	}
	
	char bits1[nb];
	
	for(i=0; i<nb; i++){
		if(numero%2==0)
			bits1[i]=0;
		else
			bits1[i]=1;	
		numero=numero/2;
	}
	
	for(i=nb-1; i>=0; i--)
		printf("%i", bits1[i]);
}

int main ()
{
	
	char bits[256], opc;
	int i=0;
	unsigned int num=0;
	
	printf("\t\t##Menu de Controle##\n");
	printf("Conversao de Bases...\n");
	printf("digite:\n");
	printf("\n[1]-Binario para Decimal;\n[2]-Binario para Hexadecimal;\n[3]-Hexadecimal para Decimal;\n[4]-Hexadecimal para Binario;");
	printf("\n[5]-Decimal para Binario;\n[6]- Decimal para Hexadecimal;\n[7]- Octal para Decimal;\n[8]- Decimal para Octal.\n");
	printf("\nOpcao:");
	scanf("%c", &opc);
	getchar();
	
	switch(opc)
	{
		case '1':
			scanf("%s", (char *) &bits);
			getchar();
			for(i=0; bits[i] != '\0'; i++)
				num = num*2 + (bits[i] - '0');	
			printf("%d", num);
			break;
		case '2':
			scanf("%s",(char *) &bits);
			getchar();
			for(i=0; bits[i] != '\0'; i++)
				num = num*2 + (bits[i] - '0');	
			printf("%X", num);
			break;
		case '3':
			scanf("%X", &num);
			getchar();
			printf("%d", num);
			break;
		case '4':
			scanf("%X", &num);
			getchar();
			bin(num);
			break;
		case '5':
			scanf("%d", &num);
			getchar();
			bin(num);
			break;
		case '6':
			scanf("%d", &num);
			getchar();
			printf("%X", num);
			break;	
		case '7':
			scanf("%o", &num);
			getchar();
			printf("%d", num);
			break;
		case '8':
			scanf("%d", &num);
			getchar();
			printf("%o", num);
			break;
	}while(opc > '8'){
	
	printf("Opcao invalida");
	break;
}

	return 0;
}
