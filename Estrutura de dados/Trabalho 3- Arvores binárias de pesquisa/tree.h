typedef struct treenode {
    int valor;
    struct treenode *left;
    struct treenode *right;
}treenode;

treenode *criarnode(int valor);
treenode *inserirnode(treenode *node, int valor);
void buscarnode(treenode *node, int chave, treenode *raiz);
void printartabs(int numrtabs);
void printartree (treenode *raiz ,int level);
void printatree (treenode* raiz);
void printaraltura(treenode *raiz ,int level);
void liberartree(treenode *node);

