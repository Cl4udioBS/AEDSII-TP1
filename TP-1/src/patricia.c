#include "patricia.h"

void inicializa(TipoApontador *Dicionario)
{
  *Dicionario = NULL; //raiz da árvore
}

void insere(TipoRegistro x, TipoApontador *p)
{
  if (*p == NULL) //caso esteja vazio ensira na raiz
  {
    *p = (TipoApontador)malloc(sizeof(TipoNo));
    (*p)->reg = x;
    (*p)->esq = NULL;
    (*p)->dir = NULL;
    return;
  }
  if (x.word < (*p)->reg.word)
  {
    insere(x, &(*p)->esq);
    return;
  }
  if (x.word > (*p)->reg.word)
    insere(x, &(*p)->dir);
  else
    printf("Erro:Registro já existe na árvore\n");
}

void antecessor(TipoApontador q, TipoApontador *r)
{
  if ((*r)->dir != NULL)
  {
    antecessor(q, &(*r)->dir);
    return;
  }
  q->reg = (*r)->reg;
  q = *r;
  *r = (*r)->esq;
  free(q);
}

void retira(TipoRegistro x, TipoApontador *p)
{
  TipoApontador aux;
  if (*p == NULL)
  {
    printf("Erro:Registro não está na arvore\n");
    return;
  }
  if (x.word < (*p)->reg.word)
  {
    retira(x, &(*p)->esq);
    return;
  }
  if (x.word > (*p)->reg.word)
  {
    retira(x, &(*p)->dir);
    return;
  }
  if ((*p)->dir == NULL)
  {
    aux = *p;
    *p = (*p)->esq;
    free(aux);
  }
  if ((*p)->esq != NULL)
  {
    antecessor(*p, &(*p)->esq);
    return;
  }
  aux = *p;
  *p = (*p)->dir;
  free(aux);
}

//percurso--transvercialização--ordem/infixa   (pré e pós)
void ordem(TipoApontador p)
{
  if (p != NULL)
  {
    ordem(p->esq);
    printf("%d\n", p->reg.word);
    ordem(p->dir);
  }
}

void preordem(TipoApontador p)
{
  if (p != NULL)
  {
    printf("%d\n", p->reg.word);
    preordem(p->esq);
    preordem(p->dir);
  }
}

void posordem(TipoApontador p)
{
  if (p != NULL)
  {
    posordem(p->esq);
    posordem(p->dir);
    printf("%d\n", p->reg.word);
  }
}

int altura(TipoApontador p)
{
  if (p == NULL)
  {
    return -1;
  }
  else
  {
    int he = altura(p->esq);
    int hd = altura(p->dir);
    if (he < hd)
      return hd + 1;
    else
      return he + 1;
  }
}

void pesquisa(TipoRegistro *x, TipoApontador *p)
{
  if (*p == NULL)
  {
    printf("Não Encontrado\n");
    return;
  }
  if (x->word < (*p)->reg.word)
  {
    pesquisa(x, &(*p)->esq);
    return;
  }
  if (x->word > (*p)->reg.word)
    pesquisa(x, &(*p)->dir);
  else
  {
    *x = (*p)->reg;
    printf("Encontrado\n");
  }
}