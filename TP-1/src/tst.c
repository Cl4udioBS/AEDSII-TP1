#include "tst.h"

// cria Nó da TST
TSTNodePointer newNode(char data)
{
    TSTNode *temp = (struct TSTNode *)malloc(sizeof(TSTNode));
    temp->character = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    temp->contador=0;
    return temp;
}

// insere uma nova palavra na TST
void insert(TSTNodePointer *root,TipoTSTinfoPointer *tree, char *word)
{
    

    // Caso Base: Árvore está vazia
    if (!(*root))
        *root = newNode(*word);
        //Conta palavras para avaliar memoria
        Contaletras(word);
        (*tree)->Memory += Contaletras(word);//memory_count ----

    // Se o caracteratual da palavra for menor que o caractere da raiz,
    // insira esta palavra na subárvore esquerda da raiz
    if ((*word) < (*root)->character){
        insert(&((*root)->left),tree, word);        
        (*tree)->Memory += Contaletras(word); //memory_count ----
    }
    // Se o caractere atual da palavra for maior do que o caractere da raiz, 
    // então insira esta palavra na subárvore direita da raiz
    else if ((*word) > (*root)->character){
        insert(&((*root)->right),tree, word);        
        (*tree)->Memory += Contaletras(word);//memory_count ----
        }
    // Se o caractere atual da palavra for igual ao caractere da raiz,
    else
    {
        (*tree)->Memory += Contaletras(word);//memory_count ----
        if (*(word + 1)){
            insert(&((*root)->eq), tree, word + 1);            
            (*tree)->Memory -= 1;//memory_count ----
        }
        // último caractere da palavra
        else{
            (*root)->contador=(*root)->contador+1;
            (*root)->isEndOfString = 1;
            }
            
    }
}

// Percorre TST
void printTSTUtil(TSTNodePointer root, char *buffer, int depth)
{
    if (root)
    {
        // Primeira percorra a subárvore esquerda
        printTSTUtil(root->left, buffer, depth);

        // Armazene o caráter deste nó
        buffer[depth] = root->character;
        if (root->isEndOfString)
        {
            buffer[depth + 1] = '\0';
            printf("%s\n", buffer);
        }

        // Percorre subárvore do meio
        printTSTUtil(root->eq, buffer, depth + 1);

        // Finalmente, Percorre a subárvore direita
        printTSTUtil(root->right, buffer, depth);
    }
}

// Função principal pra percorrer TST
// Encapsula printTSTUtil()
void printTST(TSTNodePointer root)
{
    char buffer[MAX];
    printTSTUtil(root, buffer, 0);
}

// Função para pesquisar uma determinada palavra no TST
int searchTST(TSTNodePointer root, char *word)
{
    if (!root)
        return 0;

    if (*word < (root)->character)
        return searchTST(root->left, word);

    else if (*word > (root)->character)
        return searchTST(root->right, word);

    else
    {
        if (*(word + 1) == '\0')
            return root->isEndOfString;

        return searchTST(root->eq, word + 1);
    }
}

int Contaletras(char *str)
{
     int cont = 0;
     for(;*str;str++) cont++;
     return cont;
}
