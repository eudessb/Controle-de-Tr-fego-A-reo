/**
 * Declaração de todas as funções
 * */
#ifndef FUNCTIONS_C
#define FUNCTIONS_C

typedef struct Aeronave
{
    char identificador[50];
    int combustivel;
    int horario;
    int tipo;
    int emergencia;
    int prioridade;
} Aeronave;

typedef struct HEAP
{
    Aeronave *aeronaves;
    int tamanho_maximo;
    int tamanho_atual;
} HEAP;

void construir_maxheap(HEAP *heap);

void heapify(HEAP *heap, int i);

void calcular_prioridade(Aeronave *aeronave);

void trocar_elementos(Aeronave *a, Aeronave *b);

HEAP *inicializar_heap(int tamanho_array);

void inserir_aeronave(HEAP *heap, Aeronave *nova_aeronave);

void carregar_aeronaves(const char *csvfile, HEAP *heap);

void consultar_maior_prioridade(HEAP *heap);

void remover_mprioridade(HEAP *heap);

void atualizar_prioridade(HEAP *heap);

void esvaziar(HEAP *heap);

void exibir(HEAP *heap);

#endif