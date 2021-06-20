//Fun��es para manipula��o de lista dupla. 
#include "bibliotecaListaDupla.h"
#include <ctype.h>

//Fun��es
void menu(){
    char op;
    int cod;
    dadosDupla *listaDupla = NULL; //Armazena o in�cio da lista dupla. 
    dadosDupla *ultimo = NULL; //Armazena o �ltimo registro da lista dupla. 
    dadosDupla *busca = NULL; //Armazena o registro procurado. 
    
    do{
        printf("\nA - Inserir pelo in�cio"
                "\nB - Inserir pelo Fim"
                "\nC - Pesquisar"
                "\nD - Remover"
                "\nE - Imprimir"
                "\nF - Finalizar"
                "\nDigite sua op��o: ");
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
                    printf("\nRegistro n�o encontrado."); 
                } else {
                    printf("\nAnterior %p %i - %p %i - Pr�ximo %p %i", 
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
                    printf("\nRegistro n�o encontrado."); 
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
                printf("\nOp��o inv�lida. Digite novamente. ");
                break;
        }

    } while (op != 'F');        
}

int procurarCodigo(){
    int valor;
    do{
        printf("\nDigite o c�digo a ser procurado: ");
        scanf("%i", &valor);
        if (valor < 0){
            printf("\nInv�lido.");
        }
    } while (valor < 0);
    return valor;
}

//Exclus�o de registros. 
void remover(dadosDupla *excluir, dadosDupla **inicioLista, dadosDupla **ultimoRegistro) {
    //Se for o primeiro da lista. 
    if (excluir->anterior == NULL) { //if (!excluir->anterior) {
        (*inicioLista) = (*inicioLista)->proximo; //Altero o primeiro para o segundo. 
        if ((*inicioLista) != NULL) { //Existe registro v�lido. 
            (*inicioLista)->anterior = NULL; //Coloca null no anterior, pois antes n�o vem ningu�m. 
        }
    } else { //N�o � o primeiro. 
        excluir->anterior->proximo = excluir->proximo;
        if (excluir->proximo != NULL) {
            excluir->proximo->anterior = excluir->anterior;
        }    
    }
    
    //Verifica se o registro a ser exclu�do � o �ltimo. 
    if ((*ultimoRegistro)->codigo == excluir->codigo) {
        (*ultimoRegistro) = excluir->anterior; //O �ltimo registro passar� a ser o anterior a ele. 
    }
    
    //Retirar o registro da mem�ria. 
    free(excluir); //Exclui efetivamente o registro solicitado. 
}

//Inser��o de registros. 
//Inser��o pelo in�cio
dadosDupla* inserirInicio(dadosDupla *inicioLista) {
	//Alocar o espa�o de mem�ria
	dadosDupla *novo = (dadosDupla*) malloc (sizeof(dadosDupla));
	
	//Preenchimento dos dados b�sicos do novo registro. 
	novo->codigo = RANDOMICO(1000);
	
	//Ponteiros
	novo->anterior = NULL; //Se ele � o primeiro, antes dele n�o tem ningu�m. 
	novo->proximo = inicioLista; //Depois do novo a lista ser� inserida.
	if (inicioLista != NULL) { //S� conecta se houver registro. 
		inicioLista->anterior = novo; //Aponta o primeiro registro para o novo.   
	}
	return novo; //Atualiza o in�cio da lista fora deste escopo. 	
}

//Inser��o pelo fim - Procurando o �ltimo registro.  
dadosDupla* inserirFim(dadosDupla *inicioLista){
	//Alocar o espa�o de mem�ria
	dadosDupla *novo = (dadosDupla*) malloc (sizeof(dadosDupla));
	
	//Preenchimento dos dados b�sicos do novo registro. 
	novo->codigo = RANDOMICO(1000);
	
	//Ponteiros	
	novo->proximo = NULL; //Depois do novo n�o tem ningu�m. 
	if (inicioLista == NULL) { //Este � o primeiro registro a ser criado. 
		novo->anterior = NULL;
		return novo;	
	} else { //J� existia registro na lista. 
		dadosDupla *listaTmp = inicioLista; //Cria a lista tempor�ria para deslocar entre os ponteiros. 
		while (listaTmp->proximo != NULL) { //Procura o �ltimo registro, aquele que aponta para NULL
			listaTmp = listaTmp->proximo;
		}
		listaTmp->proximo = novo; //Liga o �ltimo ao novo.
		novo->anterior = listaTmp; //Liga o novo ao �ltimo. 
		
		return inicioLista;	//Preciso retornar o mesmo registro que voc� me enviou. 	
	}
	
}

//Inser��o pelo fim - Procurando o �ltimo registro.  
void inserirFimUltimo(dadosDupla **ultimoRegistro){
	//Alocar o espa�o de mem�ria
	dadosDupla *novo = (dadosDupla*) malloc (sizeof(dadosDupla));
	
	//Preenchimento dos dados b�sicos do novo registro. 
	novo->codigo = RANDOMICO(1000);
	
	//Ponteiros
	novo->proximo = NULL; //Depois do novo n�o tem ningu�m. 
	novo->anterior = (*ultimoRegistro); //Antes do novo vir� o registro que � considerado atualmente como �ltimo. 
    if (*ultimoRegistro != NULL) { //S� conecta se houver registro v�lido. 
        (*ultimoRegistro)->proximo = novo;	
    }
    (*ultimoRegistro) = novo;
}

//Essa fun��o busca um registro procurado. 
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

//Impress�o dos registros. 
//Imprimir os elementos da pilha 
void imprimirLista(dadosDupla *lista) {
    if (lista != NULL) { //Caso recursivo. 
        printf("\nAnterior %p - %p - %i - Pr�ximo %p", 
				lista->anterior, lista, lista->codigo, lista->proximo);
        imprimirLista(lista->proximo);
    }
}
