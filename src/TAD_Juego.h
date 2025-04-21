#ifndef TAD_JUEGO_H
#define TAD_JUEGO_H

#include "tablero.h"

struct Juego{
    Tablero tablero;
    int puntuacion;
}

void iniciarJuego(Juego &g);
void jugar(Juego g);
void terminarJuego(Juego g);
void refrescarJuego(Juego g);

#endif // TAD_JUEGO_H
