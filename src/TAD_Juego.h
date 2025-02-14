#ifndef TAD_JUEGO_H
#define TAD_JUEGO_H

#include "tablero.h"

typedef struct {
    Tablero tablero;
    int puntuacion;
} Juego;

void iniciarJuego(Juego juego);
void jugar(Juego juego);
void terminarJuego(Juego juego);
void refrescarJuego(Juego juego);

#endif // TAD_JUEGO_H
