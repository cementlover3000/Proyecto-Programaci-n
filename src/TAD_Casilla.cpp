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

bool estaVacia(Casilla c){
    bool vacia;
    if(c.ocupadas==0){
   	 vacia=true;
    }
    else{
   	 vacia=false;
    }
    return vacia;
}

void vaciarCasilla(Casilla &c){
    c.ocupadas=0;
}

void insertarValorCasilla(Casilla &c, int n){
    c.vector[0]=n;
    c.ocupadas=c.ocupadas+1;
}

int devolverValorCasilla(Casilla c){
    int valor;
    valor=c.vector[0];
    return valor;
}

