#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>


//Protótipo
void menu();
void receberValorInteiro(int *valor);
float receberValorReal();
float calcularNovoSalario(float salarioAtual);
float calcularSalario(float*, int);

//Funções
int main(){
	setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}

//Questão 01
void menu(){
    char opcao;
    int numero;
    float *salarios;

    do {
        printf("\nA - Calcular novo salário");
        printf("\nB - Finalizar");
        printf("\nDigite a opção: ");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);

        if (opcao == 'A') {
            printf("\nIniciar cálculo do salário.");
            receberValorInteiro(&numero);
            salarios = (float*) malloc (numero * sizeof(float));
            printf("\nA média dos sal�rios calculados e R$%.2f", calcularSalario(salarios, numero));
        }

    } while (opcao != 'B');
}

//Questão 02
void receberValorInteiro(int *valor){
    printf("\nDigite um número inteiro de 1 até 50: ");
    scanf("%i", valor);
    while (*valor < 1 || *valor > 50) {
        printf("\nValor incorreto. Digite novamente.");
        printf("\nDigite um número inteiro de 1 até 50: ");
        scanf("%i", valor);
    }
}

//Questão 03
float receberValorReal(){
    float valor=0;
   do{
   		printf("\nDigite o valor do salário R$");
        scanf("%f", &valor);

        if (valor <= 0){
            printf("\nValor inválido.");
        }


    }while (valor <= 0);


    return valor;
}

//Questão 04
float calcularNovoSalario(float salarioAtual){
    if (salarioAtual <= 2500) {
        return salarioAtual * 1.15;
    } else if (salarioAtual <= 7500) {
        return salarioAtual * 1.075;
    } else {
        return salarioAtual;
    }
}

//Questão 05
float calcularSalario(float *vetor, int tamanho) {
    float somaSalarios = 0;

    for (int i = 1; i <= tamanho; i++) {
        printf("\nDigite o %iº salário.", i);
        *vetor = receberValorReal();
        *vetor = calcularNovoSalario(*vetor);
        somaSalarios += *vetor;
        vetor++;
    }
    return somaSalarios / tamanho;
}
