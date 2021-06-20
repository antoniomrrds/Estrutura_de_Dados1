//Biblioteca com fun��es para lista duplamente encadeada. 
//Bibliotecas utilizadas. 
#include <stdlib.h>
#include <stdio.h>

//Macros e constantes
#define RANDOMICO(x) rand() % (x)


//Estrutura
typedef struct dupla dadosDupla;
struct dupla{
	//Dados b�sicos
	int codigo;
	
	//Ponteiros
	dadosDupla *anterior;
	dadosDupla *proximo;
};

//Prot�tipo
dadosDupla* inserirInicio(dadosDupla *inicioLista);
void imprimirLista(dadosDupla *lista);
dadosDupla* inserirFim(dadosDupla *inicioLista);
void menu();
void inserirFimUltimo(dadosDupla **ultimoRegistro);
dadosDupla* funcao(dadosDupla *inicioLista, int cod);
dadosDupla* buscar(dadosDupla *inicioLista, int cod);
int procurarCodigo();
void remover(dadosDupla *excluir, dadosDupla **inicioLista, dadosDupla **ultimoRegistro);
