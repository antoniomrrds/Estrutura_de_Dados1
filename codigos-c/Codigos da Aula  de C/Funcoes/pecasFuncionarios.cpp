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
	
	  printf("\nDigite o numero de posicões do  vetor : ");
	  scanf(" %i", primeiroVetor);
	  
	  if(*primeiroVetor<=0){
	  	printf("\nDigite um numero para o primeiro vetor maior que 0 !!!");
	  	
	   }
	
   }while(*primeiroVetor<=0);
   


	  int i;
	   //Vetor peças produzidas 
	   int *pecasProduzidas = (int *) malloc(sizeof(int)* *primeiroVetor);
	   //Salário por peças produzidas 
       float *salarioProducao = (float *) malloc(sizeof(float)* *primeiroVetor);
	   for ( i = 0; i < *primeiroVetor; i++) {
	  
	  
	    do {
		
	    printf("\nDigite a quantidade de peças produzidas pelo usuario  %d: ",i+1);
	    scanf(" %i",pecasProduzidas);
	    
	    if(*pecasProduzidas<0){
	    	printf("\nDigite um numero de peças maior ou igual 0 !!!");
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
		   
		printf("\nO Funcionário Estuda : ");
		fflush(stdin);
	    scanf(" %c", &decisao);
	    decisao = toupper(decisao);
	    if(decisao!='S' && decisao!='N'){
	    	printf("Digite S para sim ou N para não !!!");
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
		
		printf("\nsalario peças podruzidas %.2f: ",*salarioProducao);
	 
	 
	 // somando salários 
 	  somaSalarios += *salarioProducao;
       pecasProduzidas++;
       salarioProducao++;
    }
    
    	pecasProduzidas -= *primeiroVetor;   
    	salarioProducao -= *primeiroVetor;
    	printf("\n\nVetor funcionários e Salarios");
     	 for ( i = 0; i < *primeiroVetor; i++) {
    	 	printf("\nFuncionário : %i  Quantidades de peças Fabricadas : %i Salário por peças fabricadas: %.2f", i+1, *pecasProduzidas,*salarioProducao);
		    pecasProduzidas++;
            salarioProducao++;
		 };
		 printf("\nA Soma de Salários %.2f: ", somaSalarios);
	     printf("\nO Maior Salário: %.2f  e a Quantidade de peças: %i ", maior,contPecas);
		    //Liberar os espaços alocados. 
		 	free(primeiroVetor);
        	free(pecasProduzidas);
        	free(salarioProducao);
 		
    return 0;
}
