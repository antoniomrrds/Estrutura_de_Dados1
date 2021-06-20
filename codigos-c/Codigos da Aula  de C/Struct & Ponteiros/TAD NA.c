#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

//Declara��o de estrutura
struct dadosCliente{
	char nome[30];
	int idade;
	float valorCompra;
	char genero;
};

int main(){
	setlocale(LC_ALL, "");
	
	//Declarar e utilizar uma vari�vel comum 
	int i;
	
	//Declarar uma vari�vel composta e homog�nea
	float salarios[10];
	//scanf("%f", &salarios[7]);
	
	//Declarar uma estrutura
	struct dadosCliente cli;
	//char nomeCliente[30];
	
	printf("\nDigite o nome do cliente: ");
	scanf(" %[^\n]", cli.nome);
	printf("\nO nome digitado � %s", cli.nome);
	
	cli.idade = -2;
	while (cli.idade <= 0)  {
		printf("\nDigite a idade do cliente %s: ", cli.nome);
		scanf("%i", &cli.idade);
		if (cli.idade <= 0) {
			printf("\nInv�lido.");
		}
	} 
	printf("\nIdade do cliente %s � %i", cli.nome, cli.idade);
	
	cli.valorCompra = 2300.76;
	printf("\nO valor liberado para compra � R$%.2f", cli.valorCompra);
	
	do{
		printf("\nDigite o g�nero do cliente: ");
		scanf(" %c", &cli.genero);
		cli.genero = toupper(cli.genero);
		
		if (cli.genero != 'F' && cli.genero != 'M'){
			printf("\nInv�lido.");
		}
	} while (cli.genero != 'F' && cli.genero != 'M');
	
	return 0;
}
