#include <stdio.h>
#include <string.h>//necessário para strcat
#include <conio.h>

void minhaStrcat(char *string_destino,char *string_origem);

int main (void)
{
   char str[11] = "Curso";
   char str2[11] = "Curso";
   strcat(str, str2);
  //Concatena a string " de C" com o conteúdo da string str
  minhaStrcat(str2, " de C");
  printf("str = %s\n", str);
  printf("str = %s\n", str2);
  //Será exibido curso de C
  
  getch();
  return 0;
}
void minhaStrcat(char *string_destino,char *string_origem){
    int a,b;
    
    for (a = 0;string_destino[a] != '\0' ; a++);
    for (b = 0;string_origem[b] != '\0' ; a++,b++)
    {
      string_destino[a] = string_origem[b];  
    }
      string_destino[a]='\0';
}
