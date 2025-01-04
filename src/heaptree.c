/**
 * Todas as funções usadas estão neste arquivo
 */
#include "heaptree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define TAMANHO_PADRAO 10

void heapify(HEAP *heap, int i)
{
    int maior = i;
    int esq = 2 * i + 1; // Filho esquerdo
    int dir = 2 * i + 2; // Filho direito

    // Verifica se o filho esquerdo existe e é maior que o nó atual
    if (esq < heap->tamanho_atual && heap->aeronaves[esq].prioridade > heap->aeronaves[maior].prioridade)
        maior = esq;

    // Verifica se o filho direito existe e é maior que o nó atual ou o filho esquerdo
    if (dir < heap->tamanho_atual && heap->aeronaves[dir].prioridade > heap->aeronaves[maior].prioridade)
        maior = dir;

    // Se o maior não for o nó atual, faz a troca
    if (maior != i)
    {
        trocar_elementos(&heap->aeronaves[i], &heap->aeronaves[maior]);
        heapify(heap, maior);
    }
}

void construir_maxheap(HEAP *heap)
{
    for (int i = heap->tamanho_atual / 2 - 1; i >= 0; i--)
    {
        heapify(heap, i);
    }
}
/**
 * Este método inicializa a heap usando o tamanho padrão, dependendo da quantidade de aeronaves ela 
 * aumenta dinamicamente, a necessidade de aumento é analisada no método inserir_aeronave.
 */
HEAP *inicializar_heap()
{

    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    if (!heap)
    {
        perror("Falha ao alocar memória\n");
        exit(EXIT_FAILURE);
    }

    heap->aeronaves = (Aeronave *)malloc(sizeof(Aeronave) * TAMANHO_PADRAO);
    if (!heap->aeronaves)
    {
        printf("Falha ao alocar memória!");
        free(heap);
        exit(EXIT_FAILURE);
    }
    heap->tamanho_inicial = 10;
    heap->tamanho_atual = 0;
    printf("Heap inicializado com sucesso!\n");
    return heap;
}
/**
 * Este método insere uma aeronave na árvore na última posição da estrutura heap, incrementa o tamanho atual da estrutura
 * e ajusta a estrutura para manter a prioridade da heap.
 */
