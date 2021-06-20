
//TAD
//Struct
typedef struct dependentes dependent;
struct dependentes {
	char nome[40];
	int codigo;
	int idade;
};

typedef struct funcionarios employee; 
struct funcionarios{
	char nome[40];
	int codigo;
	double Salario;
	int qtdDependentes;
	dependent *dep;
};



//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h> 
#include <string.h>
//Macros e constantes
#define RANDOM rand() % 500
#define CONST 3
#define NUMSEQ(a, b) ((a) *100 + (b))

//prototipos

void menu ();
void cadastrarNome(char *nome, char *frasePersonalizada);
employee* alocarVetorFuncionario(int qtde);
void cadastrarQuantidade(int *quantidadeSolicitada, int valorMaximoPermitido,char *frasePersonalizada);
void cadastrarSalario(double *salary);
dependent* alocarVetorDependente(int qtde);
void imprimirTodosFuncionarios(int qtdeFuncionario, employee *EmployeeCompany);



