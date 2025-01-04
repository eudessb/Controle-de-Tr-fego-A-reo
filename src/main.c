/**
 * Implementação de todas as funções usadas
 *
 * */
#include "../include/heaptree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    HEAP *raiz = NULL;
    raiz = inicializar_heap();
    carregar_aeronaves("data/voos.csv", raiz);
    int variavel;
    do
    {
        printf("Digite 1 para ver o menu com todas as opções, digite 0 caso deseje encerrar o programa\n");
        scanf("%d",&variavel);
        switch (variavel)
        {
        case 0:
            break;
        case 1:
            exibir_menu();
            break;
        case 2:
            exibir(raiz);
            break;
        case 3:
            atualizar_prioridade(raiz);
            break;
        case 4:
            consultar_maior_prioridade(raiz);
            break;
        case 5:
            remover_mprioridade(raiz);
            break;
        default:
            printf("OPÇÃO INVÁLIDA\n");
            break;
        }

    } while (variavel != 0);
    esvaziar_heap(raiz);
    return 0;
}