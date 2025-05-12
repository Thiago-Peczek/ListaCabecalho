#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Função auxiliar para pausar até o usuário pressionar Enter
void pausar() {
    printf("\nPressione Enter para continuar...\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
}

void mostrarMenu() {
    printf("\n====== MENU - Lista com Cabeçalho ======\n");
    printf("1. Inserir no início\n");
    printf("2. Inserir no final\n");
    printf("3. Remover valor\n");
    printf("4. Imprimir lista\n");
    printf("5. Contar elementos\n");
    printf("6. Buscar valor\n");
    printf("7. Verificar se está vazia\n");
    printf("8. Reverter lista\n");
    printf("9. Remover duplicados\n");
    printf("10. Obter maior valor\n");
    printf("11. Obter menor valor\n");
    printf("12. Concatenar com outra lista\n");
    printf("13. Copiar lista\n");
    printf("0. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

void criarECriarLista2(Lista** l2) {
    int n, val;
    *l2 = criarLista();
    printf("Quantos elementos terá a lista 2? ");
    scanf("%d", &n);
    printf("Digite os %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        inserirFim(*l2, val);
    }
}

int main() {
    Lista* lista = criarLista();
    int opcao, valor, resultado;
    Lista* l2 = NULL;

    do {
        mostrarMenu();
        if (scanf("%d", &opcao) != 1) break;
        getchar(); // consome newline
        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir no início: ");
                scanf("%d", &valor);
                inserirInicio(lista, valor);
                printf("Valor %d inserido no início.\n", valor);
                pausar();
                break;
            case 2:
                printf("Digite o valor a inserir no final: ");
                scanf("%d", &valor);
                inserirFim(lista, valor);
                printf("Valor %d inserido no final.\n", valor);
                pausar();
                break;
            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                resultado = remover(lista, valor);
                printf(resultado ? "Valor %d removido com sucesso.\n" : "Valor %d não encontrado.\n", valor);
                pausar();
                break;
            case 4:
                printf("Conteúdo da lista:\n");
                imprimirLista(lista);
                pausar();
                break;
            case 5:
                printf("A lista contém %d elemento(s).\n", contarElementos(lista));
                pausar();
                break;
            case 6:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                resultado = buscar(lista, valor);
                printf(resultado ? "Valor %d encontrado na lista.\n" : "Valor %d não encontrado.\n", valor);
                pausar();
                break;
            case 7:
                printf(estaVazia(lista) ? "A lista está vazia.\n" : "A lista não está vazia.\n");
                pausar();
                break;
            case 8:
                reverterLista(lista);
                printf("Lista invertida.\n");
                imprimirLista(lista);
                pausar();
                break;
            case 9:
                removerDuplicatas(lista);
                printf("Duplicados removidos.\n");
                imprimirLista(lista);
                pausar();
                break;
            case 10:
                resultado = obterMaior(lista);
                if (resultado != -1)
                    printf("Maior valor: %d\n", resultado);
                pausar();
                break;
            case 11:
                resultado = obterMenor(lista);
                if (resultado != -1)
                    printf("Menor valor: %d\n", resultado);
                pausar();
                break;
            case 12:
                criarECriarLista2(&l2);
                concatenarLista(lista, l2);
                printf("Listas concatenadas.\n");
                imprimirLista(lista);
                pausar();
                break;
            case 13: {
                Lista* copia = copiarLista(lista);
                printf("Lista copiada:\n");
                imprimirLista(copia);
                liberarLista(copia);
                pausar();
                break;
            }
            case 0:
                printf("Encerrando programa.\n");
                liberarLista(lista);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                pausar();
        }
    } while (opcao != 0);

    return 0;
}
