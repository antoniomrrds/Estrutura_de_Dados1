/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	 
    //Vamos entender o sizeof
    setlocale(LC_ALL, "Portuguese");
    char var;
    printf("\nTamanho do tipo char: %li", sizeof(var));

    //Vamos entender o malloc
    //malloc alocando int - 1 único espaço int
    int *x; //Ponteiro inteiro - Só armazena endereços de memória. 
     x = (int*) malloc (sizeof(int)); //Apontei
    *x = 45; //Alterar o conteúdo
    printf("\nAlocação int\nEndereço da alocação  %p - Conteúdo da alocação: %i", x, *x);
    
    //Malloc alocando char
    char *c;
    c = (char*) malloc (10); //c = (char*) malloc (10 * sizeof(char)); 
    *c = 65;
    //As linhas anteriores reservaram um vetor com 10 posições. 
    printf("\n\nAlocação char");
    int i;
    for ( i = 0; i < 10; i++) {
        printf("\n%i - Endereço da alocação  %p - Conteúdo da alocação: %c", i+1, c, *c);
        c++;
    }
    printf("\nOnde termina a alocação de c? %p", c);
    c-=10; //Reposiciona o ponteiro para o vetor alocado. 
    
    return 0;
}
