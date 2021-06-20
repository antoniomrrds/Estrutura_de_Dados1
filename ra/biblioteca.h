#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//MACROS
//q3
#define RANDOM rand() %500
//q4
#define MAXCADASTRO 3
//q5
#define MULT(a,b) ((a*100)+b)


typedef struct dependentes dependente;
struct dependentes{
    char nome[50];
    int codigoDependente;
    int idade;
};

typedef struct funcionarios funcionario;
struct funcionarios{
    char nome[50];
    int codigo;
    float salario;
    int numDependentes;
    dependente dadosDependentes[3];
    
};

void menu(void);
funcionario*alocarVetorFuncionario(int qtde);
void cadastrarNome(char *nome, char *frasePersonalizada);
void cadastrarQuantidade(int *quantidadeSolicitada, int valorMaximoPermitido);
dependente*alocarVetorDependente(int qtde);
void solicitarSalario(float *salario);
void imprimirResultado(int qtde, funcionario *func);


