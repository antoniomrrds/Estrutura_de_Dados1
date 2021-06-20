#include <math.h>
#include "bibliotecaRecursividade.h"

//Fun��es

//FATORIAL
int fatorialRecursivo(int n){
    if (n <= 1){
        return 1;
    } else {
        return n * fatorialRecursivo(n-1);
    }
}

int fatorialRecursivoCauda(int n, int resultado){
    if (n <= 1) {
        return resultado;
    } else {
        return fatorialRecursivoCauda(n-1, n * resultado);
    }
}

/* Exerc�cio 01
    Fa�a uma fun��o recursiva que efetue a multiplica��o de dois n�meros naturais, 
    atrav�s de somas sucessivas (Exemplo: 7 * 5 = 7 + 7 + 7 + 7 + 7 = 35)
*/
int somaIterativa(int numero1, int numero2) {
    int resultado = 0;
    do{
        resultado += numero2;
        numero1--;
    } while (numero1 > 0);
    return resultado;
}

//Recurs�o comum direta. 
int somaRecursiva(int numero1, int numero2){
    if (numero1 == 0 || numero2 == 0) { //Caso base - Qualquer n�mero multiplicado por zero � zero. 
        return 0;
    } else if (numero1 == 1) { //Caso base
        return numero2;
    } else { //Case recursivo
        return numero2 + somaRecursiva(numero1-1, numero2);
    }
}

//Recurs�o de cauda direta
int somaRecursivaCauda(int numero1, int numero2, int resultado) {
	if (numero1 == 0 || numero2 == 0) {
		return 0;
	} else if (numero1 == 1) {
		return numero2 + resultado;
	} else {
		return somaRecursivaCauda(numero1-1, numero2, numero2 + resultado);
	}
}

/* Exerc�cio 02
Crie uma fun��o recursiva que receba dois n�meros inteiros e positivos, n e q.
Exiba os q primeiros m�ltiplos de n.
*/

void exibirMultiplicacao(int n, int q){
    /*
    if (q == 0) {//Caso base
        return;
    } else{ //Caso recursivo
        exibirMultiplicacao(n, q-1);
        printf("\n%i * %i = %i", n, q, n*q);
    }
    */
    
    if (q > 0) {//Caso recursivo
        exibirMultiplicacao(n, q-1);
        printf("\n%i * %i = %i", n, q, n*q);
    }
    //Caso base impl�cito. 
}

/*A recursividade de cauda, para a fun��o de Multiplica��o n�o ser� 
"poss�vel" pois preciso deixar o printf para ser exibido depois de abrir a inst�ncia. */

/* Exerc�cio 03
    Crie uma fun��o recursiva para calcular o resultado da seguinte s�rie:
    1/1 + 8/10 +  27/100 + 64/1000+ ...
    O usu�rio ir� definir quantos termos da s�rie ele deseja calcular. Lembre-se que
    este n�mero dever� ser inteiro e positivo.
*/

//Fun��o auxiliar
//Gerar n�mero inteiro 
int receberNumInteiro(){
    int numero;
    do{
        printf("\nDigite um n�mero: ");
        scanf("%i", &numero);
        
        if (numero <= 0) {
            printf("\nInv�lido.");
        }
    } while (numero <= 0);
    return numero;
}

//Fun��o Iterativa
float somarSerieIterativa(int termos){
    float resultado = 0;
    while (termos > 0) {
        resultado += pow(termos, 3) / pow(10, termos-1);
        termos--;
    }
    return resultado;
}

//Fun��o recursiva
//Recursividade comum direta
float somarSerieRecursiva(int termos) {
    if (termos == 1) { //Caso base
        return pow(termos, 3) / pow(10, termos-1);
    } else { //Caso recursivo
        return pow(termos, 3) / pow(10, termos-1) + somarSerieRecursiva(termos-1);
    }
}

//Recursividade de cauda direta
float somarSerieRecursivaCauda(int termos, float parcial) {
	if (termos == 0) {
		return parcial; //No caso base a vari�vel parcial estava pronta para exibir. 
	} else {
		return somarSerieRecursivaCauda(termos-1, pow(termos, 3) / pow(10, termos-1) + parcial);
	}
}

/*Exerc�cio 04
    Fa�a uma fun��o recursiva que permita somar os elementos de um vetor de
    inteiros.
*/

//Recursividade comum direta
int somarVetor(int *vetor, int tam) {
    if (tam == 1) { //caso base
        return *vetor;
    } else { //Caso recursivo
        return *vetor + somarVetor(vetor+1, tam-1);
    }
}

//Recursividade cauda direta
int somarVetorCauda(int *vetor, int tam, int res) {
	if (tam == 1) {
		return *vetor + res;
	} else {
		return somarVetorCauda(vetor+1, tam-1, *vetor + res);
	}

	//Pode gastar uma inst�ncia a mais para chegar ao final pronto. 
	/*
	if (tam == 0) {
		return res;
	} else {
		return somarVetorCauda(vetor+1, tam-1, *vetor + res);
	}
	*/

}
