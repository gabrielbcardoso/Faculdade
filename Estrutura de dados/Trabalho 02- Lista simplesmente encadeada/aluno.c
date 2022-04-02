
// Trablho 02 - Lista simplesmente encadeada
// Gabriel Bitencourt Cardoso - gabrielbc.aluno@unipampa.edu.br

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno
{
    int m;      //matricula
    char N[40]; //Nome
    float n;    //nota
    struct aluno *link;
};

struct aluno *criarordemA(struct aluno *head)
{

    struct aluno *ptr = malloc(sizeof(struct aluno));
    if (ptr == NULL)
    {
        abort();
    }
    printf("Informe a matricula do aluno: ");
    scanf("%d", &ptr->m);
    fflush(stdin);
    printf("Informe nome do aluno: ");
    scanf("%s", &ptr->N);
    fflush(stdin);
    printf("Informe a nota do aluno: ");
    scanf("%f", &ptr->n);

    ptr->link = NULL;

    if (head == NULL || strcmp(ptr->N, head->N) < 0) //não existe head ou ptr alfabeticamente antes
    {
        ptr->link = head;
        return ptr; //retorna ptr que vem antes do head para ser o primeiro
    }
    else
    {
        struct aluno *atual = head;
        while (atual->link != NULL && strcmp(ptr->N, atual->link->N) >= 0) //proximo diferente de nulo ou nome vem depois
        {
            atual = atual->link;
        }
        ptr->link = atual->link; //atual vai apontar para o prox A->C B(digitei agr)->C
        atual->link = ptr;       // A->B
        return head;
    }
}

void printar(struct aluno *head)
{
    if (head == NULL)
    {
        printf("Lista esta vazia");
    }
    struct aluno *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("Informacoes dos alunos: \n");
        printf("Matriculo do aluno: %d \n", ptr->m);
        printf("Nome do aluno: %s \n", ptr->N);
        printf("Nota do Aluno: %.2f \n\n", ptr->n);
        ptr = ptr->link;
    }
}

struct aluno *deletar(struct aluno *head)
{
    
    if (head == NULL){ 
        printf("Lista esta vazia!");}
    else
    { 
         struct aluno *ptr = head;
         struct aluno *anterior = head;
         char Naexcluir[40];
       fflush(stdin); 
       printf("Digite o nome do aluno que sera excluido! ");
       scanf("%s", &Naexcluir);
       fflush(stdin);
       
        if (strcmp(Naexcluir, head->N) == 0)
        {
            head = head->link;
            free(ptr);
            free(anterior);
            ptr = NULL;
            anterior = NULL;
        }
        else
        {
            while (strcmp(Naexcluir, ptr->N) != 0 && ptr->link != NULL)
                
            {
                anterior = ptr;
                ptr = ptr->link;
            }
            if (strcmp(Naexcluir, ptr->N) == 0)
            {
                anterior->link = ptr->link;
                free(ptr);
                ptr = NULL;
            }
            else
            {
                printf("Aluno nao existe!");
            }
            
        }
    }

    return head;
}