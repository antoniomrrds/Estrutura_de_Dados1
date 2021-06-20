/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Novos tipos com o typedef
typedef int inteiro; //Carregou todas as características do int para o apelido inteiro. 
typedef int inteiroVetor[5];
typedef int* inteiroPonteiro;

//Exemplo fantástico
typedef char string[30];

//Protótipo
inteiro calcular(inteiro x);
void imprimir();
inteiroPonteiro exibir();

int main(){
    int i = 67;
    inteiro x = i;
    printf("\n%i", x);
    printf("\n%i", calcular(x));
    
    string nome = "Amanda";
    printf("\n%s", nome);
    printf("\n%li", sizeof(string));
    printf("\nTamanho do nome %li\n", strlen(nome));
    
    imprimir();
    printf("\n%p", exibir());

    return 0;
}

inteiro calcular(inteiro x) {
    return x * 10;
}

void imprimir(){
    inteiroVetor x;
    for (inteiro i = 0; i < 5; i++) {
        x[i] = calcular(i);
        printf("\n\n%i", x[i]);
    }
}

inteiroPonteiro exibir(){
    inteiro *x = (inteiro*) malloc (sizeof(inteiro));
    
    int p = 89;
    inteiroPonteiro pontP;
    pontP = &p;
    printf("\nConteúdo de p = %i e Endereço de p = %p", p, &p);
    printf("\nConteúdo de p = %i e Endereço de p = %p", *pontP, pontP);
    
    
    return x;
}
