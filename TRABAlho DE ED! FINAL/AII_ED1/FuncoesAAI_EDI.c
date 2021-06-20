
#include "Biblioteca.h"

void menu(){
	setlocale(LC_ALL, "Portuguese");
    char choice;
    int cod;
    char card;
    client *FirstClient =NULL;
    dependent *searchDep =NULL;
    client *search = NULL;
    client *anterior = NULL; 
    dependent *dadosDep = NULL;
   
    do{

    printf("\nA - Inserir\nB - Excluir\nC - Relatórios\nD - Finalizar\n");
    printf("Faça um escolha : ");

    scanf(" %c", &choice);
    choice = toupper(choice);
    if(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D'){
       printf("!!! Opss ERROU !!!");
    }
    
   
       if (choice == 'A'){
        do{
            printf("\n1 - Efetuar inclusão de cliente.\n"
                      "2 - Efetuar inclusão de dependente.\n");
            printf("Faça um escolha : ");

            scanf(" %c", &choice);
            choice = toupper(choice);
            
            
            if(choice != '1' && choice != '2'){
                printf("\n!!! Opss ERROU !!!");
            } else if(choice == '1'){
             
             FirstClient = inserirInicio(FirstClient);
		    
         }else {
                cod = searchCode("Digite o codigo do cliente a ser Procurado : ");
                search = searching(FirstClient, cod);
                if (!search) { //if (busca == NULL) {
                    printf("\nRegistro não encontrado."); 
                }else{
                    if(search->qtdDependentes <CONST){
                        if(search->qtdDependentes == 0){
                            search->dadosDep = inserirFim(&dadosDep,search,1);
                            search ->qtdDependentes++;
                        }else{
                          search->dadosDep = inserirFim(&dadosDep,search,2);
                          search->qtdDependentes++;
                        }
                    }
                     
                }
         }
        }while(choice != '1' && choice != '2');
        
       }
    
    else if(choice == 'B'){
        do{
            printf("\n1 - Efetuar exclusão de cliente.\n"
                   "2 - Efetuar exclusão de dependente.\n");
            printf("Faça um escolha : ");

            scanf(" %c", &choice);
            choice = toupper(choice);

            if(choice != '1' && choice != '2'){
                printf("\n!!! Opss ERROU !!!");
            }else if(choice == '1'){
                cod = searchCode("Digite o codigo do cliente a ser Procurado : ");
                search = searching(FirstClient, cod);
                if (!search) { 
                    printf("\nRegistro não encontrado."); 
                }else{
                    remove_lista_inicio(search,anterior,&FirstClient);
                }    
            }else{
                cod = searchCode("Digite o codigo do cliente a ser Procurado : ");
                search = searching(FirstClient, cod);
                if (!search) { //if (busca == NULL) {
                    printf("\nRegistro não encontrado."); 
                }else{
                    cod = searchCode("Digite o codigo do dependente a ser Procurado : ");
                    searchDep = searchingDep(search->dadosDep, cod);
                    if (!searchDep) { //if (busca == NULL) {
                       printf("\nRegistro não encontrado."); 
                    }else{
                        remover(searchDep,&search->dadosDep);
                        search->qtdDependentes--;
                    }   
                }
            }
        
            
        }while(choice != '1' && choice != '2');
    }
    else if(choice == 'C'){
        do{
            printf("\n1 - Listar todos os dados dos clientes cadastrados e exibir média dos limites.\n"
                    "2 - Listar todos os dados de um cliente por código.\n"
                    "3 - Listar clientes por tipo de cartão.\n");
            printf("Digite sua opção: ");

            scanf(" %c", &choice);
            choice = toupper(choice);

            if(choice != '1' && choice != '2' && choice != '3'){
                printf("\n!!!Opss ERROU !!!");
            }else if(choice == '1'){
                relatorio(FirstClient);
                printf("A média Do limites e :%.2f",sumLimit(FirstClient));
            }else if(choice =='2'){
                 cod = searchCode("Digite o codigo do cliente a ser Procurado : ");
                 search = searching(FirstClient, cod);
                if (!search) { //if (busca == NULL) {
                    printf("\nRegistro não encontrado."); 
                }else{
                   relatorioPorCodigo(search);
                }
            }else{
               card = typeCard();
               search = searchingCard(FirstClient,card);
               if (!search) { //if (busca == NULL) {
                    printf("\nRegistro não encontrado."); 
               }else{
                    relatorioTypeCard(search);
               }
            }   
         
         }while(choice != '1' && choice != '2' && choice != '3');

           
    }
    
}while(choice != 'D');

}
void cadastrarNome(char *nome, char *frasePersonalizada){
	do {
        printf("\n%s " ,frasePersonalizada);
        fflush(stdin);
        scanf(" %[^\n]", nome);
        
        if (strlen(nome) == 0) {
            printf("\nDigite o nome corretamente.");
        }
    } while (strlen(nome) == 0);
	
}

