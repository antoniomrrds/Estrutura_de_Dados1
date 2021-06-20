#include <stdio.h>
#include <string.h> //necess�rio para strcpy
#include <locale.h>

//Prototipo
char *minhaStrcpy( char *destiny ,char *origin);
int main (void)
{
  setlocale(LC_ALL, "Portuguese");
  char nome[16];
  char nome2[16];

  strcpy(nome, "Fulano de Tal");
//  concatenar(nome2, "antonio Marcos");
  minhaStrcpy(nome2, "antonio Marcos");
  //strcpy(string_destino, string_origem);
  //strcpy(string_destino, string_origem);
  //note que a string de destino � nome
  //a string de origem � "Fulano de Tal"

  printf("Nome = %s \n" , nome);
  printf("Nome = %s \n", nome2);


  return 0;
}

char *minhaStrcpy( char *destiny ,char *origin){
    int a ;
    for(a =0;origin[a] != '\0';a++){

    destiny[a]=  origin[a];


   }
     destiny[a]='\0';
    return destiny;
}


