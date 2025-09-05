#ifndef STRUCTS_H
#define STRUCTS_H

#include "defines.h"  // Para acessar MAX_ITENS, se necess�rio

typedef struct {
    int vida;
    int mana;
    int ouro;
    int level;
    int x; // posi��o x no mapa
    int y; // posi��o y no mapa
    int qtdItens;
    char inventario[MAX_ITENS][50]; // at� 50 caracteres por item
} Jogador;

#endif // STRUCTS_H

