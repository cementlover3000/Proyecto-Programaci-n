/*
 *
 * FUNDAMENTOS DE PROGRAMACIÓN
 *  Curso 2024/2025

    Nombre: TAD_Tablero.cpp
    Descripción: Implemetación del TAD Tablero para el proyecto Number Tiles
    encargado de gestionar la información almacenada en el tablero.
    		       
    Autor: Alejandro Bravo González y Alejandro Pulido Rodríguez

 *
 */

#include <iostream>
#include "TAD_Tablero.h"
using namespace std;



void insertarValorTablero(Tablero &t,int n, int fila,int columna){
    insertarValorCasilla(t.tablero[fila][columna])=n;
    t.ocupadas=t.ocupadas+1;
}

int obtenerValorTablero(Tablero t,int fila,int columna){
    int valor;
    valor=obtenerValorCasilla(t.tablero[fila][columna]);
    return valor;
}

bool columnaEstaLlena(Tablero t,int columna){
    bool estaLlena;
    estaLlena=true;
    int i;
    for(i=0;i<COLUMNAS;i++){
   	 if(estaVacia(t.tablero[i][columna])){
   		 estaLlena=false;
   	 }
    }
    return estaLlena;
}

bool tableroEstaLleno(Tablero t){
    bool estaLleno;
    estaLleno=true;
    int i;
    int j;
    for(i=0;i<COLUMNAS;i++){
   	 for(j=0;j<FILAS;j++){
   		 if(estaVacia(t.tablero[i][j])){
   			 estaLleno=false;
   		 }
   	 }
    }
    return estaLleno;
}

void eliminarCasillasVaciasIntermedias(Tablero &t, int columna){
    int i;
    int cuantos;
    cuantos=0;
    for(i=0;i<FILAS;i++){
   	 if(estaVacia(t.tablero[i][columna])){
   		 cuantos=cuantos+1;
   	 }
   	 else{
   		 t.tablero[i-cuantos][columna]=t.tablero[i][columna];
   	 }
    }
    t.ocupadas=t.ocupadas-cuantos;
}



