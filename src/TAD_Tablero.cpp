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
#include "TAD_Casilla.h"
#include "TAD_Tablero.h"
using namespace std;



void insertarValorTablero(Tablero &t,int n, int fila,int columna){
    insertarValorCasilla(t.tablero[fila][columna], n);
    t.ocupadas=t.ocupadas+1;
}

int obtenerValorTablero(Tablero t,int fila,int columna){
    int valor;
    valor = devolverValorCasilla(t.tablero[fila][columna]);
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

bool casillaEstaVacia(Tablero t, int fila, int columna){
    bool vacia;
    if(estaVacia(t.tablero[fila][columna])){
   	 vacia=true;
    }
    else{
   	 vacia=false;
    }
    return vacia;
}

void vaciarCasillaTablero(Tablero &t, int fila, int columna){
    int i;
    for(i=fila+1;i<FILAS;i++){
   	 t.tablero[i-1][columna]=t.tablero[i][columna];
    }
    t.ocupadas=t.ocupadas-1;
}

int filaPrimeraCasillaVacia(Tablero t,int columna){
    int fila;
    int i;
    i=0;
    bool vacia;
    vacia=false;
    while(i<FILAS && !vacia){
   	 if(estaVacia(t.tablero[i][columna])){
   		 vacia=true;
   	 }
     else{
         i=i+1;

     }
    }
    fila=i;
    return fila;
}

int numeroFilas(Tablero t){
    return FILAS;
}

int numeroColumnas(Tablero t){
    return COLUMNAS;
}

int maximoValorTablero(Tablero t){
    int i;
    int j;
    int max;
    max=0;
    for(i=0;i<COLUMNAS;i++){
   	 for(j=0;j<FILAS;j++){
   		 if(devolverValorCasilla(t.tablero[i][j])>max){
   			 max=devolverValorCasilla(t.tablero[i][j]);
   		 }
   	 }
    }
    return max;
}







