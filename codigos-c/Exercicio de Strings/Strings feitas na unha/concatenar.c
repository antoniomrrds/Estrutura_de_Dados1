#include<stdio.h>
#include<string.h>


char *concatenar(char *s1, char *s2) {
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i);
    for (j = 0; s2[j] != '\0'; ++j, ++i) {
        s1[i] = s2[j];
    }
//    s1[i] = '\0';
    return s1;
}


int main() {

    char str1[] = "abc";
    char str2[] = "defg";
    concatenar(str1, "anrsdf");

   printf("Resultado : %s",str1);



    return (0);
}

