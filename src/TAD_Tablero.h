#ifndef TAD_TABLERO_H_
#define TAD_TABLERO_H
#include <iostream>
#include "TAD_Casilla.h"
using namespace std;

const int FILAS = 7;
const int COLUMNAS = 7;;
typedef Casilla tMatriz[FILAS][COLUMNAS];
struct Tablero{
    tMatriz tablero;
    int ocupadas;
    int filas;
    int columnas;
};

void vaciarTablero(Tablero& t);

void iniciarTableroAleatorio (Tablero &t, int filas, int columnas, int filasIniciales, int maximo);

void iniciarTablero(Tablero &t);

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

int obtenerPuntuacionTablero (Tablero t);

#endif








