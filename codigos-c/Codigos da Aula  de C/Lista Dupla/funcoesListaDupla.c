//Funções para manipulação de lista dupla. 
#include "bibliotecaListaDupla.h"
#include <ctype.h>

//Funções
void menu(){
    char op;
    int cod;
    dadosDupla *listaDupla = NULL; //Armazena o início da lista dupla. 
    dadosDupla *ultimo = NULL; //Armazena o último registro da lista dupla. 
    dadosDupla *busca = NULL; //Armazena o registro procurado. 
    
    do{
        printf("\nA - Inserir pelo início"
                "\nB - Inserir pelo Fim"
                "\nC - Pesquisar"
                "\nD - Remover"
                "\nE - Imprimir"
                "\nF - Finalizar"
                "\nDigite sua opção: ");
        scanf(" %c", &op);
        op = toupper(op);
        
        switch (op) {
            case 'A' :
            	listaDupla = inserirInicio(listaDupla);
            	if (ultimo == NULL) {
            	    ultimo = listaDupla;
            	}
                break;
            case 'B':
            	//listaDupla = inserirFim(listaDupla);
            	inserirFimUltimo(&ultimo);
            	if (listaDupla == NULL) {
            	    listaDupla = ultimo; //Armazena o primeiro registro. 
            	}
                break;
            case 'C':
                cod = procurarCodigo();
                //busca = funcao(listaDupla, 383);
                busca = buscar(listaDupla, cod);
                if (busca == NULL) {
                    printf("\nRegistro não encontrado."); 
                } else {
                    printf("\nAnterior %p %i - %p %i - Próximo %p %i", 
                                        busca->anterior, 
                                        ((busca->anterior) ? busca->anterior->codigo: 0), //((busca->anterior != NULL) ? busca->anterior->codigo: 0),
                                        busca, busca->codigo,
                                        busca->proximo, 
                                        ((busca->proximo) ? busca->proximo->codigo: 0)); //((busca->proximo != NULL) ? busca->proximo->codigo: 0));
                }
                break;
            case 'D':
                cod = procurarCodigo();
                busca = buscar(listaDupla, cod);
                if (!busca) { //if (busca == NULL) {
                    printf("\nRegistro não encontrado."); 
                } else {
                    remover(busca, &listaDupla, &ultimo);
                }
                break;
            case 'E':
            	imprimirLista(listaDupla);
                break;
            case 'F':
                printf("\nPrograma finalizado. ");
                break;
            default:
                printf("\nOpção inválida. Digite novamente. ");
                break;
        }

    } while (op != 'F');        
}

int procurarCodigo(){
    int valor;
    do{
        printf("\nDigite o código a ser procurado: ");
        scanf("%i", &valor);
        if (valor < 0){
            printf("\nInválido.");
        }
    } while (valor < 0);
    return valor;
}

//Exclusão de registros. 
void remover(dadosDupla *excluir, dadosDupla **inicioLista, dadosDupla **ultimoRegistro) {
    //Se for o primeiro da lista. 
    if (excluir->anterior == NULL) { //if (!excluir->anterior) {
        (*inicioLista) = (*inicioLista)->proximo; //Altero o primeiro para o segundo. 
        if ((*inicioLista) != NULL) { //Existe registro válido. 
            (*inicioLista)->anterior = NULL; //Coloca null no anterior, pois antes não vem ninguém. 
        }
    } else { //Não é o primeiro. 
        excluir->anterior->proximo = excluir->proximo;
        if (excluir->proximo != NULL) {
            excluir->proximo->anterior = excluir->anterior;
        }    
    }
    
    //Verifica se o registro a ser excluído é o último. 
    if ((*ultimoRegistro)->codigo == excluir->codigo) {
        (*ultimoRegistro) = excluir->anterior; //O último registro passará a ser o anterior a ele. 
    }
    
    //Retirar o registro da memória. 
    free(excluir); //Exclui efetivamente o registro solicitado. 
}

//Inserção de registros. 
//Inserção pelo início
dadosDupla* inserirInicio(dadosDupla *inicioLista) {
	//Alocar o espaço de memória
	dadosDupla *novo = (dadosDupla*) malloc (sizeof(dadosDupla));
	
	//Preenchimento dos dados básicos do novo registro. 
	novo->codigo = RANDOMICO(1000);
	
	//Ponteiros
	novo->anterior = NULL; //Se ele é o primeiro, antes dele não tem ninguém. 
	novo->proximo = inicioLista; //Depois do novo a lista será inserida.
	if (inicioLista != NULL) { //Só conecta se houver registro. 
		inicioLista->anterior = novo; //Aponta o primeiro registro para o novo.   
	}
	return novo; //Atualiza o início da lista fora deste escopo. 	
}

//Inserção pelo fim - Procurando o último registro.  
dadosDupla* inserirFim(dadosDupla *inicioLista){
	//Alocar o espaço de memória
	dadosDupla *novo = (dadosDupla*) malloc (sizeof(dadosDupla));
	
	//Preenchimento dos dados básicos do novo registro. 
	novo->codigo = RANDOMICO(1000);
	
	//Ponteiros	
	novo->proximo = NULL; //Depois do novo não tem ninguém. 
	if (inicioLista == NULL) { //Este é o primeiro registro a ser criado. 
		novo->anterior = NULL;
		return novo;	
	} else { //Já existia registro na lista. 
		dadosDupla *listaTmp = inicioLista; //Cria a lista temporária para deslocar entre os ponteiros. 
		while (listaTmp->proximo != NULL) { //Procura o último registro, aquele que aponta para NULL
			listaTmp = listaTmp->proximo;
		}
		listaTmp->proximo = novo; //Liga o último ao novo.
		novo->anterior = listaTmp; //Liga o novo ao último. 
		
		return inicioLista;	//Preciso retornar o mesmo registro que você me enviou. 	
	}
	
}

//Inserção pelo fim - Procurando o último registro.  
void inserirFimUltimo(dadosDupla **ultimoRegistro){
	//Alocar o espaço de memória
	dadosDupla *novo = (dadosDupla*) malloc (sizeof(dadosDupla));
	
	//Preenchimento dos dados básicos do novo registro. 
	novo->codigo = RANDOMICO(1000);
	
	//Ponteiros
	novo->proximo = NULL; //Depois do novo não tem ninguém. 
	novo->anterior = (*ultimoRegistro); //Antes do novo virá o registro que é considerado atualmente como último. 
    if (*ultimoRegistro != NULL) { //Só conecta se houver registro válido. 
        (*ultimoRegistro)->proximo = novo;	
    }
    (*ultimoRegistro) = novo;
}

//Essa função busca um registro procurado. 
dadosDupla* funcao(dadosDupla *inicioLista, int cod){
    dadosDupla *tmp;
    for (tmp = inicioLista; tmp != NULL; tmp = tmp->proximo) {
        if (tmp->codigo == cod){
            return tmp;
        }
    }
    return NULL;
}

dadosDupla* buscar(dadosDupla *inicioLista, int cod){
    if (!inicioLista) {
        return NULL;
    } else if (inicioLista->codigo == cod){
        return inicioLista;
    } else {
        return buscar(inicioLista->proximo, cod);
    }
}

//Impressão dos registros. 
//Imprimir os elementos da pilha 
void imprimirLista(dadosDupla *lista) {
    if (lista != NULL) { //Caso recursivo. 
        printf("\nAnterior %p - %p - %i - Próximo %p", 
				lista->anterior, lista, lista->codigo, lista->proximo);
        imprimirLista(lista->proximo);
    }
}
