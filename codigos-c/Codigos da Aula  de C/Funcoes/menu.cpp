#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//structs
typedef struct produto products;
struct produto{
	char descricao[40];
	int codigo;
	double preco;
	int quantidade;
};



//Prototype
void menu();
void cadastrarNome(char *nome);
int main(){
	setlocale(LC_ALL, "");
	menu();
	
	return 0;
}


void menu(){
	int choice;
	do{
     printf("\n1- Criar estrutura para preenchimento: ");
     printf("\n2- Preencher dados: ");
     printf("\n3- Exibir Produtos com estoque zerado: ");
     printf("\n4- Exibir Produtos cadastrados: ");
     printf("\n5- Finalizar: ");
     printf("\n Selecione a Op��o: ");
     fflush(stdin);
     scanf("%i",&choice);
     if(choice >= 6 || choice < 1){
     	printf("Digite uma op��o valida !");
	 }
	 if
	}while(choice != 5);

}

void numberProducts(){
    
	int totProducts;
	do{
	
 	 printf("Digite o N�mero total de produtos");
 	 scanf("%i",&totProducts);
	 if( totProducts < 1){
	 	printf("Digite um N�mero positivo !!!");
	 }	
}while( totProducts <1);

}


void cadastrarNome(char *nome){
	do{
		if(*nome == NULL ){
	           printf("Digite um Nome N�o deixe vazio !!!");
	       }
	     printf("Digite o Nome");
 	     scanf("%s",nome);
	}while(*nome == NULL);

		 
}
