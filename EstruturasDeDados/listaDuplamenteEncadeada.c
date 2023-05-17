/*Pretendo adcionar mais algumas funções mas oque já tem aqui funciona perfeitamente*/

#include <stdio.h>
#include <stdlib.h>

typedef int d;

struct nod{
    d valor;
    struct nod *anterior;
    struct nod *proximo;
};
typedef struct nod Nod;

struct listad{
    Nod *inicio;
    Nod *fim;
};
typedef struct listad Listad;

Listad *cria_listad(Listad *l);
Nod *cria_nod(d valor);
Listad *insere_inicio(Listad *l, d valor);
Listad *insere_fim(Listad *l, d valor);
Nod *busca_nod(Nod *aux, d ref);
void insere_apos_ref(Listad *l, d valor, d ref);
void mostra_listad(Listad *l);
void remove_listad(Listad *l);

int main()
{
    Listad *lista=NULL;

    lista = insere_inicio(lista, 3);
    lista = insere_inicio(lista, 2);
    lista = insere_inicio(lista, 1);
    lista = insere_fim(lista, 4);
    lista = insere_fim(lista, 6);
    insere_apos_ref(lista, 5, 4);
    insere_apos_ref(lista, 100, 2);
    insere_apos_ref(lista, 200, 7);

    mostra_listad(lista);
    remove_listad(lista);


    return 0;
}

Listad *cria_listad(Listad *l)
{
    Listad *aux = (Listad *) malloc(sizeof(Listad));
    aux->inicio = NULL;
    aux->fim = NULL;

    return aux;
}

Nod *cria_nod(d valor)
{
    Nod *aux = (Nod *) malloc(sizeof(Nod));
    aux->valor = valor;
    aux->anterior = NULL;
    aux->proximo = NULL;

    return aux;
}

Listad *insere_inicio(Listad *l, d valor)
{
    Nod *aux = cria_nod(valor);
    if(l == NULL)
    {
        l = cria_listad(l);
        l->inicio = l->fim = aux;
    }
    else
    {
        l->inicio->anterior = aux;
        aux->proximo = l->inicio;
        l->inicio = aux;
    }

    return l;
}

Listad *insere_fim(Listad *l, d valor)
{
    Nod *aux = cria_nod(valor);
    if(l == NULL)
    {
        l = cria_listad(l);
        l->inicio = l->fim = aux;
    }
    else
    {
        l->fim->proximo = aux;
        aux->anterior = l->fim;
        l->fim = aux;
    }    

    return l;
}

Nod *busca_nod(Nod *aux, d ref)
{
    while(aux != NULL && aux->valor != ref)
    {
        aux = aux->proximo;
    }

    return aux;
}

void insere_apos_ref(Listad *l, d valor, d ref)
{
    Nod *aux;
    Nod *aux2;
    if(l == NULL)
    {
        printf("A lista esta vazia.\n");
    }
    else
    {
        aux = l->inicio;
        aux = busca_nod(aux, ref);

        if(aux != NULL)
        {
            if(aux->valor == l->fim->valor)
            {
                insere_fim(l, valor);
            }
            else
            {
                aux2 = cria_nod(valor);
                aux2->proximo = aux->proximo;
                aux2->anterior = aux;
                aux->proximo = aux2;
            }
        }
        else
        {
            printf("O valor %d nao esta presente na lista.\n", ref);
        }

    }
}

void mostra_listad(Listad *l)
{
    Nod *aux;
    if(l != NULL)
    {
        aux = l->inicio;

        while(aux != NULL)
        {
            if(aux->proximo != NULL)
            {
                printf("%d | ", aux->valor);
            }
            else
            {
                printf("%d\n", aux->valor);
            }

            aux = aux->proximo;
        }
    }
    else
    {
        printf("A lista esta vazia.\n");
    }
}

void remove_listad(Listad *l)
{
    Nod *aux;
    if(l != NULL)
    {
        aux = l->inicio;
        while(aux != NULL)
        {
            l->inicio = aux->proximo;
            free(aux);
            aux = l->inicio;
        }

        free(l);
    }
    else
    {
        printf("A lista esta vazia.\n");
    }
}