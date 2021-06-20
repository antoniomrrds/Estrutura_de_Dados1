/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
	int i = 32;
	char letra = 'A';
	printf("\n%c - %d", letra, letra); //Char é convertido pelo seu caractere e seu correspondente decimal
	printf("\n%c - %d", i, i); //O contrário também acontece (decimal se transforma em char)
	
	//Strings
	char vetor[30]; //Para ser string, em C, eu finalizo com \0
	char vetorChar[] = {'A', 'B', 'C'}; //Não é string
	
	//Inicialização de strings
	char frase[30] = "Estrutura de Dados I"; //Essa inicialização já incluir \0 ao final da frase. 
	char string[] = "Estrutura"; //Será dimensionada pelo tamanho da frase + \0

	//String de controle para Strings - %s
	printf("\n%s", frase); //Toda a string(vetor) será impressa. 
	printf("\n%c", frase[0]); //Pegando uma pequena parte da string, que é um caractere.
	
	//Comandos de entrada para strings
	printf("\nDigite a frase: ");
	//gets(frase); //Preenche a digitação de uma string. Permite vazamento de memória
	//fgets(frase, 30, stdin);//Preenche a digitação de uma string considerando o tamanho.
	//scanf("%s", frase); //Não colocar & pois o nome de vetor já é seu endereço de memória. Não aceita espaços. 
	scanf("%[^\n]", frase); //A formatação [^\n] aceita espaço na digitação da string. 
	
	//scanf("%c", &letra); //Utiliza-se & para pegar o endereço da variável
	
	printf("\n%s - A frase finaliza aqui. ", frase);
	
	//Funções da biblioteca string.h
	int tamanho = strlen(frase); //strlen conta os caracteres válidos antes do \0
	printf("\n%i", tamanho);
	
	printf("\nUtilizando o strcpy\nVetor - %s - Frase - %s", vetor, frase);
	strcpy(vetor, frase); //A função strcpy copia todo o conteúdo da string frase para dentro da string vetor (substituindo vetor)
	printf("\nVetor - %s - Frase - %s", vetor, frase);
	
	printf("\n\nUtilizando o strncpy\nVetor - %s - Frase - %s", vetor, frase);
	strncpy(vetor, "Agora vamos ver o que acontecerá.", 5); //A função strcpy copia a quantidade de caracteres do conteúdo da string frase para dentro da string vetor (substituindo vetor)
	printf("\nVetor - %s - Frase - %s", vetor, frase);
	
	printf("\n\nUtilizando o strcat\nVetor - %s - Frase - %s", vetor, frase);
	strcat(vetor, "Olá."); //A função strcpy copia a quantidade de caracteres do conteúdo da string frase para dentro da string vetor (substituindo vetor)
	printf("\nVetor - %s - Frase - %s", vetor, frase);
	
	printf("\n\nUtilizando o strcmp");
	printf("\nComparando Amanda e Amor - %i", strcmp("Amanda", "Amor"));
	printf("\nComparando Carlos e Carla - %i", strcmp("Carlos", "Carla"));
	printf("\nComparando Hoje e Hoje - %i", strcmp("Hoje", "Hoje"));
	return 0;
}
