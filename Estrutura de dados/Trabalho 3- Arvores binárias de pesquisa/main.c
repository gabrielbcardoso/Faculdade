#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    int opcao, v;
    treenode *raiz = NULL;
    while (opcao != 0)
    {
        printf("\n----Menu----\n");
        printf("1.Inserir um elemento\n");
        printf("2.Buscar um elemento\n");
        printf("3.Imprimir arvore\n");
        printf("4.Imprimir altura da arvore\n");
        printf("5.Liberar arvore\n");
        printf("0.Sair\n");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor que deseja inserir:\n");
            scanf("%i", &v);
            raiz = inserirnode(raiz, v);
            break;
        case 2:
            printf("Digite o valor que deseja buscar: \n");
            scanf("%i",&v);
            buscarnode(raiz, v, raiz);
            break;
        case 3:
            printf("Imprimindo a arvore\n");
            printartree(raiz, 0);
            break;
        case 4:
            printf("Imprimindo a altura da arvore\n");
            printaraltura(raiz, 0);
            break;
        case 5:
            liberartree(raiz);
            break;
        case 0:
            printf("Saindo...");
            break;

        default:
            printf("Opcao invalida");
            break;
        }
    }
    return 0;
}