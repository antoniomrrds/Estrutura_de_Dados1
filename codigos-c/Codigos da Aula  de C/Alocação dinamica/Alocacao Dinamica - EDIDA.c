#include <stdio.h>
#include <stdlib.h>

int main(){
	//Alocação de um espaço int
	int *x;
	x = (int*) malloc (sizeof(int));
	*x = 50;
	printf("\nAlocação int\nConteúdo da área apontada %i - Endereço da área apontada %p", *x, x);
	
	//Alocação de vetor char
	int i;

	char *c;
	c = (char*) malloc (10); 
	printf("\n\nAlocação char");
	for (i = 0; i < 10; i++ ,c++) {
		*c = 65 + i;
		printf("\n%i - Conteúdo da área apontada %c - Endereço da área apontada %p", i, *c, c);
//		c++;
	}
	printf("\nOnde finaliza do meu ponteiro c? %p", c);
	c -= 10;
	printf("\nRealocando ao início do vetor %p", c);
	
	//Alocação de vetor double
	double *y = (double*) malloc (5 * sizeof(double)); 
	printf("\n\nAlocação double");
	for (i = 0; i < 5; i++) {
		*y = rand() % 1000;
		printf("\n%i - Conteúdo da área apontada %4.4lf - Endereço da área apontada %p", i, *y, y);
		y++;
	}
	printf("\nOnde finaliza do meu ponteiro y? %p", y);
	y -= 5;
	printf("\nRealocando ao início do vetor %p", y);
	
	//Alocação de vetor float
	float *f = (float*) calloc (3, sizeof(float));
	printf("\n\nAlocação float");
	for (i = 0; i < 3; i++) {
		*f = rand() % 1000;
		printf("\n%i - Conteúdo da área apontada %.2f - Endereço da área apontada %p", i, *f, f);
		f++;
	}
	printf("\nOnde finaliza do meu ponteiro y? %p", f);
	f -= 3;
	printf("\nRealocando ao início do vetor %p", f);	
	
	//Liberar os espaços alocados. 
	free(x);
	free(c);
	free(y);
	free(f);
	
	return 0;
}
