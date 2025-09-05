#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"
#include "defines.h"
#include <stdlib.h>
#include <conio.h>

Jogador inicializarJogador(Jogador jogador);
void imprimirJogador(Jogador jogador);
void inicializarMapa(char mapa[LINHAS][COLUNAS], Jogador jogador);
void imprimirMapa(char mapa[LINHAS][COLUNAS]);
Jogador moverJogador(Jogador jogador, char direcao);
void mostrarInventario(Jogador jogador);

int main() {
	
	printf("--------PROCURE A RELIQUIA PARA PODE SAIR DA MASMORA SOMBRIA--------\n\n");
	
Jogador jogador = inicializarJogador(jogador);
char mapa[LINHAS][COLUNAS];

inicializarMapa(mapa, jogador);
imprimirMapa(mapa);
imprimirJogador(jogador);


char comando;

while (1) {
printf("\nComandos (w = pra cima, s = pra baixo, a = para esquerda\n d = para direita, q =sair do game e i = para inventario): ");
comando = getch();  // Captura tecla SEM precisar de ENTER

if (comando == 'q') {
break;
} else if (comando == 'i') {
system("cls");
mostrarInventario(jogador);
continue;
}

system("cls");

jogador = moverJogador(jogador, comando);

if (jogador.y == 2 && jogador.x == 11) {
printf("Voce chegou ao Templo Perdido!\n");
if (jogador.qtdItens < MAX_ITENS) {
strcpy(jogador.inventario[jogador.qtdItens], "Reliquia do Templo");
jogador.qtdItens++;
printf("Voce encontrou uma RELIQUIA! Foi adicionada ao inventario.\n");

}
} else if (jogador.y == 4 && jogador.x == 22) {
printf("Voca chegou a Loja\nA reliquia nao esta aqui\n");
} else if (jogador.y == 6 && jogador.x == 34) {
printf("Voce chegou ao Castelo\nA reliquia nao esta aqui!\n");
} else if (jogador.y == 6 && jogador.x == 39) {
printf("Voce chegou a Saida!\n");


int temRelique = 0;
for (int i = 0; i < jogador.qtdItens; i++) {
    if (strcmp(jogador.inventario[i], "Reliquia do Templo") == 0) {
        temRelique = 1;
        break;
    }
}

if (temRelique) {
    printf("Voce conseguiu a reliquia, ja pode sair!\n");
    break;
} else {
    printf("Voce nao tem a reliquia, nao pode sair.\n");
    continue;
}

}

inicializarMapa(mapa, jogador);
imprimirMapa(mapa);
imprimirJogador(jogador);
}

return FIM;
}

void mostrarInventario(Jogador jogador) {
printf("\n===== INVENTARIO =====\n");
if (jogador.qtdItens == 0) {
printf("O inventario esta vazio.\n");
} else {
for (int i = 0; i < jogador.qtdItens; i++) {
printf("Item %d: %s\n", i + 1, jogador.inventario[i]);
}
}
printf("======================\n");
}




void imprimirJogador(Jogador jogador) {
printf("\n= Jogador: Vida = %d\tMagia = %d 						\n"
"= Level = %d\tOuro = %d\t Pos = (%d,%d)= 					\n",
jogador.vida, jogador.mana, jogador.level,
jogador.ouro, jogador.x, jogador.y);
}

Jogador inicializarJogador(Jogador jogador) {
jogador.vida = JOGADOR_VIDA_INICIAL;
jogador.mana = JOGADOR_MANA_INICIAL;
jogador.ouro = JOGADOR_OURO_INICIAL;
jogador.level = JOGADOR_LEVEL_INICIAL;
jogador.x	= 0;
jogador.y 	= 1;
jogador.qtdItens = 0;

return jogador;
}

void inicializarMapa(char mapa[LINHAS][COLUNAS], Jogador jogador) {
// Preenche o mapa com '.'
for (int i = 0; i < LINHAS; i++) {
for (int j = 0; j < COLUNAS; j++) {
mapa[i][j] = '.';
}
}

// Adiciona locais fixos
mapa[2][11] = 'T'; // Templo
mapa[4][22] = 'L'; // Loja
mapa[6][34] = 'C'; // Castelo
mapa[6][39] = 'S'; //saida
// Posiciona o jogador
mapa[jogador.y][jogador.x] = 'J';

if (jogador.y == 2 && jogador.x == 11) {
}
if(mapa[jogador.y][jogador.x] == mapa[4][22]){
}
if(mapa[jogador.y][jogador.x] == mapa[6][34]){
}
if(mapa[jogador.y][jogador.x] == mapa[6][39]){

}
}

void imprimirMapa(char mapa[LINHAS][COLUNAS]) {
for (int i = 0; i < LINHAS; i++) {
printf("|");
for (int j = 0; j < COLUNAS; j++){
printf("%c", mapa[i][j]);
}
printf("|\n");

}

}

Jogador moverJogador(Jogador jogador, char direcao) {

switch (direcao) {
case 'w': // cima
if(jogador.y > 0) jogador.y--;
break;
case 's': // baixo
if(jogador.y < LINHAS - 1) jogador.y++;
break;
case 'a': // esquerda
if(jogador.x > 0) jogador.x--;
break;
case 'd': // direita
if(jogador.x < COLUNAS - 1) jogador.x++;
break;
default:
printf("Comando invalido!!\n");
}
return jogador;
}

