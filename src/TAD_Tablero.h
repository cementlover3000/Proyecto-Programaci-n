#ifndef TAD_TABLERO_H_
#define TAD_TABLERO_H_
#include <iostream>
#include "TAD_Casilla.h"
using namespace std;

const int FILAS=6;
const int COLUMNAS=5;
typedef Casilla tMatriz[FILAS][COLUMNAS];
struct Tablero{
    tMatriz tablero;
    int ocupadas;
};

void iniciarTablero(Tablero &t);

void insertarValorTablero(Tablero &t,int flia,int columna);

bool casillaEstaVacia(Tablero t,int fila,int columna);

int obtenerValorCasilla(Tablero t,int fila,int columna);

void vaciarCasillaTablero(Tablero &t,int fila,int columna);

bool columnaEstaLlena(Tablero t,int columna);

int filaPrimeraCasillaVacia(Tablero t,int columna);

bool tableroEstaLleno(Tablero t);

void numeroFilas(Tablero t);

void numeroColumnas(Tablero t);

void fusionarCasillasAdyacentes(Tablero &t,int fila,int columna);

void eliminarCasillasVaciasIntermedias(Tablero &t,int columna);

int obtenerValorMaximo(Tablero t);


#endif



