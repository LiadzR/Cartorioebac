#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/strings
	
	setlocale(LC_ALL, "portuguese"); //definindo linguagem
		
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado:");//coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo / W significa Write
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite um nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fprintf(file, ".");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo linguagem]
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("arquivo n�o encontrado: \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file);
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado!\n");
		system("pause");
	}

	else{
		remove(cpf);
		printf("Usu�rio deletado!\n");
		system("pause");
	}
	
}

int main() //fun��o principal
{
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); // respons�vel por limpar a tela

		setlocale(LC_ALL, "portuguese"); //definindo linguagem

		printf("### cart�rio da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n");
		printf("op��o:");//fim do menu
	
		scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
		system("cls");
	
		switch(opcao)
		{
			case 1:
				registro(); //chamada de fun��es
				break;
		
			case 2:
				consulta();//chamada de fun��es
				break;
		
			case 3:
				deletar();//chamada de fun��es
				break;
		
			default:
				printf("op��o n�o dispon�vel\n");
				system("pause");
				break;	
		}	
	}
}
