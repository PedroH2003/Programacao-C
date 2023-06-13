/*AINDA NÃO ESTÁ TOTALMENTE COMPLETO*/

#include <stdio.h>
#include <stdlib.h>

typedef int d;

struct noc
{
    d valor;
    struct noc *proximo;
};
typedef struct noc Noc;

Noc *cria_noc(d valor);
Noc *insere_fim_ini(Noc *lista, d valor);
Noc *busca_noc(Noc *lista, d ref);
Noc *insere_apos_ref(Noc *lista, d valor, d ref);
void mostra_noc(Noc *lista);
Noc *remove_lista(Noc *lista);

int main()
{



    return 0;
}

Noc *cria_noc(d valor)
{
    Noc *aux;
    aux = (Noc*) malloc(sizeof(Noc));

    aux->valor = valor;
    aux->proximo = NULL;

    return aux;
}

Noc *insere_fim_ini(Noc *lista, d valor)
{
    Noc *novo = cria_noc(valor);
    Noc *aux = lista;

    if(lista == NULL)
    {
        lista = novo;
        lista->prox = lista;
    }
    else
    {
        while(aux->proximo != lista)
        {
            aux = aux->proximo;
        }

        aux->proximo = novo;
        novo->proximo = lista;
       
    }

    return lista;
}

Noc *busca_noc(Noc *lista, d ref)
{
    Noc *aux = lista;

    if(aux != NULL)
    {
        while(aux->proximo != lista and aux->valor != ref)
        {
            aux = aux2->proximo;
        }

        if(aux->proximo == lista and aux->valor != ref)
        {
            aux = NULL;
        }
    }

    return aux;

}

Noc *insere_apos_ref(Noc *lista, d valor, d ref)
{
    Noc *novo;
    Noc *aux = busca_noc(lista, ref);

    if(lista == NULL or aux == NULL)
    {
        printf("A lista não possui elementos ou nao o elemento de referencia nao existe");
    }
    else
    {
        novo = cria_noc(valor);
        if(aux->proximo == lista)
        {
            aux->proximo = novo;
            novo->proximo = lista;
        }
        else
        {
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }

    return lista;
}

void mostra_noc(Noc *lista)
{
    Noc *aux = lista;

    do
    {
        printf("%d ", aux->valor);
        aux = aux->proximo;

    }while(aux != lista)
}

Noc *remove_lista(Noc *lista);