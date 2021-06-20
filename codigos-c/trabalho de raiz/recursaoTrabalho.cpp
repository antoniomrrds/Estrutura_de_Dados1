#include <stdio.h>
#include <locale.h>
//Victor não fez nada! falo que ia desenvolver mas não desenvolveu
//Funcoes recursiva
//com cauda
int raizQuadradaComCaudarecursiva(int n,int result);
//sem cauda
int raizQuadradaSemCaudaRecursiva(int n,int numeroImpar);

int main(){
	setlocale(LC_ALL,"");
	int n = 9,raiz;
        raiz =  raizQuadradaComCaudarecursiva(9,0);
//      raiz =  raizQuadradaSemCaudaRecursiva(9,1);
	(raiz > 0) ? 
	    printf("\nRaiz de %i = %i",n,raiz)
	:
	    printf("\nNão existe raiz quadrada possível para %i",n);
	
	return 0;
}


int raizQuadradaComCaudarecursiva(int n,int result){

    n -= result*2 + 1;
    result += 1;

	if(n==0){
		return result;
	} 
    
    if (n<0) {
        return -1;
    }

	return raizQuadradaComCaudarecursiva(n, result);
}

int raizQuadradaSemCaudaRecursiva(int n,int numeroImpar){
	if (n < 0) return -1;
	if (n == 0) return  0;
	int result = raizQuadradaSemCaudaRecursiva(n - numeroImpar, numeroImpar + 2);
	return result < 0 ? result: 1 + result;
} 


