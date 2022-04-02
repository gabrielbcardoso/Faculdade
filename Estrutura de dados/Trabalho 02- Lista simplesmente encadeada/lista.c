// Trablho 02 - Lista simplesmente encadeada
// Gabriel Bitencourt Cardoso - gabrielbc.aluno@unipampa.edu.br

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"
int main(){
struct aluno *head = NULL;
    
    int opt;
    do
    {
        printf("---Menu---\n");
        printf("1.Inserir Aluno\n");
        printf("2.Exibir Alunos\n");
        printf("3.Remover Aluno\n");
        printf("4.sair\n");
        scanf("%d", &opt);
        if (opt == 1)
        {
           head = criarordemA(head);
        }
        else if (opt == 2)
        {
           printar(head);
        }
        else if (opt == 3)
        {
           deletar(head); 
        }
    } while (opt != 4);
    for (int i = 0; i < 3; i++)
    {
        head = criarordemA(head);
    }

    printar(head);

   
    return 0;
}