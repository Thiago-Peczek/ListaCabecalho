#include <stdio.h> 
#include <stdlib.h>
#include "lista.h"

Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeca = (No*)malloc(sizeof(No)); // nó de cabeçalho
    lista->cabeca->prox = NULL;
    return lista;
}

void inserirInicio(Lista* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = lista->cabeca->prox;
    lista->cabeca->prox = novo;
}

void inserirFim(Lista* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    No* atual = lista->cabeca;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
}

void imprimirLista(Lista* lista) {
    No* atual = lista->cabeca->prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int remover(Lista* lista, int valor) {
    No* ant = lista->cabeca;
    No* atual = ant->prox;

    while (atual != NULL && atual->dado != valor) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return 0; // não encontrado

    ant->prox = atual->prox;
    free(atual);
    return 1; // removido com sucesso
}

void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}

//verifica se o valor após o cabeçalho é vazio, caso seja retorna 1, se não for vazia retorna 0
int estaVazia(Lista* lista){
    if(lista->cabeca->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

//percorre a lista a partir do cabeçalho, se o valor do elemento for igual ao valor passado retorna 1, 
//caso percorra a lista inteira e não encontrar retorna 0
int buscar(Lista* lista, int valor) {
    No* atual = lista->cabeca->prox;

    while (atual != NULL) {
        if (atual->dado == valor) {
            return 1;  // Valor encontrado
        }
        atual = atual->prox;
    }

    return 0;  // Valor não encontrado
}

//percorre a lista incrementando um contador até encotrar um NULL e retorna o contador
int contarElementos(Lista* lista) {
    int cont = 0;
    No* atual = lista->cabeca->prox;

    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }

    return cont;
}

//percorre a lista até encontrar o ultimo elemento, assim que encontrar coloca o ponteiro dele para o 
//primeiro elemento após o cabeçalho da lista 2, libera o cabeçalho e a lista 2 após isso
void concatenarLista(Lista* l1, Lista* l2) {
    No* atual = l1->cabeca;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = l2->cabeca->prox;

    free(l2->cabeca);
    free(l2);
}

//Se a lista estiver vazia retorna -1, caso contrario o primeiro elemento é colocado como maior
//após isso percorre a lista comparando o maior com os valores do nó, se o valor for maior substitui o maior
int obterMaior(Lista* lista) {
    No* atual = lista->cabeca->prox;

    if (atual == NULL) {
        printf("Lista vazia!\n");
        return -1; 
    }

    int maior = atual->dado;

    atual = atual->prox;
    while (atual != NULL) {
        if (atual->dado > maior) {
            maior = atual->dado;
        }
        atual = atual->prox;
    }

    return maior;
}

//Se a lista estiver vazia retorna -1, caso contrario o primeiro elemento é colocado como menor
//após isso percorre a lista comparando o menor com os valores do nó, se o valor for menor substitui o menor
int obterMenor(Lista* lista) {
    No* atual = lista->cabeca->prox;

    if (atual == NULL) {
        printf("Lista vazia!\n");
        return -1; 
    }

    int menor = atual->dado;

    atual = atual->prox;
    while (atual != NULL) {
        if (atual->dado < menor) {
            menor = atual->dado;
        }
        atual = atual->prox;
    }

    return menor;
}

//verifica o primeiro nó, compara esse valor nó por nó, caso ache um valor igual modifica o ponteiro 
//do anterior para ser o próximo do valor que estamos, após passar por toda a lista retorna para o segundo valor
//percorre novamente a lista removendo os valores repetidos. Depois vai para o terceiro, quarto e assim por diante 
void removerDuplicatas(Lista* lista) {
    No* atual = lista->cabeca->prox;

    while (atual != NULL) {
        No* anterior = atual;
        No* verificador = atual->prox;

        while (verificador != NULL) {
            if (verificador->dado == atual->dado) {
                anterior->prox = verificador->prox;
                free(verificador);
                verificador = anterior->prox;
            } else {
                anterior = verificador;
                verificador = verificador->prox;
            }
        }

        atual = atual->prox;
    }
}

/*
 * Esta função inverte a ordem dos nós da lista simplesmente encadeada
 * alterando os ponteiros entre eles, sem criar novos nós nem trocar valores.
 * A ideia é percorrer a lista e, a cada nó, fazer com que ele passe a apontar
 * para o nó anterior, em vez do próximo. Para isso, usamos três ponteiros:
 * um para o nó atual sendo processado, um para o anterior (inicialmente NULL),
 * e outro para armazenar temporariamente o próximo nó, já que vamos quebrar
 * a ligação original. No final do percurso, o último nó visitado será o novo
 * primeiro da lista, e o ponteiro do cabeçalho é atualizado para apontar para ele.
 */
void reverterLista(Lista* lista) {
    No* anterior = NULL;
    No* atual = lista->cabeca->prox;
    No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    // Atualiza o ponteiro do cabeçalho
    lista->cabeca->prox = anterior;
}

/*
 * Esta função cria uma nova lista que é uma cópia profunda da lista original.
 * Ou seja, ela cria novos nós, aloca nova memória e copia os valores de cada
 * nó da lista original para a nova lista. Os ponteiros `prox` também são
 * copiados, mas apontando para novos nós (não para os nós originais).
 * A lista resultante é uma cópia independente da lista original.
 */
Lista* copiarLista(Lista* listaOriginal) {
    Lista* novaLista = criarLista();  // Cria uma nova lista vazia
    No* atualOriginal = listaOriginal->cabeca->prox;  // Começa da cabeça da lista original

    // Percorre a lista original e copia cada nó
    while (atualOriginal != NULL) {
        No* novoNo = (No*)malloc(sizeof(No));  // Cria um novo nó
        novoNo->dado = atualOriginal->dado;   // Copia o valor do nó original
        novoNo->prox = NULL;

        // Se a nova lista estiver vazia, insere o primeiro nó
        if (novaLista->cabeca->prox == NULL) {
            novaLista->cabeca->prox = novoNo;
        } else {
            // Caso contrário, insere o novo nó no final
            No* temp = novaLista->cabeca->prox;
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novoNo;
        }

        atualOriginal = atualOriginal->prox;  // Avança para o próximo nó da lista original
    }

    return novaLista;  // Retorna a nova lista criada
}