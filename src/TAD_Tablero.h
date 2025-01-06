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

//PRE:{n tiene que ser múltiplo de 2, 0<=fila<7, 0<=columna<7}
//POST:{inserta el valor n en la casilla del tablero indicada por fila y columna}
void insertarValorTablero(Tablero &t,int n, int fila,int columna);

//PRE:{0<=fila<7, 0<=columna<7, la casilla debe de estar llena}
//POST:{devuelve el valor de la casilla del tablero indicada por fila y columna}
int obtenerValorTablero(Tablero t,int fila,int columna);

//PRE:{ 0<=columna<7}
//POST:{devuelve true si la columna está llena y false en caso contrario}
bool columnaEstaLlena(Tablero t,int columna);

//PRE:{}
//POST:{devuelve true si el tablero está lleno y false en caso contrario}
bool tableroEstaLleno(Tablero t);

//PRE:{0<=columna<7}
//POST:{elimina las casillas vacías intermedias y desplaza los elementos de una determinada casilla}
void eliminarCasillasVaciasIntermedias(Tablero &t, int columna);


