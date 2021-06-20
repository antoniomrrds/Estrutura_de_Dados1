#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char word[60], word2[60];
    printf("\nDigite uma palavra: ");
    scanf(" %[^\n]",word);
    printf("\nDigite uma outra palavra: ");
    scanf(" %[^\n]",word2);
    resultado =word2 +word
    printf("\nword %s e word2 %s",resultado);
    
    //questão 2
	strcat(word, " ");
	strcat(word, word2);
	printf("\nword %s e word2 %s",word,word2);
    return 0;
}
