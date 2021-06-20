//Biblioteca com funções para lista duplamente encadeada. 
//Bibliotecas utilizadas. 
#include <stdlib.h>
#include <stdio.h>

//Macros e constantes
#define RANDOMICO(x) rand() % (x)


//Estrutura
typedef struct dupla dadosDupla;
struct dupla{
	//Dados básicos
	int codigo;
	
	//Ponteiros
	dadosDupla *anterior;
	dadosDupla *proximo;
};

//Protótipo
dadosDupla* inserirInicio(dadosDupla *inicioLista);
void imprimirLista(dadosDupla *lista);
dadosDupla* inserirFim(dadosDupla *inicioLista);
void menu();
void inserirFimUltimo(dadosDupla **ultimoRegistro);
dadosDupla* funcao(dadosDupla *inicioLista, int cod);
dadosDupla* buscar(dadosDupla *inicioLista, int cod);
int procurarCodigo();
void remover(dadosDupla *excluir, dadosDupla **inicioLista, dadosDupla **ultimoRegistro);
