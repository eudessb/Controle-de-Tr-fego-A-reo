#include "include/heaptree.h"
#include <stdio.h>
#include <stdlib.h>

int heap[99];
int tamanho =0;
void construir_maxheap(int raiz)
{
   
    int pai = raiz/2;
    int filho_esquerdo = pai *2;
    int filho_direito = pai *2 +1;
    
}
void inserir_aeronave(Aeronave aeronave)
{
    heap[tamanho] = aeronave.identificador;
    int i = tamanho;
    tamanho++;

    while (0 < i && heap[(i -1 )/2] < heap[i])
    {
        int temp = heap[(i-1)/2];
        heap[(i-1)/2] = heap[i];
        heap[i]= temp;
        i = (i-1)/2;
    }
};
//99% de certeza que está errada/é desnecessária.
Aeronave calcular_prioridade(Aeronave aeronave)
{
    aeronave.prioridade =  (1000  - aeronave.combustivel) + (1440 - aeronave.horario) + 500 *(aeronave.tipo) + 5000 *(aeronave.emergencia);
    return aeronave;
}
void carregarAeronaves(char csvfile);

void consultar_mprioridade();

void remover_mprioridade();

void atualizar_prioridade();

void exibir();