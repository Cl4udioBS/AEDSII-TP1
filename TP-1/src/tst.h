#ifndef TST_h
#define TST_h

#include <stdio.h>
#include <stdlib.h>
#include "tst_info.h"

#define MAX 50

// Nó TST
typedef char data;
typedef struct TSTNode *TSTNodePointer;

typedef struct TSTNode {
    data character;
    // Verdadeiro || 1 se este caractere for o último caractere de uma das palavras
    short isEndOfString : 1; //mudar pra 2 caso de pau
    int contador;
    TSTNodePointer left,eq,right;
    
} TSTNode;





//FUNÇOES

int Contaletras(char *str);
void insert(TSTNodePointer *root, TipoTSTinfoPointer *tree, char *word);
void printTSTUtil(TSTNodePointer root, char *buffer, int depth);
void printTST(TSTNodePointer root);
int searchTST(TSTNodePointer root, char *word);
TSTNodePointer newNode(char data);

#endif