#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int *primeiroVetor,contPecas;
	primeiroVetor = (int *) malloc(sizeof(int));
	float somaSalarios =0;
	float maior = 0 ;
	char decisao;
	   	

	do{
	
	  printf("\nDigite o numero de posic�es do  vetor : ");
	  scanf(" %i", primeiroVetor);
	  
	  if(*primeiroVetor<=0){
	  	printf("\nDigite um numero para o primeiro vetor maior que 0 !!!");
	  	
	   }
	
   }while(*primeiroVetor<=0);
   


	  int i;
	   //Vetor pe�as produzidas 
	   int *pecasProduzidas = (int *) malloc(sizeof(int)* *primeiroVetor);
	   //Sal�rio por pe�as produzidas 
       float *salarioProducao = (float *) malloc(sizeof(float)* *primeiroVetor);
	   for ( i = 0; i < *primeiroVetor; i++) {
	  
	  
	    do {
		
	    printf("\nDigite a quantidade de pe�as produzidas pelo usuario  %d: ",i+1);
	    scanf(" %i",pecasProduzidas);
	    
	    if(*pecasProduzidas<0){
	    	printf("\nDigite um numero de pe�as maior ou igual 0 !!!");
           }
           
 	    }while(*pecasProduzidas<0);


       
	    if( *pecasProduzidas<=200  ){
		 *salarioProducao =  *pecasProduzidas* 2;
		}else if( *pecasProduzidas>200 && *pecasProduzidas <=400){
			*salarioProducao =  *pecasProduzidas* 2.30;
		}else {
		    *salarioProducao =  *pecasProduzidas* 2.50;
		}
	   
	   
	   	do{
		   
		printf("\nO Funcion�rio Estuda : ");
		fflush(stdin);
	    scanf(" %c", &decisao);
	    decisao = toupper(decisao);
	    if(decisao!='S' && decisao!='N'){
	    	printf("Digite S para sim ou N para n�o !!!");
		}
	    
	   }while(decisao!='S' && decisao!='N');


	   
	    // mais 10% do salario 
	    if(decisao =='S'){
//	    	*salarioProducao += (*salarioProducao *  0.1);
          *salarioProducao = *salarioProducao * (1.1);
		}
		// maior salario
	
		if(*salarioProducao>maior){
		  maior=*salarioProducao;
		  contPecas = *pecasProduzidas;
		}
		
		printf("\nsalario pe�as podruzidas %.2f: ",*salarioProducao);
	 
	 
	 // somando sal�rios 
 	  somaSalarios += *salarioProducao;
       pecasProduzidas++;
       salarioProducao++;
    }
    
    	pecasProduzidas -= *primeiroVetor;   
    	salarioProducao -= *primeiroVetor;
    	printf("\n\nVetor funcion�rios e Salarios");
     	 for ( i = 0; i < *primeiroVetor; i++) {
    	 	printf("\nFuncion�rio : %i  Quantidades de pe�as Fabricadas : %i Sal�rio por pe�as fabricadas: %.2f", i+1, *pecasProduzidas,*salarioProducao);
		    pecasProduzidas++;
            salarioProducao++;
		 };
		 printf("\nA Soma de Sal�rios %.2f: ", somaSalarios);
	     printf("\nO Maior Sal�rio: %.2f  e a Quantidade de pe�as: %i ", maior,contPecas);
		    //Liberar os espa�os alocados. 
		 	free(primeiroVetor);
        	free(pecasProduzidas);
        	free(salarioProducao);
 		
    return 0;
}