char cadastrarNascimento(){

 struct tm *data_hora_atual; 
  
   
  //variÃ¡vel do tipo time_t para armazenar o tempo em segundos  
  time_t segundos;
  
  //obtendo o tempo em segundos  
  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a funÃ§Ã£o localtime  
  data_hora_atual = localtime(&segundos);  
    
    int idade,anoAtual=data_hora_atual->tm_year+1900;
    int ano;

do{

printf("\nInforme o ano de nascimento: ");
fflush(stdin);
scanf(" %i", &ano);

 idade = (anoAtual - ano);
 if(idade > HIGHER||idade <BOTTOM ){
     printf("\nPor favor digite um ano valido sua idade tem que ser maior que 0 e menor que 101 !!!\n");
     
 }


}while(idade > HIGHER||idade <BOTTOM );
 return idade;
 
    
}

void cadastrarLimite(float *limite,int *idade){
    if(*idade <= 40 ){
        *limite = 10000; 
    }else if(*idade <= 60){
        *limite = 15000;
    }else if(*idade <= 75 ){
        *limite = 5000;
    }else{
        *limite = 2500;
    }
    
}
char cadastrarTipo(float *limite){
    char tipo;
    do{
      printf("\nDigite U - universitario");
      printf("\nDigite N - nacional");
      printf("\nDigite I - Internacional : ");
      printf("\nDigite o tipo de cartão: ");
      fflush(stdin);
      scanf(" %c", &tipo);
      tipo = toupper(tipo);
      if(tipo != 'U' &&  tipo != 'N'&& tipo != 'I'){
          printf("\nDigite o tipo valido !!!\n");
      }
      if(tipo == 'N'){
          *limite += (*limite * 0.05); 
      }else if(tipo == 'I'){
          *limite += (*limite * 0.20);
      }
     
      
    }while(tipo != 'U' &&  tipo != 'N'&& tipo != 'I');
}


char typeCard(){
    char tipo;
    do{
      printf("\nDigite U - universitario");
      printf("\nDigite N - nacional");
      printf("\nDigite I - Internacional : ");
      printf("\nDigite o tipo de cartão: ");
      fflush(stdin);
      scanf(" %c", &tipo);
      tipo = toupper(tipo);
      if(tipo != 'U' &&  tipo != 'N'&& tipo != 'I'){
          printf("\nDigite o tipo valido !!!\n");
      }
  
    }while(tipo != 'U' &&  tipo != 'N'&& tipo != 'I');
}




void cadastrarTipoDependente(char *tipoDependente){
     
    do{
      printf("\nDigite C - Cônjugue");
      printf("\nDigite F - Filho");
      printf("\nDigite E - Enteado");
      printf("\nDigite o tipo de dependente: ");
      fflush(stdin);
      scanf(" %c", tipoDependente);
      *tipoDependente = toupper(*tipoDependente);
      if(*tipoDependente != 'C' &&  *tipoDependente != 'F'&& *tipoDependente != 'E'){
          printf("\nDigite um  tipo valido !!!\n");
      }
 
      
    }while(*tipoDependente != 'C' &&  *tipoDependente != 'F'&& *tipoDependente != 'E');
}
    
