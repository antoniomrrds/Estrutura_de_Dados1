#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

//int idadeValidacao(){
//	int numIdade = 0;
//	
//		do {
//			 printf("\nDigite a sua idade :");
//             scanf(" %i", & numIdade);
//			 
//                if (numIdade < 1 || numIdade > 100)
//                {
//                    printf("\nvalor Invalido digite idade abaixo de  100  e acima de 0!!!");
//                   
//                }
//				
//		
//     	}while(numIdade < 1 || numIdade > 100);
//	    return numIdade;
//}



int idadeValidacao( char *frase){
	int numIdade = 0;
	
		do {
			
			 printf("\n%s : ",frase);
             scanf(" %i", &numIdade);
			
			 
			 
                if (numIdade < 1 || numIdade > 100)
                {
                   printf("\nvalor Invalido digite idade abaixo de  100  e acima de 0!!!");
                   
                }
				
		
     	}while(numIdade < 1 || numIdade > 100);
	    return numIdade;
}


void valideUmNumeroReal(float *real){
	
	do{
		
		printf("\n Digite o numero real : ");
        printf("\n %f" ,real);
		if(*real<=0){
			   printf("\n Digite um numero positivo!!!");
		}
 
	
     }while(*real<=0);
}

void valideUmNumeroReal(float *real);


int main()
{
	setlocale(LC_ALL, "Portuguese");
//	char frase[30];
//	
//	 printf("\n Digite qual a frase que voce quer que valide de inteiros: ");
//	 
//	 scanf(" %[^\n]", frase);
//	 printf("\n%i",idadeValidacao(frase));
   	float numero; 
	valideUmNumeroReal(&numero);
	 
	 
	  
	 
	 
	 return 0;
}


