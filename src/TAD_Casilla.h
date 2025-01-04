/*
 *
 * FUNDAMENTOS DE PROGRAMACIÓN
 *  Curso 2024/2025

    Nombre: TAD_Casilla.cpp
    Descripción: Especificación del TAD Casilla para el proyecto Number Tiles
    		       encargado de gestionar la información de una casilla del tablero.

    Autor: Alejandro Bravo González y Alejandro Pulido Rodríguez

 *
 */

#ifndef NUMBERTILES_H_
#define NUMBERTILES_H_

//PRE:{}
//POST:{inicia la casilla vacia}

void iniciar(Casilla &c);

//PRE:{}
//POST:{devuelve true si la casilla está vacía y false si está llena}

bool estaVacia(Casilla c);

//PRE:{}
//POST:{borra la información almacenada en una casilla}


#endif /* NUMBERTILES_H_ */


