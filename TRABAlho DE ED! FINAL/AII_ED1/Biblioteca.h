//Struct

typedef struct dependentes dependent;
struct dependentes {
	char nome[50];
	int codigo;
	int idade;
	char tipoDependente;
	dependent *next;
	dependent *previous; 
};



typedef struct cliente client; 
struct cliente{
	char nome[50];
	int codigo;
	int idade;
	float limEmprestimo;
	char tipoCartao;
	int qtdDependentes;
	dependent *dadosDep;
	client *next;
};



//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h> 
#include <string.h>
#include <time.h>
//Macros e constantes
#define RANDOM(x) rand() % (x)
#define HIGHER 100
#define BOTTOM 1
#define CONST 2
#define NUMSEQ(a, b) ((a) * 100 + (b))

//prototipos

void menu ();
void cadastrarNome(char *nome, char *frasePersonalizada);
char cadastrarNascimento(); 
void cadastrarLimite(float *limite,int *idade);
char cadastrarTipo(float *limite);
void cadastrarTipoDependente(char *tipoDependente);
void cadastrarQuantidadeDependente(client *cliente);

client* inserirInicio(client *inicioLista);
dependent* inserirFim(dependent **lastlist,client *cliente,int y);

//buscar pelo codigo
int searchCode(char *frasePersonalizada);
client* searching(client *inicioLista, int cod);

//remocao pelo inicio

void remove_lista_inicio(client *search,client *anterior,client **inicioLista);

void remover(dependent *excluir, dependent **ultimoRegistro);

dependent* searchingDep(dependent *inicioLista, int cod);

float sumLimit(client *FirstClient);

client* searchingCard(client *inicioLista, char card);

//tipo de cartao 
char typeCard();
void relatorioTypeCard(client *search);

//Relatorio de dependentes 
void relatorio(client *lista);
void relatorioPorCodigo(client *search);