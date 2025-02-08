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

void vaciarTablero(Tablero &t);

bool esPotenciaDe2(int num);

int redondearPotencia2(int num);

void iniciarTableroAleatorio(Tablero &t,int filasIniciales, int maximo);

bool iniciarTablero(Tablero& t);

void insertarValorTablero(Tablero &t,int fila,int columna,int valor);

bool casillaEstaVacia(Tablero t,int fila,int columna);

int obtenerValorTablero(Tablero t,int fila,int columna);

void vaciarCasillaTablero(Tablero &t,int fila,int columna);

bool columnaEstaLlena(Tablero t,int columna);

int filaPrimeraCasillaVacia(Tablero t,int columna);

bool tableroEstaLleno(Tablero t);

int numeroFilas(Tablero t);

int numeroColumnas(Tablero t);

void fusionarCasillasAdyacentes(Tablero &t,int fila,int columna);

void eliminarCasillasVaciasIntermedias(Tablero &t,int columna);

int obtenerValorMaximo(Tablero t);


#endif
