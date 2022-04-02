// Trabalho 01-Ponteiros e alocação dinâmica de memória
// Nome: Gabriel Bitencourt Cardoso-Email:gabrielbc.aluno@unipampa.edu.br

#include <stdio.h>
#include <stdlib.h>

struct _produto {
     int codigo;
    char descricao[80];
    float valor;
};

typedef struct _produto p;

int main(){
 int i,qts;
 p *dadosproduto;
 float vt;
 printf("Quantos produtos ? ");
 scanf("%d",&qts);
 
 dadosproduto = malloc(qts*sizeof(p));

 for (i=0; i<qts; i++) {
    printf("Digite o codigo: ");
    scanf("%d",&dadosproduto[i].codigo);
    printf("Digite a descricao: ");
    scanf("%s",&dadosproduto[i].descricao);
    printf("Digite o valor: ");
    scanf("%f",&dadosproduto[i].valor);
 }
 
 printf("Codigo\tDescricao\tValor\n");
 for (i=0; i<qts; i++) {
    printf("%d\t%s\t\t%.2f\n", dadosproduto[i].codigo, dadosproduto[i].descricao, dadosproduto[i].valor );    
 }
 for(i=0; i<qts; i++){
    vt=dadosproduto[i].valor+vt;
 }
 printf("Valor total: %.2f",vt);

free(dadosproduto);
return 0;
}