void cadastrarQuantidadeDependente(client *cliente){
  
    do{
    printf("\nDigite a quantidade de dependentes do cliente %s :",cliente->nome);
    scanf("%i", &cliente->qtdDependentes);
    if(cliente->qtdDependentes < 0 || cliente->qtdDependentes > CONST ){
        ("\nDigite a quantidade de dependentes menor ou igual a 2\n");
    }

    }while(cliente->qtdDependentes < 0 || cliente->qtdDependentes > CONST );
   
}    


client* inserirInicio(client *inicioLista){
    //Criar o novo espaço de memória
    client *new = (client*) malloc (sizeof(client));
    dependent*dadosDep =NULL;
    
    
    cadastrarNome(new->nome,"Digite seu Nome Cliente: "); 
    printf("O seu codigo é: %i",new->codigo = RANDOM(1000));
    new->idade = cadastrarNascimento();
    cadastrarLimite(&new->limEmprestimo,&new->idade); 
    new-> tipoCartao = cadastrarTipo(&new->limEmprestimo);
    cadastrarQuantidadeDependente(new);

        for(int y = 0; y< new->qtdDependentes; y++){
            int x = y+1;
            new->dadosDep = inserirFim(&dadosDep,new,x); 
            
        }
    
    
    new -> next = inicioLista;
    
    return new;
}


dependent* inserirFim(dependent **lastlist,client *cliente,int y){
	//Alocar o espaço de memória
	dependent *new = (dependent*) malloc (sizeof(dependent));
	//Preenchimento dos dados básicos do novo registro. 
	
	  cadastrarNome(new->nome,"Digite o nome do Dependente: ");
	   printf("\nO Codigo do Dependente é %i:",new->codigo = NUMSEQ(cliente->codigo,y));
	   new->idade = cadastrarNascimento();
	   cadastrarTipoDependente(&new->tipoDependente);
	
	//Ponteiros	
	new->next = NULL; //Depois do new não tem ninguém. 
	
	new->previous = (*lastlist);
	
	if(*lastlist != NULL){
       (*lastlist)->next = new;	    
	}
	(*lastlist) = new;
	
	 
	return new;
	
	
}
//funcao buscar cliente por codigo
int searchCode(char *frasePersonalizada){
    int value;
    do{
        printf("\n%s " ,frasePersonalizada);
        fflush(stdin);
        scanf("%i", &value);
        if (value < 0){
            printf("\nInválido.");
        }
    } while (value < 0);
    return value;
}
//Funcao para procurar cliente
client* searching(client *inicioLista, int cod){
    if (!inicioLista) {
        return NULL;
    } else if (inicioLista->codigo == cod){
        return inicioLista;
    } else {
        return searching(inicioLista->next, cod);
    }
}

//Procurando cartão

client* searchingCard(client *inicioLista, char card){
    if (!inicioLista) {
        return NULL;
    } else if (inicioLista->tipoCartao == card){
        return inicioLista;
    } else {
        return searching(inicioLista->next, card);
    }
}


dependent* searchingDep(dependent *inicioLista, int cod){
    if (!inicioLista) {
        return NULL;
    } else if (inicioLista->codigo == cod){
        return inicioLista;
    } else {
        return searchingDep(inicioLista->next, cod);
    }
}

void remove_lista_inicio(client *search,client *anterior,client **inicioLista){

    if(anterior == NULL) {
        (*inicioLista) = (*inicioLista)->next ;
      
    } else {
        anterior->next = search->next;
    }
    free(search); //Exclui o registro. 
    printf("Cliente excluido com sucesso !!!");

}


void remover(dependent *excluir, dependent **ultimoRegistro) {
   
   
   if(excluir->next == NULL && excluir->previous != NULL){
       (*ultimoRegistro) = excluir->previous;
       excluir->previous->next = NULL;
   }else if(excluir->previous == NULL){
       excluir->next->previous == NULL;
   }else{
       (*ultimoRegistro) == NULL;
   }
   
   
    free(excluir); //Exclui efetivamente o registro solicitado. 
}

