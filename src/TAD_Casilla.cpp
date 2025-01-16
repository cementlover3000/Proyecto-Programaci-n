/*
 *
 * FUNDAMENTOS DE PROGRAMACIÓN
 *  Curso 2024/2025

	Nombre: TAD_Casilla.cpp
	Descripción: Implemetación del TAD Casilla para el proyecto Number Tiles
   		    	encargado de gestionar la información de una casilla del tablero.

	Autor: Alejandro Bravo González y Alejandro Pulido Rodríguez

 *
 */

#include <iostream>
#include "TAD_Casilla.h"
using namespace std;


void iniciar(Casilla &c){
	c.ocupadas=0;
}

bool estaVacia(Casilla &c) {
   return c.ocupadas == 0;
}

void vaciarCasilla(Casilla &c){
	c.ocupadas=0;
}

void insertarValorCasilla(Casilla &c, int n) {
	if (c.ocupadas < MAX) {
    	c.vector[c.ocupadas] = n; // Almacena el valor en la posición ocupada
    	c.ocupadas++;
	}
}

int devolverValorCasilla(Casilla &c) {
	if (c.ocupadas > 0) {
    	return c.vector[0]; // Devuelve el valor almacenado
	} else {
    	return -1; // O algún valor que indique error
	}
}
