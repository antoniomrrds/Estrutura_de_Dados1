#include "bibliotecaRecursividade.h"
#include <locale.h>

int main(){
	setlocale(LC_ALL, "");
    int num1 = 5,
        num2 = 6;
    //Exemplo
    //printf("\n%i! = %i", num1, fatorialRecursivo(num1));
    //printf("\n%i! = %i", num1, fatorialRecursivoCauda(num1, 1));
    
    //Exercício 01 - Somas sucessivas
    //printf("\n%d * %d = %d", num1, num2, somaIterativa(num1, num2));
    //printf("\n%d * %d = %d", num1, num2, somaRecursiva(num1, num2));
    //printf("\n%d * %d = %d", num1, num2, somaRecursivaCauda(num1, num2, 0));
    
    //Exercício 02 - Multiplicação
    //exibirMultiplicacao(num1, num2);
    
    //Exercício 03 - Somar série matemática
    //num1 = receberNumInteiro();
    //printf("\nSérie com %d termos %.2f", num1, somarSerieIterativa(num1));
    //printf("\nSérie com %d termos %.2f", num1, somarSerieRecursiva(num1));
    //printf("\nSérie com %d termos %.2f", num1, somarSerieRecursivaCauda(num1, 0));
    
    //Exercício 04 - Somar vetor. 
    int vet[5] = {10, 20, 30,34, 87};
    printf("\nO somatório do vetor é %i", somarVetor(vet, 5));
    printf("\nO somatório do vetor é %i", somarVetorCauda(vet, 5, 0));
    
    return 0;
}