void relatorio(client *lista) {
    if (lista != NULL) { //Caso recursivo. 
    if(lista->qtdDependentes == 0){
         printf("\n===================Relatorio==================\n");
         printf("\n     Nome do Cliente                     :%s\n"
                "\n     Codigo do Cliente                   :%i\n"
                "\n     idade de dependente                 :%i\n"
                "\n     Tipo do cartao do Cliente           :%c\n"
                "\n     Limite do Cliente                   :R$ %.2f\n"
                "\n     Quantidade de dependente do Cliente :%i\n",
				lista->nome, lista->codigo, lista->idade,lista->tipoCartao,lista->limEmprestimo,lista->qtdDependentes);
				
    }else{
       
        printf("\n===================Relatorio==================\n");
        printf("\n     Nome do Cliente                     :%s\n"
               "\n     Codigo do Cliente                   :%i\n"
               "\n     idade de dependente                 :%i\n"
               "\n     Tipo do cartao do Cliente           :%c\n"
               "\n     Limite do Cliente                   :R$ %.2f\n"
               "\n     Quantidade de dependente do Cliente :%i\n",
				lista->nome, lista->codigo, lista->idade,lista->tipoCartao,lista->limEmprestimo,lista->qtdDependentes);
				               if(lista->qtdDependentes == 1){
				               printf("\n===================Dependente==================\n");   
                               printf("\n     Nome do Dependente     :%s\n"
                                      "\n     Codigo do Dependente   :%i\n"
                                      "\n     idade de Dependente    :%i\n"
                                      "\n     Tipo do  Dependente    :%c\n",
				                      lista->dadosDep->nome,lista->dadosDep->codigo,lista->dadosDep->idade,lista->dadosDep->tipoDependente);
				                      
				                      
				               }else{
				                   
				                     printf("\n===================Dependente1==================\n");   
                                     printf("\n     Nome do Dependente     :%s\n"
                                      "\n     Codigo do Dependente   :%i\n"
                                      "\n     idade de Dependente    :%i\n"
                                      "\n     Tipo do  Dependente    :%c\n",
				                
				                   lista->dadosDep->previous->nome,lista->dadosDep->previous->codigo,lista->dadosDep->previous->idade,lista->dadosDep->previous->tipoDependente);
				                   
				                    printf("\n===================Dependente2==================\n");   
                                    printf("\n     Nome do Dependente     :%s\n"
                                           "\n     Codigo do Dependente   :%i\n"
                                           "\n     idade de Dependente    :%i\n"
                                           "\n     Tipo do  Dependente    :%c\n",
				                           lista->dadosDep->nome,lista->dadosDep->codigo,lista->dadosDep->idade,lista->dadosDep->tipoDependente);
				                   
				               }
    }	
    
    
	
        relatorio(lista->next);
    }
    
    
}

float sumLimit(client *FirstClient){
    
    float sumLimite = 0;
    int cont = 0;
    while(FirstClient != NULL){
        sumLimite += FirstClient->limEmprestimo;
        FirstClient=FirstClient->next;
        cont++;
    }
        return sumLimite/cont;
    
    
}


