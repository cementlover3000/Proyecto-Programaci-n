/*
 *
 * FUNDAMENTOS DE PROGRAMACIÓN
 *  Curso 2024/2025

    Nombre: TAD_Tablero.h
    Descripción: Especificación del TAD Tablero para el proyecto Number Tiles
    		       encargado de gestionar la información del tablero.

    Autor: Alejandro Bravo González y Alejandro Pulido Rodríguez

 *
 */

#ifndef TAD_TABLERO_H_
#define TAD_TABLERO_H_
#include "TAD_Casilla.h"

const int FILAS=7;
const int COLUMNAS=7;
typedef Casilla tMatriz[FILAS][COLUMNAS];
struct Tablero{
    tMatriz tablero;
    int ocupadas;
};

//PRE:{n tiene que ser múltiplo de 2, 0<=fila<FILAS, 0<=columna<COLUMNAS}
//POST:{inserta el valor n en la casilla del tablero indicada por fila y columna}
//Complejidad: O(1)
void insertarValorTablero(Tablero &t,int n, int fila,int columna);

//PRE:{0<=fila<7, 0<=columna<7, la casilla debe de estar llena}
//POST:{devuelve el valor de la casilla del tablero indicada por fila y columna}
//Complejidad: O(1)
int obtenerValorTablero(Tablero t,int fila,int columna);

//PRE:{ 0<=columna<7}
//POST:{devuelve true si la columna está llena y false en caso contrario}
//Complejidad: O(n)
bool columnaEstaLlena(Tablero t,int columna);

//PRE:{}
//POST:{devuelve true si el tablero está lleno y false en caso contrario}
//Complejidad: O(n²)
bool tableroEstaLleno(Tablero t);

//PRE:{0<=columna<7}
//POST:{elimina las casillas vacías intermedias y desplaza los elementos de una determinada casilla}
//Complejidad: O(n)
void eliminarCasillasVaciasIntermedias(Tablero &t, int columna);


bool casillaEstaVacia(Tablero t, int fila, int columna);

void vaciarCasillaTablero(Tablero &t, int fila, int columna);

int filaPrimeraCasillaVacia(Tablero t,int columna);

int numeroFilas(Tablero t);

int numeroColumnas(Tablero t);

int maximoValorTablero(Tablero t);




#endif
