/*
 *
 * FUNDAMENTOS DE PROGRAMACIÓN
 *  Curso 2024/2025

	Nombre: TAD_Casilla.h
	Descripción: Especificación del TAD Casilla para el proyecto Number Tiles
	encargado de gestionar la información de una casilla del tablero.

	Autor: Alejandro Bravo González y Alejandro Pulido Rodríguez

 *
 */

#ifndef TAD_CASILLA_H_
#define TAD_CASILLA_H_

#include <iostream>
using namespace std;

const int MAX=1;
typedef int tVector[MAX];
struct Casilla{
	tVector vector;
	int ocupadas;
};

//PRE:{}
//POST:{inicia la casilla vacia}
void iniciar(Casilla &c);

//PRE:{}
//POST:{devuelve true si la casilla está vacía y false si está llena}
bool estaVacia(Casilla c);

//PRE:{}
//POST:{borra la información almacenada en una casilla}
void vaciarCasilla(Casilla &c);

//PRE:{}
//POST:{inserta el valor n en la casilla}
void insertarValorCasilla(Casilla &c, int n);

//PRE:{}
//POST:{devuelve el valor almacenado en la casilla}
int devolverValorCasilla(Casilla c);

#endif




