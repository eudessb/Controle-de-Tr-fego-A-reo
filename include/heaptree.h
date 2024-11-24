#ifndef FUNCTIONS_C
#define FUNCTIONS_C

typedef struct Aeronave
{
    char identificador[50];
    int combustivel;
    int horario;
    int tipo;
    int emergencia;
    int prioridade ;
} Aeronave;

Aeronave calcular_prioridade (Aeronave aeronave);

void inserir_aeronave();

void carregar_aeronaves();

void consultar_mprioridade();

void remover_mprioridade();

void atualizar_prioridade();

void exibir();

#endif