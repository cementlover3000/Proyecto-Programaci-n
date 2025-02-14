#ifndef TAD_JUEGO_H
#define TAD_JUEGO_H

#include "tablero.h"

struct Juego{
    Tablero tablero;
    int puntuacion;
}

void iniciarJuego(Juego juego);
void jugar(Juego juego);
void terminarJuego(Juego juego);
void refrescarJuego(Juego juego);

#endif // TAD_JUEGO_H
