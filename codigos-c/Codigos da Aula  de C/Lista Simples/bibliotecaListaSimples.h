//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Macros e Constantes
#define RANDOM(x) rand() % (x)


//TAD (structs, enum, unio, etc)
typedef struct simples dadosSimples;
struct simples{
    //Dados básicos
    int codigo;    
    
    //Ponteiros
    dadosSimples *proximo;
};

//Protótipos
void menu();
dadosSimples* inserirInicio(dadosSimples *inicioLista);
void imprimirLista(dadosSimples *lista);
dadosSimples* inserirFim (dadosSimples *inicioLista);
void inserirFimUltimo (dadosSimples **ultimoLista);
dadosSimples* buscarRegistro(dadosSimples **anterior, dadosSimples *atual, int cod);
int procurarCodigo();
void removerElemento(dadosSimples *excluir, dadosSimples *anterior, dadosSimples **inicioLista);
