#ifndef TAD_JUEGO_H
#define TAD_JUEGO_H
#include "TAD_Tablero.h"

struct Juego{
	Tablero tablero;
	int puntuacion;;
};

void iniciarJuego(Juego &g);
void jugar(Juego &g, string &mensaje, bool &salir, int &valor, int &fila, int &columna);
void terminarJuego(Juego g, string mensaje);
void refrescarJuego(Juego &g, string &mensaje, bool &salir, int &valor, int &fila, int &columna );

#endif




