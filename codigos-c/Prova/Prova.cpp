#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

//Prototipos
void menu();
void minhaStrcat(char *string_destino,char *string_origem);
int valorInteiro(char *frasePersonalizada);
float valorReal(float *valor,char *frasePersonalizada);
float calcularNumeroReal(float valorReal);
float percorrendoArray(float *vetor, int size);

int main(){
	setlocale(LC_ALL, "");
    menu();
   
    return 0;
}
//Funcao 1
void menu(){
	int choice;
	char word[60], word2[60];
	float *qtdInform;
	int tamanhoVetor;
   do{
     printf("\n1 - Para exibir a solução da Questao 2?");
     printf("\n2 - Para exibir a solução da Questao 6?");
     printf("\n3 - Finalizar execucão: ");
     printf("\n Selecione a Opção: ");
     fflush(stdin);
     scanf(" %i", &choice);

      if(choice == 1){
   			 printf("\nDigite uma Palavra: ");
   			 fflush(stdin);
 		     scanf(" %[^\n]",word);
 	  		 printf("\nDigite outra Palavra: ");
 	  		 fflush(stdin);
  			 scanf(" %[^\n]",word2);
             minhaStrcat(word,word2);
             printf("valor da 1º variável word = %s valor da 2º variável word2 =  %s \n", &word,&word2);
	  } if(choice == 2){
	  	tamanhoVetor = valorInteiro("Digite a Quantidade de Clientes da loja: ");
        qtdInform =  (float*) malloc ( tamanhoVetor * sizeof(float));
        printf("A quantidade de Clientes que compraram mais de 1500 :%.2f",percorrendoArray(qtdInform,tamanhoVetor));
	  }


   }while(choice != 3 );

}
////Funcao 2
void minhaStrcat(char *string_destino,char *string_origem){
 int a,b;

    for (a = 0;string_destino[a] != '\0' ; a++);
    for (b = 0;string_origem[b] != '\0' ; a++,b++)
    {
      string_destino[a] = string_origem[b];
    }
      string_destino[a]='\0';
}
//Funcao 3
int valorInteiro(char *frasePersonalizada){
	int number = 0;
	do{
		printf("\n%s ", frasePersonalizada);
		scanf("%i", &number);
		if (number < 0 || number > 30){
			printf("\nO numero tem que ser entre 0 e 30!!");
		}
	}while(number < 0 || number > 30);

	return number;
}
//Funcao 4
float valorReal(float *valor,char *frasePersonalizada){
do{

        printf("\n%s ",frasePersonalizada);
        fflush(stdin);
        scanf("%f", valor);

        if (*valor <= 0){
            printf("\nPor favor Digite um valor Positivo!!!.");
        }
    }while(*valor <= 0);
    return *valor;
}

//Funcao 5
float calcularNumeroReal(float valorReal){
    if (valorReal <= 2000) {
    	return valorReal - (valorReal *  0.03);
    } else if (valorReal>2000 && valorReal <=5000) {
        return  valorReal - (valorReal *  0.05);
    }  else if (valorReal>5000 && valorReal <=15000) {
        return  valorReal - (valorReal *  0.10);
    } else {
          return valorReal - (valorReal *  0.15);
    }
}
//Funcao 6
float percorrendoArray(float *vector, int size) {
    int cont= 0;
    for (int i = 1; i <= size; i++) {
      
        *vector = valorReal(vector,"Digite o Quanto você comprou Cliente : ");
        *vector = calcularNumeroReal(*vector);

        // maior salario

		if(*vector>1500){
		  cont++;
		}
    }
    return cont;
}


