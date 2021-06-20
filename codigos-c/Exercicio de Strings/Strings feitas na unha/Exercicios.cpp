#include <stdio.h>
#include <string.h>//necess?rio para strlen
#include <conio.h>
int minhastrlen(const char *variavel_origem);
int main (void)
{
  int tamanho;
  int tamanho2;
  char str[6] = "Curso";
  char str2[6] = "bla";

   tamanho = strlen(str);
   tamanho2 = minhastrlen(str2);


  printf("O tamanho da string %s vale %d\n", str, tamanho);
  printf("O tamanho da string %s vale %d\n", str2, tamanho2);

  getch();
  return 0;
}

int minhastrlen(const  char *variavel_origem){
  int i ;
  for (i = 0;variavel_origem[i] != '\0'; ++i);
  return i;

}
