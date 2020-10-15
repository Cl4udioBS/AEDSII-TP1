#ifndef PATRICIA_h
#define PATRICIA_h

#include <stdio.h>
#include <stdlib.h>

typedef struct TipoRegistro
{
  char word;
} TipoRegistro;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
  TipoRegistro reg;
  TipoApontador esq, dir;
} TipoNo;

typedef TipoApontador TipoDicionario;


void inicializa(TipoApontador *Dicionario);
void insere(TipoRegistro x, TipoApontador *p);
void antecessor(TipoApontador q, TipoApontador *r);
void retira(TipoRegistro x, TipoApontador *p);
void ordem(TipoApontador p);
void preordem(TipoApontador p);
void posordem(TipoApontador p);
int altura(TipoApontador p);
void pesquisa(TipoRegistro *x, TipoApontador *p);

#endif