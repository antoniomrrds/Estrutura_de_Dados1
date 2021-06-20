/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
//Protótipo
void receberNumeroReal(float *pontReal);
int receberNumeroInteiro(char *frase);

//Funções
int main(){
char frasePersonalizada[30];	  
    //Chamada da função exercício 01 e 02
//    printf("\n%i", receberNumeroInteiro("Digite um número inteiro de 0 até 100: "));
//    //OU PODE USAR FRASES DIGITADAS PELO USUÁRIO
//    char frasePersonalizada[30];
   printf("\nDigite um frase personalizada: ");
   scanf(" %[^\n]", frasePersonalizada);
   printf("\n%i", receberNumeroInteiro(frasePersonalizada));
    
    //Chamada da função exercício 03
    float numero; //Variável apontada
    receberNumeroReal(&numero);
    printf("\n%.2f", numero);
    return 0;
}

//----------------------------- Exercicio 3 ----------------------------
void receberNumeroReal(float *pontReal){ //Aqui está o ponteiro
    do{
        printf("\nDigite um número real e positivo: ");
        scanf("%f", pontReal);
        if (*pontReal <= 0) {
            printf("\nDigite um número positivo.");
        }
    } while (*pontReal <= 0);
    
}

//----------------------------- Exercicio 1 e 2 ----------------------------
int receberNumeroInteiro(char *frase){ //Adaptação do código do Igor, Claysson e Guilherme Dantas
	int numero = 0;
	do{
		printf("\n%s ", frase);
		scanf("%i", &numero);
		if (numero < 0 || numero > 100){
			printf("\n>>> O numero tem que ser entre 0 e 100");
		}
	}while(numero < 0 || numero > 100);
	
	return numero;
}
