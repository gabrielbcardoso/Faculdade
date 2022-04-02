#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int valor;
    struct treenode *left;
    struct treenode *right;
}treenode;


treenode *criarnode(int valor){
    treenode *resultado = malloc(sizeof(treenode));
    if(resultado != NULL){
        resultado->left=NULL;
        resultado->right=NULL;
        resultado->valor=valor;
    } 
    return resultado;
}

treenode *inserirnode(treenode *node, int valor){
    if (node==NULL){
        node=criarnode(valor);
        return node;
    }
    if (valor==node->valor){
        printf("\nNumero ja foi adicionado\n");
        return node;
    }
    if(valor<node->valor){
        node->left=inserirnode(node->left,valor);
    }else {
        node->right=inserirnode(node->right,valor);
    }
    return  node;
}

void buscarnode(treenode *node, int chave, treenode *raiz){
    if (node==NULL){
        printf("Chave nao encontrada");
        return;
    }
    if(node->valor==chave){
        if(chave==raiz->valor){
            printf("A celula que equivale a %d e a raiz",chave);
        }
        if(chave>raiz->valor){
            printf("O valor informado corresponde a celula que esta a direita da celula com valor %i",raiz->valor);
        }
        if(chave<raiz->valor){
            printf("O valor informado corresponde a celula que esta a esquerda da celula com valor %i",raiz->valor);
        }
    return ;
    }
    if(chave<node->valor){
        buscarnode(node->left,chave,node);
    }else{
        buscarnode(node->right,chave,node);
    }
}

void printartabs(int numrtabs){
    for (int i = 0; i < numrtabs; i++)
    {
        printf("\t");
    }    
}

void printartree (treenode *raiz ,int level){
    if(raiz==NULL){
        printartabs(level);
        printf("---Vazio---\n");
        return;
    }
    printartabs(level);
    printf("Valor = %i \n",raiz->valor);

    printartabs(level);
    printf("left\n");
    printartree(raiz->left, level+1);

    printartabs(level);
    printf("right\n");
    printartree(raiz->right, level+1);   
        
}

void printatree (treenode* raiz){
    printartree(raiz,0);
}


//printar altura da arvore
void printaraltura(treenode *raiz ,int level){
    if(raiz==NULL){              
        return;
    }     
    printaraltura(raiz->left, level+1);   
    printaraltura(raiz->right, level+1);            
    printf("Altura da arvore:%i\n",level+1);
}



void liberartree(treenode *node){
    if (node==NULL){
        return;
    }
    free(node->valor);
    liberartree(node->left);
    liberartree(node->right);
    free(node);
}
