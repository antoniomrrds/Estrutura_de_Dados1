#include <stdio.h>
#include <stdlib.h>

int main(){
	//Aloca��o de um espa�o int
	int *x;
	x = (int*) malloc (sizeof(int));
	*x = 50;
	printf("\nAloca��o int\nConte�do da �rea apontada %i - Endere�o da �rea apontada %p", *x, x);
	
	//Aloca��o de vetor char
	int i;

	char *c;
	c = (char*) malloc (10); 
	printf("\n\nAloca��o char");
	for (i = 0; i < 10; i++ ,c++) {
		*c = 65 + i;
		printf("\n%i - Conte�do da �rea apontada %c - Endere�o da �rea apontada %p", i, *c, c);
//		c++;
	}
	printf("\nOnde finaliza do meu ponteiro c? %p", c);
	c -= 10;
	printf("\nRealocando ao in�cio do vetor %p", c);
	
	//Aloca��o de vetor double
	double *y = (double*) malloc (5 * sizeof(double)); 
	printf("\n\nAloca��o double");
	for (i = 0; i < 5; i++) {
		*y = rand() % 1000;
		printf("\n%i - Conte�do da �rea apontada %4.4lf - Endere�o da �rea apontada %p", i, *y, y);
		y++;
	}
	printf("\nOnde finaliza do meu ponteiro y? %p", y);
	y -= 5;
	printf("\nRealocando ao in�cio do vetor %p", y);
	
	//Aloca��o de vetor float
	float *f = (float*) calloc (3, sizeof(float));
	printf("\n\nAloca��o float");
	for (i = 0; i < 3; i++) {
		*f = rand() % 1000;
		printf("\n%i - Conte�do da �rea apontada %.2f - Endere�o da �rea apontada %p", i, *f, f);
		f++;
	}
	printf("\nOnde finaliza do meu ponteiro y? %p", f);
	f -= 3;
	printf("\nRealocando ao in�cio do vetor %p", f);	
	
	//Liberar os espa�os alocados. 
	free(x);
	free(c);
	free(y);
	free(f);
	
	return 0;
}
