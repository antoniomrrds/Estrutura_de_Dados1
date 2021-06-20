#include "bibliotecaListaSimples.h"
#include <ctype.h>

//Fun��es
void menu(){
    char op;
    int cod;
    dadosSimples *listaSimples = NULL; //Armazena o in�cio da lista. 
    dadosSimples *ultimo = NULL; //Armazena o �ltimo da lista. 
    dadosSimples *busca = NULL; //Registro que ser� procurado no c�digo. 
    dadosSimples *registroAnterior = NULL; //Registro que aponta para o atual. 
    
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
                listaSimples = inserirInicio(listaSimples);
                if (ultimo == NULL) {
                    ultimo = listaSimples;
                }
                break;
            case 'B':
                //listaSimples = inserirFim(listaSimples);
                inserirFimUltimo(&ultimo);
                if (listaSimples == NULL) {
                    listaSimples = ultimo;
                }
                break;
            case 'C':
                registroAnterior = NULL;
                cod = procurarCodigo();
                busca = buscarRegistro(&registroAnterior, listaSimples, cod);
                if (busca != NULL) {
                    printf("\nRegistro procurado %p - %i e Anterior %p", 
                            busca, busca->codigo, registroAnterior);
                } else {
                    printf("\nRegistro n�o encontrado.");
                }
                
                break;
            case 'D':
                registroAnterior = NULL;
                cod = procurarCodigo();
                busca = buscarRegistro(&registroAnterior, listaSimples, cod);
                if (busca != NULL) { //Se retornar solicita exclus�o 
                    //chamando a fun��o de exclus�o. 
                    removerElemento(busca, registroAnterior, &listaSimples);
                    if (listaSimples == NULL) {
                    	ultimo = NULL;
					} else if (ultimo->codigo == cod) {
						ultimo = registroAnterior;
					}
                } else { //N�o existe. 
                    printf("\nRegistro n�o encontrado.");
                }
                
                break;
            case 'E':
                imprimirLista(listaSimples);
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

//Fun��o de inser��o pelo in�cio em uma lista simples
dadosSimples* inserirInicio(dadosSimples *inicioLista){
    //Criar o novo espa�o de mem�ria
    dadosSimples *novo = (dadosSimples*) malloc (sizeof(dadosSimples));
    
    //Dados b�sicos do registro que acabou de ser criado. 
    novo->codigo = RANDOM(1000);
    
    //Conectar o novo registro � lista - Rose apontar� para a Izabel
    novo->proximo = inicioLista;    
    
    //Atualizar a lista externamente. 
    return novo;
}

//Fun��o de inser��o pelo fim, procurando o �ltimo. 
dadosSimples* inserirFim (dadosSimples *inicioLista) {
    //Criar o novo espa�o de mem�ria
    dadosSimples *novo = (dadosSimples*) malloc (sizeof(dadosSimples));
    
    //Dados b�sicos do registro que acabou de ser criado. 
    novo->codigo = RANDOM(1000);
    
    //Conectar os ponteiros.
    //Depois do �ltimo n�o vem ningu�m (NULL)
    novo->proximo = NULL;
    
    //Se o registro for o primeiro, passar� a ser o in�cio da lista. 
    if (inicioLista == NULL) {
        return novo; //Atualiza a lista com o novo. 
    } else {
        dadosSimples *tmp = inicioLista;
        while (tmp->proximo != NULL) { //Enquanto o registro apontar para outro, continua a busca. 
            tmp = tmp->proximo; //Vai para o pr�ximo. 
        }
        tmp->proximo = novo; //Aponta o �ltimo para o novo, tornando-o o pen�ltimo. 
        
        return inicioLista; //O in�cio da lista n�o muda. 
    }
}

//Fun��o de inser��o pelo fim, guardando o �ltimo. 
void inserirFimUltimo (dadosSimples **ultimoLista) {
    //Criar o novo espa�o de mem�ria
    dadosSimples *novo = (dadosSimples*) malloc (sizeof(dadosSimples));
    
    //Dados b�sicos do registro que acabou de ser criado. 
    novo->codigo = RANDOM(1000);
    
    //Conectar os ponteiros.
    //Depois do �ltimo n�o vem ningu�m (NULL)
    novo->proximo = NULL;
    
    //Conectar o �ltimo ao novo
    if ((*ultimoLista) != NULL) { //Somente se houver registro no ponteiro �ltimo. 
        (*ultimoLista)->proximo = novo; //Aponta o �ltimo para o novo, tornando-o o pen�ltimo.
    }
    (*ultimoLista) = novo; //Atualiza o ponteiro �ltimo com o novo registro. 
    
}

//Imprimir os elementos da pilha 
void imprimirLista(dadosSimples *lista) {
    if (lista != NULL) { //Caso recursivo. 
        printf("\n%p - %i - %p", lista, lista->codigo, lista->proximo);
        imprimirLista(lista->proximo);
    }
}

//Buscar registro na lista. 
dadosSimples* buscarRegistro(dadosSimples **anterior, dadosSimples *atual, int cod){
    while (atual != NULL) {//Enquanto este ponteiro apontar para algum registro continua. 
        if (atual->codigo == cod) { //Encontrei o registro. 
            return atual;    
        } else { //N�o encontrei o registro. 
            (*anterior) = atual; //Guarda o registro atual como anterior. 
            atual = atual->proximo; //O atual aponta para o pr�ximo, ainda na busca do registro. 
        }
    }   
    return NULL; //Se chegar aqui � porque o registro n�o existe na lista. 
}

//Remover registro da lista. 
void removerElemento(dadosSimples *excluir, dadosSimples *anterior, dadosSimples **inicioLista){
    if (anterior == NULL) { //Estou excluindo o primeiro registro. 
        (*inicioLista) = (*inicioLista)->proximo; //O in�cio da lista passa a ser o pr�ximo do que ser� exclu�do. 
    } else { //Estou excluindo um registro a partir do segundo. 
        anterior->proximo = excluir->proximo;
    }
    free(excluir); //Exclui o registro. 
}

