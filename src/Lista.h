#ifndef _LISTA_
#define _LISTA_

#include <stdio.h>
#include <stdlib.h>

//Simplificando o nome das Struct's
typedef struct TipoItem Item;
typedef struct TipoBloco Bloco;
typedef struct TipoLista Lista;
//FIm -> Simplificando o nome das Struct's

//Declarando as Struct's
struct TipoItem{
    int valor;
};
struct TipoBloco{
    Item dado;
    Bloco *prox;
};
struct TipoLista{
    Bloco *primeiro;
    Bloco *ultimo;
};
//Fim -> Declarando as Struct's

//Funções da lista
void ListaVazia(Lista *l){
    l->primeiro = (Bloco*)malloc(sizeof(Bloco));
    l->ultimo = l->primeiro;
    l->ultimo->prox = NULL;
}

void Inserir(Lista *l, Item x){
    l->ultimo->prox = (Bloco*)malloc(sizeof(Bloco));
    l->ultimo = l->ultimo->prox;
    l->ultimo->prox = NULL;
    l->ultimo->dado = x;
    printf("\n\nItem inserido.\n\n");
}

void remover(Lista *l, Item x){
    Bloco *aux;
    Bloco *temp;

    if(l->primeiro == l->ultimo){
        printf("\n\nErro! Lista vazia.\n\n");
        return;
    }
    
    aux = l->primeiro;
    while( (aux != NULL) && aux->prox->dado.valor != x.valor)
        aux = aux->prox;

    if(aux != NULL){
        temp = aux;
        aux = aux->prox;
        temp->prox = aux->prox;
        free(aux);
        printf("\n\nItem removido\n\n");
    }else
        printf("\n\nItem nao existente ou nao encontrado\n\n");
}
//Fim -> Funções da lista
#endif