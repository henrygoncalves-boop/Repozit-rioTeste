#ifndef STRUCTS_H
#define STRUCTS_H

#include "defines.h"  // Para acessar MAX_ITENS, se necessário

typedef struct {
    int vida;
    int mana;
    int ouro;
    int level;
    int x; // posição x no mapa
    int y; // posição y no mapa
    int qtdItens;
    char inventario[MAX_ITENS][50]; // até 50 caracteres por item
} Jogador;

#endif // STRUCTS_H

