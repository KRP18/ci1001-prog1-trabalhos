/* 
 * Implementa o TAD Lista Ordenada
 * Feito em C para a disciplina CI1001 - Programacao 1 
 *
 * Versao 1.1.0 30/05/2023 por Kauan
 */

/*
 * elemento_t possui o campo chave, quem sabe pode ter mais coisas depois
*/
typedef struct elemento {
    int chave;  /* chave da struct */
    /* pode ter mais campos, mas a chave sera usada sempre nas operacoes */
} elemento_t;

/*
 * nodo_t eh uma estrutura interna que representa cada nodo da Lista.
 * Externamente o usuario da biblioteca nao vai poder usa-la, pois
 * nao pode ter acesso direto ao ponteiro prox.
*/
typedef struct nodo {
    elemento_t *elemento;
    struct nodo *prox;
} nodo_t;

/*
 * Representacao da Lista 
*/
typedef struct lista {
    nodo_t *ini;
} lista_t;

/* 
 * Cria uma Lista vazia 
*/
lista_t *lista_cria ();

/* 
 * verifica se lista está vazia
*/
int lista_vazia(lista_t *l);

/* 
 * Cria um elemento
*/
elemento_t *elemento_cria(int dado);

/* 
 * Destroi a Lista e a aponta para NULL
*/ 
void lista_destroi (lista_t **l);

/* 
 * Destroi um elemento e o aponta para null
*/ 
void elemento_destroi(elemento_t **elemento);

/* 
 * Adiciona um elemento em ordem de acordo com o valor elemento->chave na Lista. 
 * Retorna 1 em caso de sucesso e 0 caso contrario.
*/
int lista_insere_ordenado (lista_t *l, elemento_t *elemento);

/* 
 * Retira o elemento da Lista e a mantem em ordem.
 * Retorna 1 em caso de sucesso e 0 caso elemento nao esteja na Lista.
*/
int lista_remove_ordenado (lista_t *l, elemento_t *elemento);