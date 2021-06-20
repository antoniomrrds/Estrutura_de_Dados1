#include <stdio.h>
#include <stdlib.h>

typedef union {
	int valor;
	char tipo;
}calc;

void calcular(calc *valores, int i){
	if(i != 0){
		printf("\nDigite o valor: ");
		scanf("%i",&valores -> valor);
		valores->tipo = ((valores->valor > 100) ? 'A' : 'B');
		calcular(valores,i++);
	}
	
}

int main(){
	calc *val = (calc*) malloc (2 * sizeof(calc));
	calcular(val,2);
	return 0;
}

