#ifndef LISTA_H
#define LISTA_H
typedef struct No{
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* cabeca;
} Lista;

Lista* criarLista();
void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);
void imprimirLista(Lista* lista);
int remover(Lista* lista, int valor);
void liberarLista(Lista* lista);
int estaVazia(Lista* lista);
int buscar(Lista* lista, int valor);
int contarElementos(Lista* lista);
void concatenarLista(Lista* l1, Lista* l2);
int obterMaior(Lista* lista);
int obterMenor(Lista* lista);
void removerDuplicatas(Lista* lista);
void reverterLista(Lista* lista);
//funções criadas

Lista* copiarLista(Lista* lista);

#endif
