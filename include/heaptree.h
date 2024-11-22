#ifndef FUNCTIONS_C
#define FUNCTIONS_C

typedef struct Aeronave
{
    char identificador[50];
    int combustivel;
    int horario;
    int tipo;
    int emergencia;
    int prioridade = (1000 - combustivel) + (1440 - horario) + 500 *(tipo) + 5000 *(emergencia)   ;
} Aeronave;

typedef struct No
{
    Aeronave aeronave;
    struct No* esquerda;
    struct No* direita;

}No;


/*

void consultar_prioridade ()


No* criar_no(int valor) {

    char[50] identificador;
    float combustível
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}
*/

#endif