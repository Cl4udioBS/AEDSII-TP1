#ifndef TSTinfo_h
#define TSTinfo_h
#include "tst.h"

//dados da arvore
typedef struct TSTinfo *TipoTSTinfoPointer;
typedef struct TSTinfo
{
    int Memory, WordsScore;
    float ExecTime;
} TSTinfo;

 

//Funções para comparações de dados das árvores

void inicializaDados(TipoTSTinfoPointer *Tree);
int CountWordsTSTUtil(TSTNodePointer root);
void CountWordsTST(TSTNodePointer root);

#endif
