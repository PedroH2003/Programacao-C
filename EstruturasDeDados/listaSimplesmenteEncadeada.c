/*Pretendo adcionar mais algumas funções mas oque já tem aqui funciona perfeitamente*/

#include <stdio.h>
#include <stdlib.h>

typedef int d; //fiz esse typedef para caso eu queira mudar o tipo de dado da minha lista de forma mais rapida

struct no{
    d valor;
    struct no *prox;
};
typedef struct no No;

No* cria_no(d valor);
No* insere_inicio(No *lista, d valor);
No* insere_final(No *lista, d valor);
No* busca_referencia(No *lista, d referencia);
No* insere_apos_ref(No *lista, d valor, d referencia);
void mostra_lista(No *lista);
No* remove_lista(No *lista);

int main()
{
    No *lista = NULL;

    lista = insere_inicio(lista, 2);
    lista = insere_inicio(lista, 100);
    lista = insere_final(lista, 50);
    lista = insere_apos_ref(lista, 30, 100);
    lista = insere_apos_ref(lista, 40, 30);
    lista = insere_apos_ref(lista, 1, 2);

    mostra_lista(lista);

    lista = remove_lista(lista);


    return 0;
}

No* cria_no(d valor)
{
    No *lista = (No*) malloc(sizeof(No));
    lista->valor = valor;
    lista->prox = NULL;

    return lista;
}

No* insere_inicio(No *lista, d valor)
{
    No *aux = cria_no(valor);

    if(lista == NULL)
    {
        lista = aux;
    }
    else
    {
        aux->prox = lista;
        lista = aux;
    }

    return lista;
}

No* insere_final(No *lista, d valor)
{
    No *aux = cria_no(valor);
    No *aux2= lista;

    if(lista == NULL)
    {
        lista = aux;
    }
    else
    {
        while(aux2->prox != NULL)
        {
            aux2 = aux2->prox;
        }

        aux2->prox = aux;
    }

    return lista;
}

No* busca_referencia(No *lista, d referencia)
{
    No *no_ref = lista;

    while(no_ref->valor != referencia)
    {
        no_ref = no_ref->prox;
    }

    return no_ref;
}

No* insere_apos_ref(No *lista, d valor, d referencia)
{
    No *aux = cria_no(valor);
    No *no_ref=NULL;

    if(lista == NULL)
    {
        lista = aux;
    }
    else
    {
        no_ref = busca_referencia(lista, referencia);

        aux->prox = no_ref->prox;
        no_ref->prox = aux;
    }

    return lista;
}

void mostra_lista(No *lista)
{
    No *aux=lista;
    if(lista != NULL)
    {
        while(aux != NULL)
        {
            if(aux->prox != NULL)
            {
                printf("%d | ", aux->valor);
            }
            else
            {
                printf("%d\n", aux->valor);
            }
            aux = aux->prox;
        }
    }
    else
    {
        printf("A lista esta vazia\n");
    }
}

No* remove_lista(No *lista)
{
    No *aux = lista;

    while(aux != NULL)
    {
        lista = lista->prox;
        free(aux);
        aux = lista;
    }

    return NULL;
}