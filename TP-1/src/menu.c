#include "menu.h"
#include "patricia.h"
#include "tst_info.h"

void print_menu1()
{
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 163; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++)
    {
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 79; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 163; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for (i = 0; i < 41; i++)
    {
        fputs(" ", stdout);
    }
    printf("Digite (1) para Utilizar a TRIE TST e (2) Utilizar a PATRICIA");
    for (i = 0; i < 50; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n|           ");
    for (i = 0; i < 152; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");

    printf("|");
    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("------------->");
    fflush(stdin);
}

void print_menu2()
{
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 163; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++)
    {
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 79; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 163; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for (i = 0; i < 51; i++)
    {
        fputs(" ", stdout);
    }
    printf("Digite (1) Para Inserir word, (2) Para Pesquisar Palavra");
    for (i = 0; i < 45; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n|           ");

    for (i = 0; i < 38; i++)
    {
        fputs(" ", stdout);
    }
    printf(" ");
    for (i = 0; i < 113; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");

    for (i = 0; i < 45; i++)
    {
        fputs(" ", stdout);
    }
    printf(" (3) Para Exibir Todas as Palavras em Ordem Alfabética, (4) Para Contar as Palavras ou");
    for (i = 0; i < 32; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");

    for (i = 0; i < 38; i++)
    {
        fputs(" ", stdout);
    }
    printf(" ");
    for (i = 0; i < 124; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");

    for (i = 0; i < 60; i++)
    {
        fputs(" ", stdout);
    }
    printf("Qualquer número diferente dos anteriores para fechar o programa.");
    for (i = 0; i < 39; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");

    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("------------->");
    fflush(stdin);
}

void menu(TipoApontador p,TipoTSTinfoPointer q, TSTNode *root)
{
    int resp[2];
    char word[MAX];
    char search[MAX];
    TipoRegistro aux;

    print_menu1();
    scanf("%d", &resp[0]);
    if (resp[0] == 1)
        ;
    else
        inicializa(&p);
        inicializaDados(&q);
    do
    {

        print_menu2();
        scanf("%d", &resp[1]);

        //opções para TST
        if (resp[0] == 1 && resp[1] == 1)
        {
            printf("Digite a palavra que será inserida = ");
            scanf("%s", word);
            insert(&root,&q,word);
        }
        if (resp[0] == 1 && resp[1] == 2)
        {
            printf("Digite a palavra que será pesquisada = ");
            scanf("%s", search);
            searchTST(root, search) ? printf("Encontrado\n") : printf("Não Encontrado\n");
        }
        if (resp[0] == 1 && resp[1] == 3)
        {
            printTST(root);
        }
        if (resp[0] == 1 && resp[1] == 4)
    
        {   
            printf("Quantidade de palavras na arvore: %d \n",root->contador);
            //CountWordsTST(root);  //funcao para contar as palavras                    XXXXXXXXXXXXXXXXXXX
            printf("Quantidade de espaço utilizado: %d",q->Memory);
        }

        //opções para PATRICIA
        if (resp[0] == 2 && resp[1] == 1)
        {
            printf("Digite a palavra que será inserida = ");
            scanf("%s", word);
            aux.word = (*word);
            insere(aux, &p);
        }
        if (resp[0] == 2 && resp[1] == 2)
        {
            printf("Digite a palavra que será pesquisada = ");
            scanf("%s", search);
            aux.word = (*search);
            pesquisa(&aux, &p);
        }
        if (resp[0] == 2 && resp[1] == 3)
        {
        }
        if (resp[0] == 2 && resp[1] == 4)
        {
        }
    } while (resp[1] == 1 || resp[1] == 2 || resp[1] == 3 || resp[1] == 4);
}