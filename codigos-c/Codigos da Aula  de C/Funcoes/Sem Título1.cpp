#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>
int main()
{

    setlocale(LC_ALL, "Portuguese");
    char choice;
    int number, counter;
    float result;
    do
    {
        printf("\nDigite uma opcao : "
               "\n A = série A"
               "\n B = série B"
               "\n C = série C"
               "\n D = série D = SAIR : ");
        //limpeza de buffer = fflush(stdin);
        //limpeza de buffer = espaço tambem limpa buffer;
        //  <ctype.h> = biblioteca de letras maiusculas
        //  fflush(stdin);
        scanf(" %c", &choice);
        choice = toupper(choice);

        if (choice == 'D')
        {
            printf("\nObrigado por usar o Programa Volte  Sempre !!! ");
        }
        else if (choice == 'A' || choice == 'B' || choice == 'C')
        {

            do
            {
                printf("\nDigite a Quantidade de termos da Série %c que deseja calcular : ", choice);
                scanf(" %i", &number);
                if (number <= 0)
                {
                    printf("\nvalor Inválido digite números acima de 0 !!!");
                }
            } while (number <= 0);
            result = 0;
            counter = 1;

            switch (choice)
            {
            case 'A':
                while (counter <= number)
                {

                    result += (counter + (counter - 1)) / pow(counter, 2);
                    counter++;
                }
                printf("\n A Soma da série %c até o número %i: %.2f", choice, number, result);
                break;
            case 'B':

                do
                {
                    result += pow(counter, 3) / pow(10, (counter - 1));
                    counter++;
                } while (counter <= number);
                printf("\n A Soma da série %c até o número %i: %.2f", choice, number, result);
                break;
            case 'C':

                for (counter; counter <= number; counter++)
                {
                    result += (float)counter / (3 * (2 * counter));
                
                }
                printf("\n A Soma da série %c até o número %i: %f", choice, number, result);
                break;
            }
        }
        else
        {
            printf("\nOpcão Inválida !!!");
        }

    } while (choice != 'D');
    return 0;
}
