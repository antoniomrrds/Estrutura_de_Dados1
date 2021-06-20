#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

//Declaração de estrutura
struct dadosCliente{
	char nome[30];
	int idade;
	float valorCompra;
	char genero;
};

int main(){
	setlocale(LC_ALL, "");
	
	//Declarar e utilizar uma variável comum 
	int i;
	
	//Declarar uma variável composta e homogênea
	float salarios[10];
	//scanf("%f", &salarios[7]);
	
	//Declarar uma estrutura
	struct dadosCliente cli;
	//char nomeCliente[30];
	
	printf("\nDigite o nome do cliente: ");
	scanf(" %[^\n]", cli.nome);
	printf("\nO nome digitado é %s", cli.nome);
	
	cli.idade = -2;
	while (cli.idade <= 0)  {
		printf("\nDigite a idade do cliente %s: ", cli.nome);
		scanf("%i", &cli.idade);
		if (cli.idade <= 0) {
			printf("\nInválido.");
		}
	} 
	printf("\nIdade do cliente %s é %i", cli.nome, cli.idade);
	
	cli.valorCompra = 2300.76;
	printf("\nO valor liberado para compra é R$%.2f", cli.valorCompra);
	
	do{
		printf("\nDigite o gênero do cliente: ");
		scanf(" %c", &cli.genero);
		cli.genero = toupper(cli.genero);
		
		if (cli.genero != 'F' && cli.genero != 'M'){
			printf("\nInválido.");
		}
	} while (cli.genero != 'F' && cli.genero != 'M');
	
	return 0;
}
