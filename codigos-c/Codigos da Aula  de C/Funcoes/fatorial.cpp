
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void fatorial(int numero);

int main(){
	
	fatorial(5);
	return 0 ;
}


void  fatorial(int numero) {
    int fact ;
    int number = numero ;


    for (fact = 1; numero > 1; numero = numero - 1) {
        fact = fact * numero;
    }
    printf("O Fatorial do numero %i e igual a  %i",number,fact);
}



