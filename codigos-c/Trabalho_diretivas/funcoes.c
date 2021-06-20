#include "Bibliotecas.h"
	
void menu(){
	
	 setlocale(LC_ALL, "Portuguese");
	
char choice;
int quant,numdep =0,i,j;
employee  *employ = NULL;

	
	

do{
	 printf("\n A - Inserir dados Funcionários");
	 printf("\n B - Exibir Informações");
	 printf("\n C - Finalizar");
	 printf("\nSelecione a opção desejada :");
	 fflush(stdin);
	 scanf(" %c", &choice);
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
	     for(i = 0 ; i < quant;i++  ){
	     
	     	cadastrarNome(employ[i].nome,"\nDigite o Nome de funcionario: ");
	     	
	     	printf("\nCódigo: %i",employ[i].codigo = RANDOM);
	     	cadastrarSalario(&employ[i].Salario);
	        cadastrarQuantidade(&employ[i].qtdDependentes,CONST,"\nDigite a Quantidade de Dependentes: ");
			employ[i].dadosDependentes = alocarVetorDependente(employ[i].qtdDependentes);
	        
			for(j = 0 ; j < employ[i].qtdDependentes ;j++  ){
		    	cadastrarNome(employ[i].dadosDependentes[j].nome,"\nDigite o Nome do Dependente: ");
		    	printf("%s",employ[i].dadosDependentes[j].nome);
	            printf("\nCódigo do dependente: %i", employ[i].dadosDependentes[j].codigo = NUMSEQ(employ[i].codigo,j));
	            cadastrarQuantidade(&employ[i].dadosDependentes[j].idade,18,"\nDigite a Idade do Dependente : ");
			
			}
			
		}
		
	 
		 }
		 
	 
	 
	  if(choice == 'B'){
		  	imprimirTodosFuncionarios(quant,employ);
		  	 
	  }	    

	 
}while(choice != 'C');

}
//1-funcao
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
        printf("\n%s" ,frasePersonalizada);
        scanf(" %i", quantidadeSolicitada);
        if((*quantidadeSolicitada < 0) || *quantidadeSolicitada > valorMaximoPermitido){
            printf("Valor Inválido, deve estar entre 0 e %i!\n", valorMaximoPermitido);
        }
    }while((*quantidadeSolicitada < 0) || *quantidadeSolicitada > valorMaximoPermitido);
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

void imprimirTodosFuncionarios(int qtdeFuncionario, employee *EmployeeCompany) {
    int i,j;
	for (i = 0; i < qtdeFuncionario; i++) {
		printf("\n===============Funcionarios===============" 
		       "\nNome: %s \nCodigo: %i \nSalário: R$%.2lf \nQuantidade Dependentes : %i" ,
		    EmployeeCompany[i].nome,EmployeeCompany[i].codigo, EmployeeCompany[i].Salario, EmployeeCompany[i].qtdDependentes);
		for (j = 0; j < EmployeeCompany[i].qtdDependentes; j++){
		  printf( "\n===============Dependentes==============="
		          "\nNome: %s \nCodigo: %i \nIdade: %i",
			 EmployeeCompany[i].dadosDependentes[j].nome, EmployeeCompany[i].dadosDependentes[j].codigo,EmployeeCompany[i].dadosDependentes[j].idade);
		}  
		
			        
}
    
}
