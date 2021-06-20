#include "Bibliotecas.h"
	
void menu(){
	
	 setlocale(LC_ALL, "Portuguese");
	
char choice;
int quant,numdep =0;
employee  *employ = NULL;
dependent *depend = NULL;
	
	

do{
	 printf("\n A - Inserir dados Funcionários");
	 printf("\n B - Exibir Informações");
	 printf("\n C - Finalizar");
	 printf("\nSelecione a opção desejada :");
	 fflush(stdin);
	 scanf("%c", &choice);
	 choice = toupper(choice);
	 
	 if(choice =='A'){
	 	do{
		 
	     printf("\nDigite a quantidade de Funcionário : ");
	     fflush(stdin);
	     scanf("%i",&quant);
	     
	     if(quant<0){
	     	printf("\nDigite o número Positivo !!!");
		 }
	 }while(quant<0);
	     employ = alocarVetorFuncionario(quant);
	     for(int i = 1 ; i <= quant;i++  ){
	     	cadastrarNome(employ.nome,"\nDigite o Nome de funcionario: ");
	     	printf("\nCódigo: %i",employ[i].codigo = RANDOM);
	     	cadastrarSalario(&employ[i].Salario);
	        cadastrarQuantidade(&employ[i].qtdDependentes,CONST,"\nDigite a Quantidade de Dependentes: ");
	     	depend = alocarVetorDependente(employ[i].qtdDependentes);
	     	
	     	 if (employ[i].qtdDependentes == 0)  {
			        printf("\nNão possui dependentes.");
			}else{
				
			  for(int j = 1 ; j <= employ[i].qtdDependentes ;j++  ){
			  	
			    cadastrarNome(depend[j].nome,"\nDigite o Nome do Dependente: ");
	            printf("\nCódigo do dependente: %i",NUMSEQ(employ[i].codigo,i));
	            cadastrarQuantidade(&employ[j].qtdDependentes,18,"\nDigite a Idade do Dependente : ");	
			}
		}
		 }
		 
	 }
	 
	  if(choice == 'B'){
		  	imprimirTodosFuncionarios(quant,employ);
		  	 printf("\nNão possui dependentes.");
	    
}
	 
}while(choice != 'C');
}

//1-funcaao
employee* alocarVetorFuncionario(int qtde){
	
   return (employee*) malloc (qtde * sizeof(employee));
	
}
//2-funcao
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

//3-funcao
void cadastrarQuantidade(int *quantidadeSolicitada, int valorMaximoPermitido,char *frasePersonalizada){
	do{
		 printf("\n%s " ,frasePersonalizada);
		 fflush(stdin);
         scanf("%i", quantidadeSolicitada);
		
		 if (*quantidadeSolicitada > valorMaximoPermitido || *quantidadeSolicitada < 0 ) {
            printf("\nQuantidade tem que ser menor ou igual : %i",valorMaximoPermitido);
        }
		
	}while(*quantidadeSolicitada > valorMaximoPermitido || *quantidadeSolicitada <0);
}
//4-funcao
void cadastrarSalario(double *salary) {
    
    do{
	
        printf("\nDigite o Salario R$");
        fflush(stdin);
        scanf("%lf", salary);
        
        if (*salary < 0) {
            printf("\nValor inválido.");
        }
    
	}while(*salary < 0);
}
//5-funcao
dependent* alocarVetorDependente(int qtde){
	
   return (dependent*) malloc (qtde * sizeof(dependent));
	
}

//6-funcao

void imprimirTodosFuncionarios(int qtdeFuncionario, employee *EmployeeCompany,dependent *depd) {
    int i;
	for (i = 1; i <= qtdeFuncionario; i++) {
		for(int j = 1 ; j <= EmployeeCompany[i].qtdDependentes ;j++  ){
        printf("\nFuncionarios %s - %i - R$%.2lf - %i" 
                "\nDependentes %s - %i - %i",
                EmployeeCompany[i].nome,EmployeeCompany[i].codigo, EmployeeCompany[i].Salario, EmployeeCompany[i].qtdDependentes,depd[j].nome,depd[i].codigo,depd[i].idade);
    }
}
    
}