void inserir_aeronave(HEAP *heap, Aeronave *nova_aeronave)
{
    if (heap->tamanho_atual >= heap->tamanho_inicial)
    {
        int tamanho_maximo = heap->tamanho_inicial * 2;
        heap->aeronaves = realloc(heap->aeronaves, sizeof(Aeronave) * tamanho_maximo);
        if (heap->aeronaves == NULL)
        {
            exit(EXIT_FAILURE);
        }
        heap->tamanho_inicial = tamanho_maximo;
    }
    calcular_prioridade(nova_aeronave);
    int i = heap->tamanho_atual;
    heap->aeronaves[i] = *nova_aeronave;
    heap->tamanho_atual++;

    while (0 < i && heap->aeronaves[(i - 1) / 2].prioridade < heap->aeronaves[i].prioridade)
    {
        trocar_elementos(&heap->aeronaves[i], &heap->aeronaves[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
/**
 * Dá ao usuário a opção de alterar os dados da aeronave que ele selecionou. A seleção é feita através da inserção
 * do código da aeronave, após a inserção de todos os dados a prioridade da aeronave é recalculada e a aeronave reinserida
 * na heap.
 */
void inserir_manualmente(HEAP *heap)
{
    Aeronave aeronave_temporaria;
    printf("Insira o identificador da aeronave:\n");
    getchar();
    fgets(aeronave_temporaria.identificador, sizeof(aeronave_temporaria.identificador), stdin);
    aeronave_temporaria.identificador[strcspn(aeronave_temporaria.identificador, "\n")] = '\0';

    printf("Insira o combustível da aeronave:\n");
    getchar();
    scanf("%d", &aeronave_temporaria.combustivel);

    printf("Insira o horário previsto de chegada ou partida (em minutos do dia) da aeronave:\n");
    getchar();
    scanf("%d", &aeronave_temporaria.horario);

    printf("Insira o tipo de operação (0 para decolagem, 1 para pouso) da aeronave:\n");
    getchar();
    scanf("%d", &aeronave_temporaria.tipo);

    printf("Insira 1 caso a aeronave esteja em estado de emergência e 0 caso não esteja:\n");
    getchar();
    scanf("%d", &aeronave_temporaria.emergencia);

    inserir_aeronave(heap, &aeronave_temporaria);
}
void trocar_elementos(Aeronave *a, Aeronave *b)
{
    Aeronave temp = *a;
    *a = *b;
    *b = temp;
}
void calcular_prioridade(Aeronave *aeronave)
{
    if (aeronave == NULL)
    {
        printf("Erro: o ponteiro da aeronave é nulo!\n");
        return;
    }
    aeronave->prioridade = (1000 - aeronave->combustivel) + (1440 - aeronave->horario) + 500 * (aeronave->tipo) + 5000 * (aeronave->emergencia);
}
/**
 * Este método deve carregar os dados de um arquivo csv é inseri-los numa estrutura heap, caso o arquivo esteja vazio deve retornar a heap intacta
 * caso contrário ele inse
 */
void carregar_aeronaves(const char *csvfile, HEAP *heap)
{
    char linha[1024];
    FILE *file = fopen(csvfile, "r");
    if (file == NULL)
    {
        perror("Não foi possível ler o arquivo\n");
        return;
    }
    while (fgets(linha, sizeof(linha), file))
    {
        Aeronave *nova_aeronave = malloc(sizeof(Aeronave));
        if (nova_aeronave == NULL)
        {
            perror("Falha ao alocar memória");
            continue;
        }

        // Copia o identificador
        char *token = strtok(linha, ",");
        if (token == NULL)
        {
            free(nova_aeronave);
            continue;
        }
        strcpy(nova_aeronave->identificador, token);
        // Copia o combustível
        token = strtok(NULL, ",");
        if (token == NULL)
        {
            free(nova_aeronave);
            continue;
        }
        nova_aeronave->combustivel = atoi(token);
        // Copia o horário
        token = strtok(NULL, ",");
        if (token == NULL)
        {
            free(nova_aeronave);
            continue;
        }
        nova_aeronave->horario = atoi(token);
        // Copia o tipo
        token = strtok(NULL, ",");
        if (token == NULL)
        {
            free(nova_aeronave);
            continue;
        }
        nova_aeronave->tipo = atoi(token);
        // Copia a emergência
        token = strtok(NULL, ",");
        if (token == NULL)
        {
            free(nova_aeronave);
            continue;
        }
        nova_aeronave->emergencia = atoi(token);
        inserir_aeronave(heap, nova_aeronave);
        free(nova_aeronave);
    }
    fclose(file);
}
//Remove a raiz (aeronave com maior prioridade) e reorganiza a heap.
void remover_mprioridade(HEAP *heap)
{
    if (heap->tamanho_atual == 0)
    {
        printf("Árvore vazia\n");
        return;
    }
    printf("removendo elemento: %s \n", heap->aeronaves[0].identificador);
    heap->aeronaves[0] = heap->aeronaves[heap->tamanho_atual - 1];
    heap->tamanho_atual--;
    heapify(heap, 0); // heapify para manter a árvore organizada
}
// Atualiza a prioridade de uma aeronave, alterando o seus dados e recalculando sua posição na heap
void atualizar_prioridade(HEAP *heap)
{
    char identificador[50];
    printf("Insira o identificador da aeronave:\n");
    getchar(); // Limpa o buffer
    fgets(identificador, sizeof(identificador), stdin);
    identificador[strcspn(identificador, "\n")] = '\0';

    int indice = -1;
    for (int i = 0; i < heap->tamanho_atual; i++)
    {
        if (strcmp(heap->aeronaves[i].identificador, identificador) == 0)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("Aeronave com identificador %s não encontrada.\n", identificador);
        return;
    }

    printf("Insira o combustível da aeronave (Até 1000):\n");
    scanf("%d", &heap->aeronaves[indice].combustivel);

    printf("Insira o horário previsto de chegada ou partida (em minutos do dia):\n");
    scanf("%d", &heap->aeronaves[indice].horario);

    printf("Insira o tipo de operação (0 para decolagem, 1 para pouso):\n");
    scanf("%d", &heap->aeronaves[indice].tipo);

    printf("Insira 1 caso a aeronave esteja em estado de emergência e 0 caso não esteja:\n");
    scanf("%d", &heap->aeronaves[indice].emergencia);
    calcular_prioridade(&heap->aeronaves[indice]);
    // Ajustar a posição da aeronave, subindo no heap se necessário
    if (indice > 0 && heap->aeronaves[(indice - 1) / 2].prioridade < heap->aeronaves[indice].prioridade)
    {

        while (indice > 0 && heap->aeronaves[(indice - 1) / 2].prioridade < heap->aeronaves[indice].prioridade)
        {
            trocar_elementos(&heap->aeronaves[indice], &heap->aeronaves[(indice - 1) / 2]);
            indice = (indice - 1) / 2; // Mover para o pai
        }
    }
    else
    {
        heapify(heap, indice); // Ajustar a posição, movendo para baixo
    }
}
//Exibir todos os elementos da heap, do 0, a raíz, até o último elemento;
void exibir(HEAP *heap)
{
    if (heap == NULL || heap->tamanho_atual == 0)
    {
        printf("Heao vazia ou vazia.\n");
    }
    if (heap != NULL)
    {
        printf("Aeronaves:\n\n");
        for (int i = 0; i < heap->tamanho_atual; i++)
        {
            printf("[%d] %s %d\n", i, heap->aeronaves[i].identificador, heap->aeronaves[i].prioridade);
        }
    }
}
//Retorna o elemento com maior prioridade (raiz).
void consultar_maior_prioridade(HEAP *heap)
{
    printf("A aeronave %s é a aeronave com maior prioridade\n\n", heap->aeronaves[0].identificador);
}
//Esvazia a heap para evitar vazamentos de memória
void esvaziar_heap(HEAP *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    free(raiz->aeronaves);
    free(raiz);
}
void exibir_menu()
{
    printf("\n==== Controlador de Tráfego Aéreo====\n");
    printf("0. ENCERRAR PROGRAMA.\n");
    printf("1. EXIBIR O MENU.\n");
    printf("2. EXIBIR HEAP.\n");
    printf("3. ATUALIZAR PRIORIDADE.\n");
    printf("4. EXIBIR AERONAVE COM MAIOR PRIORIDADE\n");
    printf("5. REMOVER AERONAVE COM MAIOR PRIORIDADE.\n");
}