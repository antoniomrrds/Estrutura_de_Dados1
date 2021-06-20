/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

//Criar estrutura
typedef struct itens itens;
struct itens{
   int quantidade;
   double valorUnitario;
} ;

//Criar união
typedef union dadosItens dadosItens;
union dadosItens{
   int quantidade;
   double valorUnitario;
   char booleano;
};

int main(){
    //Utilizar a estrutura
    itens produtos;
    produtos.quantidade = 10;
    produtos.valorUnitario = 20.87;
    printf("\nImprimir Valores da estrutura - %.2f", produtos.quantidade * produtos.valorUnitario);
    printf("\nTamanho da estrutura itens %li", sizeof(produtos));

    //Utilizar a union
    dadosItens produtosUnion;
    produtosUnion.quantidade = 10;
    //produtosUnion.valorUnitario = 20.87;
    printf("\n\n\nImprimir Valores da união - %i", produtosUnion.quantidade);
    printf("\n\n\nImprimir Valores da união - %.2f", produtosUnion.valorUnitario);
    printf("\n\n\nImprimir Valores da união - %.2f", produtosUnion.quantidade * produtosUnion.valorUnitario);
    printf("\nTamanho da união dadosItens %li", sizeof(produtosUnion));
    
    return 0;
}
