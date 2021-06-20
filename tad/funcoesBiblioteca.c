#include "biblioteca.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Protótipos
int informarQuantidadeProdutos();
void cadastrarNome(char *nome);
void cadastrarProdutos(int tam, produto *prodCad);
int cadastrarCodigo();
void cadastrarPreco(double *preco);
void cadastrarQuantidade(produto *listaProdutos);
void imprimirGeral(int qtdeProduto, produto *listaProd);
void imprimirEstoqueZerado(int qtdeProduto, produto *listaProd);


void menu() {
	int opcao;
	int tamanho = 0;
	produto *prod = NULL;
	do{
		printf("\n1– Criar estrutura para preenchimento"
				"\n2 – Preencher dados"
				"\n3 – Exibir produtos com estoque zerado"
				"\n4 – Exibir produtos cadastrados"
				"\n5 – Finalizar"
				"\nDigite a opção desejada: ");
		scanf("%i", &opcao);
		
		switch(opcao) {
			case 1:
				printf("\nAlocação não iniciada %p", prod);
				tamanho = informarQuantidadeProdutos();
				prod = (produto*) malloc (tamanho * sizeof(produto));
				printf("\nAlocação de produtos inicia em %p", prod);
				break;
			case 2:
			    if (tamanho == 0) {//if (prod == NULL) {
			        printf("\nAlocação do produto não realizada.");
			    } else {
			        cadastrarProdutos(tamanho, prod);
			    }
				break;
			case 3:
			    imprimirEstoqueZerado(tamanho, prod);
				break;
			case 4:
			   if (prod == NULL)  {//if (tamanho == 0){
			        printf("\nAlocação do produto não realizada.");
			    } else {
			        imprimirGeral(tamanho, prod);
				}
				break;
			case 5:
				printf("\nPrograma finalizado.");
				break;
			default:
				printf("\nOpção inválida.");
				break;
		}
	} while (opcao != 5);
}

int informarQuantidadeProdutos(){
	int totalProdutos;
	do{
		printf("\nDigite o total de produtos: \n");
		scanf("%i", &totalProdutos);

		if (totalProdutos <= 0) {
			printf("\nQuantidade inválida. Digite novamente. ");
		}
	}while(totalProdutos <= 0);
	return totalProdutos;
}	

void cadastrarNome(char *nome){
    do {
        printf("\nDigite o nome do produto: ");
        scanf(" %[^\n]", nome);
        
        if (strlen(nome) == 0) {
            printf("\nDigite o nome corretamente.");
        }
    } while (strlen(nome) == 0);
}

void cadastrarProdutos(int tam, produto *prodCad){
    int i;
    for(i=1; i <= tam; i++) {
        prodCad->codigo = cadastrarCodigo();
        cadastrarNome(prodCad->descricao);
        cadastrarPreco(&prodCad->preco);
        cadastrarQuantidade(prodCad);
        prodCad++;
    }
}

int cadastrarCodigo(){
    int cod;
    printf("\nDigite o código do produto: ");
    scanf("%i", &cod);
    while (cod < 0 || cod > 50){
        printf("\nCódigo inválido. Digite novamente de 0 até 50.");
        printf("\nDigite o código do produto: ");
        scanf("%i", &cod);
    }
    return cod;
}

void cadastrarPreco(double *preco) {
    *preco = -2;
    while (*preco < 0) {
        printf("\nDigite o preço do produto R$");
        scanf("%lf", preco);
        
        if (*preco < 0) {
            printf("\nValor inválido.");
        }
    }
}

void cadastrarQuantidade(produto *listaProdutos){
    do{
        printf("\nDigite a quantidade existente no estoque do produto %s: ", listaProdutos->descricao);
        scanf("%i", &listaProdutos->quantidade);
        
        if (listaProdutos->quantidade < 0) {
            printf("\nInválido.");
        }
    } while (listaProdutos->quantidade < 0);
}

void imprimirGeral(int qtdeProduto, produto *listaProd) {
    int i;
	for (i = 0; i < qtdeProduto; i++) {
        printf("\nProduto %i - %s - R$%.2lf - %i", 
                listaProd[i].codigo, listaProd[i].descricao, listaProd[i].preco, listaProd[i].quantidade);
    }
}

void imprimirEstoqueZerado(int qtdeProduto, produto *listaProd) {
    int i;
	for (i = 0; i < qtdeProduto; i++) {
        if (listaProd->quantidade == 0) {
            printf("\nProduto %i - %s - R$%.2lf - %i", 
                listaProd->codigo, listaProd->descricao, listaProd->preco, listaProd->quantidade);
        }
        listaProd++;
    }
}