void relatorioPorCodigo(client *search){
     if (search != NULL) { //Caso recursivo. 
     if(search->qtdDependentes == 0){
         printf("\n===================Relatorio==================\n");
         printf("\n     Nome do Cliente                     :%s\n"
                "\n     Codigo do Cliente                   :%i\n"
                "\n     idade de dependente                 :%i\n"
                "\n     Tipo do cartao do Cliente           :%c\n"
                "\n     Limite do Cliente                   :R$ %.2f\n"
                "\n     Quantidade de dependente do Cliente :%i\n",
				search->nome, search->codigo, search->idade,search->tipoCartao,search->limEmprestimo,search->qtdDependentes);
				
    }else{
       
        printf("\n===================Relatorio==================\n");
        printf("\n     Nome do Cliente                     :%s\n"
               "\n     Codigo do Cliente                   :%i\n"
               "\n     idade de dependente                 :%i\n"
               "\n     Tipo do cartao do Cliente           :%c\n"
               "\n     Limite do Cliente                   :R$ %.2f\n"
               "\n     Quantidade de dependente do Cliente :%i\n",
				search->nome, search->codigo, search->idade,search->tipoCartao,search->limEmprestimo,search->qtdDependentes);
				               if(search->qtdDependentes == 1){
				               printf("\n===================Dependente==================\n");   
                               printf("\n     Nome do Dependente     :%s\n"
                                      "\n     Codigo do Dependente   :%i\n"
                                      "\n     idade de Dependente    :%i\n"
                                      "\n     Tipo do  Dependente    :%c\n",
				                         search->dadosDep->nome,search->dadosDep->codigo,search->dadosDep->idade,search->dadosDep->tipoDependente);
				                      
				                      
				               }else{
				                   
				                     printf("\n===================Dependente1==================\n");   
                                     printf("\n     Nome do Dependente     :%s\n"
                                            "\n     Codigo do Dependente   :%i\n"
                                            "\n     idade de Dependente    :%i\n"
                                            "\n     Tipo do  Dependente    :%c\n",
				                
				                           search->dadosDep->previous->nome,search->dadosDep->previous->codigo,search->dadosDep->previous->idade,search->dadosDep->previous->tipoDependente);
				                   
				                    printf("\n===================Dependente2==================\n");   
                                    printf("\n     Nome do Dependente     :%s\n"
                                           "\n     Codigo do Dependente   :%i\n"
                                           "\n     idade de Dependente    :%i\n"
                                           "\n     Tipo do  Dependente    :%c\n",
				                           search->dadosDep->nome,search->dadosDep->codigo,search->dadosDep->idade,search->dadosDep->tipoDependente);
				                   
				               }
    }	
    
    
	
        relatorioPorCodigo(search->next);
    }
    
}

void relatorioTypeCard(client *search){
     if (search != NULL) { //Caso recursivo. 
     if(search->qtdDependentes == 0){
         printf("\n===================Relatorio==================\n");
         printf("\n     Nome do Cliente                     :%s\n"
                "\n     Codigo do Cliente                   :%i\n"
                "\n     idade de dependente                 :%i\n"
                "\n     Tipo do cartao do Cliente           :%c\n"
                "\n     Limite do Cliente                   :R$ %.2f\n"
                "\n     Quantidade de dependente do Cliente :%i\n",
				search->nome, search->codigo, search->idade,search->tipoCartao,search->limEmprestimo,search->qtdDependentes);
				
    }else{
       
        printf("\n===================Relatorio==================\n");
        printf("\n     Nome do Cliente                     :%s\n"
               "\n     Codigo do Cliente                   :%i\n"
               "\n     idade de dependente                 :%i\n"
               "\n     Tipo do cartao do Cliente           :%c\n"
               "\n     Limite do Cliente                   :R$ %.2f\n"
               "\n     Quantidade de dependente do Cliente :%i\n",
				search->nome, search->codigo, search->idade,search->tipoCartao,search->limEmprestimo,search->qtdDependentes);
				               if(search->qtdDependentes == 1){
				               printf("\n===================Dependente==================\n");   
                               printf("\n     Nome do Dependente     :%s\n"
                                      "\n     Codigo do Dependente   :%i\n"
                                      "\n     idade de Dependente    :%i\n"
                                      "\n     Tipo do  Dependente    :%c\n",
				                         search->dadosDep->nome,search->dadosDep->codigo,search->dadosDep->idade,search->dadosDep->tipoDependente);
				                      
				                      
				               }else{
				                   
				                     printf("\n===================Dependente1==================\n");   
                                     printf("\n     Nome do Dependente     :%s\n"
                                            "\n     Codigo do Dependente   :%i\n"
                                            "\n     idade de Dependente    :%i\n"
                                            "\n     Tipo do  Dependente    :%c\n",
				                
				                           search->dadosDep->previous->nome,search->dadosDep->previous->codigo,search->dadosDep->previous->idade,search->dadosDep->previous->tipoDependente);
				                   
				                    printf("\n===================Dependente2==================\n");   
                                    printf("\n     Nome do Dependente     :%s\n"
                                           "\n     Codigo do Dependente   :%i\n"
                                           "\n     idade de Dependente    :%i\n"
                                           "\n     Tipo do  Dependente    :%c\n",
				                           search->dadosDep->nome,search->dadosDep->codigo,search->dadosDep->idade,search->dadosDep->tipoDependente);
				                   
				               }
    }	
    
    
	
        relatorioPorCodigo(search->next);
    }
    
}

