/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
//Protótipos
void exibirMensagem();
int somarNumeros(int *numero1, int numero2);//numero1 - referência e numero2 - valor
float dividirNumeros(int, float, double);

//Funções
int main(){
    exibirMensagem();
    //int somatorio = somarNumeros(somarNumeros(3,2), 37);
    int numero1 = 5,
        numero2 = 37,
        somatorio = somarNumeros(&numero1, numero2);
    printf("\nDentro da main - numero1 = %d e numero2 = %d", numero1, numero2);
    //printf("\n%d", somatorio);
    printf("\nPrograma finalizado.");
    return 0; //Finalizado com sucesso. 
}

void exibirMensagem(){
	int i;
  for ( i = 0; i < 30; i++) {
    printf("\nOlá Mundo!");
    printf("\n%d", somarNumeros(100, 45));
}
}

int somarNumeros(int *numero1, int numero2){
    *numero1 *= 2;
    numero2 += 150;
    printf("\nDentro da somarNumeros - numero1 = %d e numero2 = %d", *numero1, numero2);
    return *numero1 + numero2;
}

float dividirNumeros(int numero1, float numero2, double numero3){
    numero2 += numero3;
    return (float) numero1 / numero2;
}
