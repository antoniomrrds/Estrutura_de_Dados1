/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main(){
    //Declarar variável comum
    //int idade; //Variável int que armazena números inteiros. 
    int *pontIdade; //Ponteiro que armazena endereços de memória de inteiros. 
    int dia;
    int idade;

    printf("\nDigite a idade: ");
    scanf("%i", &idade);
    
 sacnf ( *(pontIdade+10));
    
    //Apontamento
    pontIdade = &idade; 
    dia = *pontIdade; //dia = idade;
    *pontIdade = 190;
    
    printf("\nAcesso direto - idade = %i e endereço = %p", idade, &idade);
    printf("\nAcesso indireto - idade = %i e endereço = %p", *pontIdade, pontIdade); //Só acontece se estiver referenciada. 
    printf("\nEndereço do ponteiro %p", &pontIdade);
    printf("\nDia = %i", dia);

    //Declaração de vetor
    int vetorIdade[3] = {23, 78, 94};
    pontIdade = vetorIdade; //pontIdade = &vetorIdade[0]; //Fazem a mesma coisa.
    
    for(int i = 0; i < 3; i++) {
        //printf("\nvetor[%i] = %d - %p",i, vetorIdade[i], &vetorIdade[i]);
        printf("\nvetor[%i] = %d - %p",i, *pontIdade, pontIdade);
        pontIdade++;
    }
    
    
    return 0;
}
