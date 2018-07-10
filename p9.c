//Marcos Vinicius Souza Rodrigues
//11711ECP008

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef
	struct Dimensoes
	{
		float largura;
		float profundidade;
		float altura;
	}
Dimensoes_m;
typedef
	struct Produto
	{
		char nome[64];
		float preco;
		Dimensoes_m dimensoes;
	}
Produto_i;
void cadastro(int x, Produto_i p[2])
{
	printf("\nNome: ");
	fgets(p[x].nome, 64, stdin); 
	p[x].nome[strlen(p[x].nome)-1] = '\0';
	printf("\nPreco: ");
	scanf("%f", &p[x].preco);
	getchar();
	printf("\nLargura: ");
	scanf("%f", &p[x].dimensoes.largura);
	getchar();
	printf("\nProfundidade: ");
	scanf("%f", &p[x].dimensoes.profundidade);
	getchar();
	printf("\nAltura: ");
	scanf("%f", &p[x].dimensoes.altura);
	getchar();
}
int main()
{
	int opc1=0, opc2=0, i=0;
	char aux[64];
	Produto_i p[2];
	for (i=0; i<2; i++)
		p[i].nome[0] = '\0';
	do
	{
		printf("\t\t## MENU PRINCIPAL ##");
		printf("\n[1]- Cadastro\n[2]- Consulta\n");
		scanf("%d", &opc1);
		getchar();
		switch (opc1)
		{
			case 1:
				printf("\n[1]- Produto 1\n [2]- Produto 2\n");
				scanf("%d", &opc2);
				getchar();
				printf("\nInsira as informacoes do produto: %d: ", opc2);
				cadastro(opc2-1, p);
				printf("\nCadastro realizado com sucesso!");
				break;
			case 2:
				printf("\nProcurar produto:");
				scanf("%d", &opc2);
				getchar();
				if (strlen(p[opc2-1].nome) == 0)
					printf("\nProduto nao encontrado!\n");
				else
					printf("\n%s, R$ %.2f, L: %.2fm x P: %.2fm x A: %.2fm", p[opc2-1].nome, p[opc2-1].preco, p[opc2-1].dimensoes.largura, p[opc2-1].dimensoes.profundidade, p[opc2-1].dimensoes.altura);
				break;
		}
	}while (opc1 == 1 || opc1 == 2);
	
	return 0;
}
