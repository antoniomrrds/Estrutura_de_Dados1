#include "bibliotecaListaSimples.h"
#include <ctype.h>

//Funções
void menu(){
    char op;
    int cod;
    dadosSimples *listaSimples = NULL; //Armazena o início da lista. 
    dadosSimples *ultimo = NULL; //Armazena o último da lista. 
    dadosSimples *busca = NULL; //Registro que será procurado no código. 
    dadosSimples *registroAnterior = NULL; //Registro que aponta para o atual. 
    
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
                    printf("\nRegistro não encontrado.");
                }
                
                break;
            case 'D':
                registroAnterior = NULL;
                cod = procurarCodigo();
                busca = buscarRegistro(&registroAnterior, listaSimples, cod);
                if (busca != NULL) { //Se retornar solicita exclusão 
                    //chamando a função de exclusão. 
                    removerElemento(busca, registroAnterior, &listaSimples);
                    if (listaSimples == NULL) {
                    	ultimo = NULL;
					} else if (ultimo->codigo == cod) {
						ultimo = registroAnterior;
					}
                } else { //Não existe. 
                    printf("\nRegistro não encontrado.");
                }
                
                break;
            case 'E':
                imprimirLista(listaSimples);
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

//Função de inserção pelo início em uma lista simples
dadosSimples* inserirInicio(dadosSimples *inicioLista){
    //Criar o novo espaço de memória
    dadosSimples *novo = (dadosSimples*) malloc (sizeof(dadosSimples));
    
    //Dados básicos do registro que acabou de ser criado. 
    novo->codigo = RANDOM(1000);
    
    //Conectar o novo registro à lista - Rose apontará para a Izabel
    novo->proximo = inicioLista;    
    
    //Atualizar a lista externamente. 
    return novo;
}

//Função de inserção pelo fim, procurando o último. 
dadosSimples* inserirFim (dadosSimples *inicioLista) {
    //Criar o novo espaço de memória
    dadosSimples *novo = (dadosSimples*) malloc (sizeof(dadosSimples));
    
    //Dados básicos do registro que acabou de ser criado. 
    novo->codigo = RANDOM(1000);
    
    //Conectar os ponteiros.
    //Depois do último não vem ninguém (NULL)
    novo->proximo = NULL;
    
    //Se o registro for o primeiro, passará a ser o início da lista. 
    if (inicioLista == NULL) {
        return novo; //Atualiza a lista com o novo. 
    } else {
        dadosSimples *tmp = inicioLista;
        while (tmp->proximo != NULL) { //Enquanto o registro apontar para outro, continua a busca. 
            tmp = tmp->proximo; //Vai para o próximo. 
        }
        tmp->proximo = novo; //Aponta o último para o novo, tornando-o o penúltimo. 
        
        return inicioLista; //O início da lista não muda. 
    }
}

//Função de inserção pelo fim, guardando o último. 
void inserirFimUltimo (dadosSimples **ultimoLista) {
    //Criar o novo espaço de memória
    dadosSimples *novo = (dadosSimples*) malloc (sizeof(dadosSimples));
    
    //Dados básicos do registro que acabou de ser criado. 
    novo->codigo = RANDOM(1000);
    
    //Conectar os ponteiros.
    //Depois do último não vem ninguém (NULL)
    novo->proximo = NULL;
    
    //Conectar o último ao novo
    if ((*ultimoLista) != NULL) { //Somente se houver registro no ponteiro último. 
        (*ultimoLista)->proximo = novo; //Aponta o último para o novo, tornando-o o penúltimo.
    }
    (*ultimoLista) = novo; //Atualiza o ponteiro último com o novo registro. 
    
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
        } else { //Não encontrei o registro. 
            (*anterior) = atual; //Guarda o registro atual como anterior. 
            atual = atual->proximo; //O atual aponta para o próximo, ainda na busca do registro. 
        }
    }   
    return NULL; //Se chegar aqui é porque o registro não existe na lista. 
}

//Remover registro da lista. 
void removerElemento(dadosSimples *excluir, dadosSimples *anterior, dadosSimples **inicioLista){
    if (anterior == NULL) { //Estou excluindo o primeiro registro. 
        (*inicioLista) = (*inicioLista)->proximo; //O início da lista passa a ser o próximo do que será excluído. 
    } else { //Estou excluindo um registro a partir do segundo. 
        anterior->proximo = excluir->proximo;
    }
    free(excluir); //Exclui o registro. 
}

