
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
//Prototipos
void receberMenu(char *descisao);
// funcao 2

void receberValorInteiro(int *valor);
//funcao 3 
float receberValorReal();
//funcao 4
float novoSalario(float salario);
void varrendoElementosIndice(int *pVet, int tam);
void varrendoSalario(int *pVet, int tam);


int main(){
	setlocale(LC_ALL, "Portuguese");
	// menu
    char choice;
    receberMenu(&choice);
    
    return 0; 
}

void receberMenu(char *descisao){
    
    do{
        printf("\n A - Calcular novo salário : ");
        printf("\n B - Finalizar : ");
        fflush(stdin);
        scanf("%c", descisao);
        	*descisao = toupper(*descisao);
        if (*descisao == 'B') {
            break;
        }
         if (*descisao == 'A') {
         	 int posVetor;
	         receberValorInteiro(&posVetor);
	         
	          int vetorReal[posVetor];
	          
	          varrendoElementosIndice(vetorReal,posVetor);
	       
	        
	         
	         
	         
	         
        }
    } while ( *descisao != 'B');
    
}
// funcao 2

void receberValorInteiro(int *valor){
	    do{
        printf("\n Digite um número inteiro e positivo: ");
        fflush(stdin);
        scanf("%i", valor);
        if ( *valor < 0 || *valor > 50 ) {
            printf("\nDigite um número positivo e menor que 50. ");
        }
    } while ( *valor < 0 || *valor > 50);
    
}
// funcao 3

float receberValorReal(){
	float real = 0;
	 do{
        printf("\nDigite um número real e positivo: ");
        fflush(stdin);
        scanf("%f", &real);
        if (real < 0) {
            printf("\nDigite um número positivo.");
        }
        
   }while(real < 0);
    return real;
}
// funcao 4
float novoSalario(float salario){
       float newSalario = 0;
        
		if ( salario > 0 && salario <= 2500) {
            newSalario += (salario *  0.15) + salario;
        
        } else if(salario >  2500 && salario <=7000){
		   newSalario += (salario *  0.075) + salario;
		}else if(salario >7000){
			return salario;
		}
	

     return newSalario; 


}
void varrendoElementosIndice(int *pVet, int tam){
	int i;

	for (i = 0; i < tam; i++){
		receberValorReal() == *pVet;
		pVet++;
	}
}

void varrendoSalario(int *pVet, int tam){
	int i;
    tam -=*pVet;
	for (i = 0; i < tam; i++){
	novoSalario(*pVet);
		pVet++;
	}
}







