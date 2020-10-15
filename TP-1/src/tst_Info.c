//#include "tst_info.h"
#include "tst.h"


void inicializaDados(TipoTSTinfoPointer *Tree)
{
  *Tree = NULL; //dados da árvore
}

// Conta palavras TST
int CountWordsTSTUtil(TSTNodePointer root)
{
    int contador=0;

    if (root)
    {
        // Primeira percorra a subárvore esquerda
        contador += CountWordsTSTUtil(root->left);         
        if (root->isEndOfString)
        {            
              contador++;                          
        }
        // Percorre subárvore do meio
        contador += CountWordsTSTUtil(root->eq);
        // Finalmente, Percorre a subárvore direita
        contador += CountWordsTSTUtil(root->right);
        //printf("%d\n",&contador);
          return contador;
    }    
}

// Função principal pra percorrer TST
// Encapsula printTSTUtil()
void CountWordsTST(TSTNodePointer root)
{    
    int NumWords=0;
    
    NumWords = CountWordsTSTUtil(root); 
    printf("%d\n",NumWords);
    printf("Saiu\n");   
    printf("A quantidade de palavras e: %d\n",NumWords);
}