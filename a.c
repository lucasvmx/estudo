#include <stdio.h>
#include <stdlib.h>

typedef struct cabeca {
    int num_itens;
    celula *prox;
    celula *ultimo;
} cabeca;

typedef struct celula { 
    int dado; 
    struct celula *prox;
} celula;

int vetor[20];

void preenche()
{
    for(int i = 0; i < 20; i++)
        vetor[i] = 3 * i - 1;
}


cabeca *cria_lista()
{
    cabeca *lista;

    lista = malloc(sizeof(cabeca));
    lista->prox = NULL;
    lista->num_itens = 0;
    lista->ultimo = NULL;
    
    return lista;
}

celula *cria_no(int dado) {

    celula *no = malloc(sizeof(celula));
    no->dado = dado;
    no->prox = NULL;
    return no;
}

void imprime_lista(celula *l)
{
    if(l != NULL) {
        printf("%d\n", l->dado);
        imprime_lista(l->prox);
    }
}

int vazia(cabeca *lista) {
    return lista->prox == NULL;
}

void inserir_inicio(cabeca *lista, celula *no)
{
    lista->num_itens++;
    no->prox = lista->prox;
    lista->prox = no;

    if(lista->prox == NULL) lista->ultimo = no;
}

void insere_depois(cabeca *lista, celula *ref, celula *no)
{
    no->prox = ref->prox;
    ref->prox = no;

    lista->num_itens++;

    if(no->prox == NULL) lista->ultimo = no;
}

void inserir_fim(cabeca *lista, celula *elem)
{
    lista->num_itens++;
    lista->ultimo->prox = elem;
}

int main()
{
    celula *lista = cria_lista();


    imprime_lista(lista);

    return 0;
}

