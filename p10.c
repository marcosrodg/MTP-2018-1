//Marcos Vinicius Souza Rodrigues
// 11711ECP008

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHAR_NOME 64

typedef struct
{
	float largura, profundidade, altura;
}Dimensoes;

typedef struct
{
	char nome[CHAR_NOME];
	float preco;
	Dimensoes dimensoes;
}Produto;

int sizeofFile(char nomearquivo[CHAR_NOME])
{
	int sof = 0;
	
	FILE* arquivo = fopen(nomearquivo, "rb");
	
	if (arquivo)
	{
		fseek(arquivo, 0, SEEK_END);
		sof = ftell(arquivo); 
		fclose(arquivo);
	}else
	{
		fprintf(stderr, ">>> Arquivo nao encontrado!\n");
		sof = -1;
	}
	
	return sof;
}


void cadastrarNovo(Produto *p, int cont)
{
	printf("Nome do produto: ");
	scanf("%s", p[cont].nome); getchar();
	printf("Preco: ");
	scanf("%f", &p[cont].preco); getchar();
	printf("Largura: ");
	scanf("%f", &p[cont].dimensoes.largura); getchar();
	printf("Profundidade: ");
	scanf("%f", &p[cont].dimensoes.profundidade); getchar();
	printf("Altura:");
	scanf("%f", &p[cont].dimensoes.altura); getchar();
	printf("\nCadastramento realizado com sucesso!\n\n");
}

void consultar(Produto *p, int cont)
{
	if(cont == 0)
		printf("\n produto nao pode ser cadastrado!\n\n");
	else
	{
		int i, op; 
		printf("Lista de produtos cadastrados: %d\n0. Voltar\n", cont);
		
		for(i = 0 ; i < cont; i++)
			printf("%d. %s\n", i+1, p[i].nome);
		
		printf("\nOpcao desejada: ");
		scanf("%d", &op);
		getchar();
		
		if(op != 0)
		{
			if(op>cont)
				printf("Produto nao encontrado!\n\n");
			else
			{
				op--;
				printf("%s, R$ %.2f, L: %.2f m x P: %.2f m x A: %.2f m\n\n", p[op].nome, p[op].preco, p[op].dimensoes.largura, p[op].dimensoes.profundidade, p[op].dimensoes.altura);
			}
		}
	}
}

void abrirArq(Produto *p, int *cont)
{
	FILE *arquivo;
	char nomearquivo[CHAR_NOME];
	
	printf("\nNome do arquivo: ");
	scanf("%s", nomearquivo);
	
	int sof = sizeofFile(nomearquivo), i;
	
	if (sof > 0)
	{
		arquivo = fopen(nomearquivo, "rb");
		*cont = sof/sizeof(Produto);
		p = (Produto *) realloc(p, *cont*sizeof(Produto));
		if(p!=NULL)
		{
			for(i = 0; i < *cont; i++)
			{
				fread(p[i].nome, sizeof(char), CHAR_NOME, arquivo);
				fread(&p[i].preco, sizeof(float), 1, arquivo);
				fread(&p[i].dimensoes.largura, sizeof(float), 1, arquivo);
				fread(&p[i].dimensoes.profundidade, sizeof(float), 1, arquivo);
				fread(&p[i].dimensoes.altura, sizeof(float), 1, arquivo);	
			}
			printf("\nArquivo contem %d produto(s). Leitura realizada com sucesso!\n\n", *cont);
		}
		else {
			fprintf(stderr, ">>> Problema na realocacao da memoria!\n\n");
			cont = 0;
		}
	fclose(arquivo);
	}else
		fprintf(stderr, ">>> Carregamento nao pode ser efetuado!\n\n");	
}

void salvarArq(Produto *p, int cont)
{
	FILE *arq;
	int i = 0;
	char nomearquivo[CHAR_NOME];
	
	printf("\nNome do arquivo: ");
	scanf("%s", nomearquivo); getchar();
	
	if((arq = fopen(nomearquivo,"wb")) != NULL)
	{
		for(i = 0; i < cont; i++)
		{
			fwrite(p[i].nome, sizeof(char), CHAR_NOME, arq);
			fwrite(&p[i].preco, sizeof(float), 1, arq);
			fwrite(&p[i].dimensoes.largura, sizeof(float), 1, arq);
			fwrite(&p[i].dimensoes.profundidade, sizeof(float), 1, arq);
			fwrite(&p[i].dimensoes.altura, sizeof(float), 1, arq);
		}
		printf("Produtos cadastrados com sucesso!\n\n");
		fclose(arq);
	}else
		printf("Erro: não impossível abrir o arquivo\n\n");
}

int main()
{
	Produto *p;
	int cont = 0, op;
	p = malloc(sizeof(Produto));
	
	do
	{
		printf("\t\tPainel de Comando\n");
		printf("\t\t\t\t\t\tProdutos em memoria:%d\n\n",cont);
		printf("\n[1]. Consultar\n[2]. Cadastrar novo\n[3]. Carregar de arquivo para memoria (substituir conteudo na memoria)");
		printf("\n[4]. Salvar memoria em arquivo (substituir conteudo na memoria)\n\n[0]. Encerra\n\nOpcao: ");
		scanf("%d", &op);
		getchar();

		switch(op)
		{
			case 1:
				consultar(p, cont);
				break;
			case 2:
				cadastrarNovo(p, cont);
				cont++;
				break;
			case 3:
				abrirArq(p, &cont);
				break;
			case 4:
				salvarArq(p, cont);
				break;
		}	
	}while(op!=0);
	
	free(p);
	
	return 0;
}
