/* Marcos Vinicius Souza Rodrigues
   11711ECP008*/

#include <stdio.h>


int main()
{
	int estado = 0 ,i = 0;
	char bits[256];
	
	
	printf("Entre com uma sequencia binaria '0' e '1' :\n");
	scanf("%s",bits);
	
	while(bits[i] != '\0')
	{
		if( bits[i]=='0')
		{
			if(estado==0)
				estado=0;
			else	
			{
			 if(estado==1)
				estado=2;
				else
				{	 
					if(estado==2)
						estado=1;
				}
			}
		}
		
		if(bits[i]=='1')
		{
				
			if(estado==0)				
				estado = 1;
			else
			{	
				if(estado==1)
					estado = 0;
				else
				{
					if(estado==2)
						estado=2;
		        }
		    }
		}	

	i++;
	}
	
	printf("\n\nO valor do automato e %i",estado);
	
	if(estado != 0)
			printf("\n\n Nao e multiplo de 3");
	
	if(estado == 0)
		printf("\n\n E multiplo de 3 ");
		

	
	
	return 0;
}
