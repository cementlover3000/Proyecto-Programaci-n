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

#ifndef NUMBERTILES_H_
#define NUMBERTILES_H_

const int FILAS=7;
const int COLUMNAS=7;
typedef Casilla tMatriz[FILAS][COLUMNAS];
struct Tablero{
    tMatriz tablero;
    int ocupadas;
};

//PRE:{n tiene que ser múltiplo de 2, 0<=fila<7, 0<=columna<7}
//POST:{inserta el valor n en la casilla del tablero indicada por fila y columna}
//Complejidad O(1)
void insertarValorTablero(Tablero &t,int n, int fila,int columna);

//PRE:{0<=fila<7, 0<=columna<7, la casilla debe de estar llena}
//POST:{devuelve el valor de la casilla del tablero indicada por fila y columna}
//Complejidad O(1)
int obtenerValorTablero(Tablero t,int fila,int columna);

//PRE:{ 0<=columna<7}
//POST:{devuelve true si la columna está llena y false en caso contrario}
//Complejidad O(n)
bool columnaEstaLlena(Tablero t,int columna);

//PRE:{}
//POST:{devuelve true si el tablero está lleno y false en caso contrario}
//Complejidad O(n^2)
bool tableroEstaLleno(Tablero t);

//PRE:{0<=columna<7}
//POST:{elimina las casillas vacías intermedias y desplaza los elementos de una determinada casilla}
//Complejidad O(n)
void eliminarCasillasVaciasIntermedias(Tablero &t, int columna);

//PRE:{0<=fila<7, 0<=columna<7}
//POST:{devuelve true si la casilla está vacía y false en caso contrario}
//Complejidad O(1)
bool casillaEstaVacia(Tablero t, int fila, int columna);

//PRE:{0<=fila<7, 0<=columna<7}
//POST:{elimina el valor que se encuentra en la casilla determinada por fila y columna y deplaza los 
//elementos de la columna que se encuentran encima de ella hacia abajo}
//Complejidad O(n)
void vaciarCasillaTablero(Tablero &t, int fila, int columna);

//PRE:{0<=columna<7, para que el módulo funcione, la columna no puede estar llena}
//POST:{devuelve la fila de la primera casilla vacía de la columna dada}
//Complejidad O(n)
int filaPrimeraCasillaVacia(Tablero t,int columna);

//PRE:{}
//POST:{devuelve el número de filas que hay en el tablero}
//Complejidad O(1)
int numeroFilas(Tablero t);

//PRE:{}
//POST:{devuelve el número de columnas que hay en el tablero}
//Complejidad O(1)
int numeroColumnas(Tablero t);

//PRE:{}
//POST:{rastrea todas las casillas del tablero en busca del valor más grande, y lo devuelve}
//Complejidad O(n^2)
int maximoValorTablero(Tablero t);
