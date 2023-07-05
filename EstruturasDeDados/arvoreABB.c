/*Ainda pretendo acrescentar mais coisas mas oque está aqui já funciona*/

#include <stdio.h>
#include <stdlib.h>

typedef int d;

struct no
{
    d chave;
    struct no *esquerda;
    struct no *direita;
};
typedef struct no No;

No *cria_no(d chave);
No *insere_no_r(No *raiz, d chave); //insere no de forma recursiva
No *insere_no_i(No *raiz, d chave); //insere no de forma iterativa
void pre_ordem(No *raiz);
void em_ordem(No *raiz);
void pos_ordem(No *raiz);



int main()
{
    No *raiz=NULL;

    raiz = insere_no_r(raiz, 5);
    raiz = insere_no_i(raiz, 3);
    raiz = insere_no_r(raiz, 7);
    raiz = insere_no_i(raiz, 1);
    raiz = insere_no_r(raiz, 6);

    pre_ordem(raiz);
    printf("\n");
    em_ordem(raiz);
    printf("\n");
    pos_ordem(raiz);

    return 0;
}

No *cria_no(d chave)
{
    No *aux = (No*) malloc(sizeof(No));
    aux->chave = chave;
    aux->esquerda = aux->direita = NULL;

    return aux;
}

No *insere_no_r(No *raiz, d chave) //insere no de forma recursiva
{
    No *novo = cria_no(chave);

    if(raiz == NULL)
    {
        raiz = novo;
    }
    else
    {
        if(chave < raiz->chave)
        {
            raiz->esquerda = insere_no_r(raiz->esquerda, chave);
        }
        else if(chave > raiz->chave)
        {
            raiz->direita = insere_no_r(raiz->direita, chave);
        }   
    }

    return raiz;
}

No *insere_no_i(No *raiz, d chave) //insere no de forma iterativa
{
    No *novo = cria_no(chave);
    No *aux = raiz;
    No *pai;

    if(raiz == NULL)
    {
        raiz = novo;
    }
    else
    {
        while(aux != NULL)
        {
            pai = aux;
            if(chave < aux->chave)
            {
                aux = aux->esquerda;
            }
            else if(chave > aux->chave)
            {
                aux = aux->direita;
            }
        }

        if(chave < pai->chave)
        {
            pai->esquerda = novo;
        }
        else if(chave > pai->chave)
        {
            pai->direita = novo;
        }
    }

    return raiz;
}

void pre_ordem(No *raiz)
{
    if(raiz != NULL)
    {
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(No *raiz)
{
    if(raiz != NULL)
    {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->chave);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(No *raiz)
{
    if(raiz != NULL)
    {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}