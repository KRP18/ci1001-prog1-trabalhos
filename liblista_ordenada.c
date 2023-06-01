#include <stdio.h>
#include <stdlib.h>
#include "liblista_ordenada.h"

lista_t *lista_cria()
{
	lista_t *l;

	if(!(l = malloc(sizeof(lista_t))))
		return NULL;

	l->ini = NULL;

	return l;
}

elemento_t *elemento_cria(int dado)
{
	elemento_t *e;

	if(!(e = malloc(sizeof(elemento_t))))
		return NULL;

	e->chave = dado;

	return e;
}

int lista_vazia(lista_t *l) 
{
	return !l->ini;
}
 
void lista_destroi(lista_t **l)
{
	nodo_t *aux;
	
	while(!lista_vazia((*l)))
	{
		aux = (*l)->ini;
		(*l)->ini = (*l)->ini->prox;
		free(aux->elemento);
		free(aux);
	}
	
	free((*l));
	(*l) = NULL;
}

void elemento_destroi(elemento_t **elemento)
{
    if (elemento != NULL && *elemento != NULL) {
        free(*elemento);
        *elemento = NULL;
    }
}

int lista_insere_ordenado(lista_t *l, elemento_t *elemento)
{
    nodo_t *novo, *aux, *ant;

    if (!(novo = malloc(sizeof(nodo_t))))
        return 0;

    novo->elemento = elemento;

    if (lista_vazia(l))
    {
        novo->prox = NULL;
        l->ini = novo;
        return 1;
    }

    aux = l->ini;
    ant = NULL;
    while (aux != NULL && novo->elemento->chave > aux->elemento->chave)
    {
        ant = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    if (ant != NULL)
        ant->prox = novo;
    else
        l->ini = novo;

    return 1;
}

int lista_remove_ordenado(lista_t *l, elemento_t *elemento)
{
	nodo_t *aux, *temp;
	
	if(lista_vazia(l))
	{
		return 0;
	}
	
	if(elemento->chave == l->ini->elemento->chave)
	{
		aux = l->ini;
		l->ini = aux->prox;
		free(aux);
		return 1;
	}
	
	aux = l->ini;
	while(aux->prox != NULL && 
		elemento->chave != aux->prox->elemento->chave)
	{
		aux = aux->prox;
	}
	
	if(aux->prox == NULL)
			return 0;
		
	temp = aux->prox;
	aux->prox = temp->prox;
	free(temp);
	return 1;	
}

int lista_search_ordenado(lista_t *l, elemento_t *elemento)
{
	nodo_t *aux;
	
	if(lista_vazia(l))
	{
		return 0;
	}
	
	if(elemento->chave == l->ini->elemento->chave)
	{
		return 1;
	}
	
	aux = l->ini;
	while(aux->prox != NULL && 
		elemento->chave != aux->prox->elemento->chave)
	{
		aux = aux->prox;
	}
	
	if(aux->prox == NULL || 
		elemento->chave != aux->prox->elemento->chave)
			return 0;

	return 1;	
}