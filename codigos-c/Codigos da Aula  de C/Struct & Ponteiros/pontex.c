#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>
int main()
{
    char letras [] = "PONTEIROS",
        *pontletra = letras;
    printf("%c", *pontletra);
    pontletra++;
    printf("%c", *pontletra);
    pontletra += 4;
    printf("%c", *pontletra);
    (*pontletra) += 5;
    printf("%c", *pontletra);
    pontletra -= 2;
    printf("%c", *pontletra);
//    
//000000000062FE10




    return 0;
}
