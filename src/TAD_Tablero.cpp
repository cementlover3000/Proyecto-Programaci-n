#include <iostream>
#include <fstream>
#include <cmath>
#include "TAD_Tablero.h"
using namespace std;

void vaciarTablero(Tablero& t){
    int i;
    int j;
	for (i = 0; i < FILAS; ++i){
    	for (j = 0; j < COLUMNAS; ++j){
        	vaciarCasillaTablero(t, i, j);
    	}
	}
	t.ocupadas = 0;
}


void iniciarTableroAleatorio (Tablero &t, int filas, int columnas, int filasIniciales, int maximo) {
    srand(time(nullptr));
    int i;
    int j;
    for (i = 0; i < filasIniciales; i++) {
   	 for (j = 0; j < columnas; j++) {
   		 insertarValorTablero(t, i, j, pow(2,rand()%maximo + 1));
   	 }
    }
}

void iniciarTablero(Tablero& t) {
	ifstream archivo("numberTiles.cnf");

	int filas, columnas, comoIniciar, filasIniciales;
	archivo >> filas >> columnas >> comoIniciar >> filasIniciales;

	vaciarTablero(t);
	t.ocupadas = 0;
	t.filas = filas;
	t.columnas = columnas;

	if (comoIniciar == 0) {
   	 int i;
   	 int j;
    	for (i = 0; i < filasIniciales; i++) {
        	for (j = 0; j < columnas; j++) {
            	int valor;
            	archivo >> valor;
            	insertarValorTablero(t, i, j, valor);
        	}
    	}
	}
	else {
    	iniciarTableroAleatorio(t, filas, columnas, filasIniciales, comoIniciar);
	}
}


void insertarValorTablero(Tablero &t, int fila, int columna, int valor){
    vaciarCasillaTablero(t,fila,columna);
	insertarValorCasilla(t.tablero[fila][columna], valor);
	t.ocupadas = t.ocupadas + 1;
}


bool casillaEstaVacia(Tablero t, int fila, int columna) {
    return estaVacia(t.tablero[fila][columna]);
}

int obtenerValorTablero(Tablero t, int fila, int columna) {
    int resultado;
    if(casillaEstaVacia(t, fila, columna)){
   	 resultado = 0;
    }
    else{
   	 resultado = obtenerValorCasilla(t.tablero[fila][columna]);
    }
    return resultado;
}

void vaciarCasillaTablero(Tablero &t, int fila, int columna) {
    if(!casillaEstaVacia(t, fila, columna)){
   	 vaciarCasilla(t.tablero[fila][columna]);
   	 t.ocupadas = t.ocupadas-1;
    }
}

bool columnaEstaLlena(Tablero t, int columna) {
    bool estaLlena;
    int fila;
    estaLlena = true;
    for (fila = 0; fila < t.filas; fila++) {
   	 if (casillaEstaVacia(t, fila, columna)) {
   		 estaLlena = false;
   	 }
    }
    return estaLlena;
}

int filaPrimeraCasillaVacia(Tablero t, int columna) {
	int fila;
	bool estaVacia;
	estaVacia = false;
    if (columnaEstaLlena(t, columna)) {
  	  fila = -1;
	}
	else{
        fila = 0;
        while(fila < t.filas && !estaVacia){
        	if (casillaEstaVacia(t, fila, columna)) {
       		  estaVacia = true;
        	}
        	else{
     		   fila++;
        	}
        }
	}
	return fila;
}

bool tableroEstaLleno(Tablero t) {
    return t.ocupadas == t.filas * t.columnas;
}



void fusionarCasillasAdyacentes(Tablero &t, int fila, int columna) {
    int valorActual;
    valorActual = obtenerValorTablero(t, fila, columna);
    int sumaFusionada;
    sumaFusionada = valorActual;

    int valorArriba;
    valorArriba = obtenerValorTablero(t, fila - 1, columna);
    if (valorArriba == valorActual) {
   	 sumaFusionada = sumaFusionada + valorArriba;
   	 vaciarCasillaTablero(t, fila - 1, columna);
   	 t.ocupadas=t.ocupadas-1;
   }

   int valorAbajo;
   valorAbajo = obtenerValorTablero(t, fila + 1, columna);
   if (valorAbajo == valorActual) {
   	 sumaFusionada = sumaFusionada + valorAbajo;
   	 vaciarCasillaTablero(t, fila + 1, columna);
   	 t.ocupadas=t.ocupadas-1;
   }

   int valorIzquierda;
   valorIzquierda = obtenerValorTablero(t, fila, columna - 1);
   if (valorIzquierda == valorActual) {
   	 sumaFusionada = sumaFusionada + valorIzquierda;
   	 vaciarCasillaTablero(t, fila, columna - 1);
   	 t.ocupadas=t.ocupadas-1;
   }

   int valorDerecha;
   valorDerecha = obtenerValorTablero(t, fila, columna + 1);
   if (valorDerecha == valorActual) {
   	 sumaFusionada = sumaFusionada + valorDerecha;
   	 vaciarCasillaTablero(t, fila, columna + 1);
   	 t.ocupadas=t.ocupadas-1;
   }

   int nuevoValor;
   nuevoValor = 1;
   while (nuevoValor < sumaFusionada) {
  	 nuevoValor = nuevoValor * 2;
   }
   vaciarCasillaTablero(t, fila, columna);
   insertarValorTablero(t, fila, columna, nuevoValor);
}

void eliminarCasillasVaciasIntermedias(Tablero &t, int columna) {
    int cuantos;
    int fila;
	cuantos = 0;
    for (fila = 0; fila < t.filas; fila++) {
   	 if (casillaEstaVacia(t,fila,columna)) {
   		 cuantos = cuantos + 1;;
   	 }
   	 else {
   		 if (cuantos > 0) {
   			 int valor;
   			 valor = obtenerValorTablero(t, fila, columna);
   			 vaciarCasillaTablero(t, fila - cuantos, columna);
   		 	insertarValorTablero(t, fila - cuantos, columna, valor);
       		 vaciarCasillaTablero(t, fila, columna);
   		 }
   	 }
    }
}


int obtenerValorMaximo(Tablero t) {
	int maxValor;
	int valor;
	int fila;
	int columna;
    maxValor = 0; //Porque el valor mínimo que puede haber en el tablero es 2
    for (fila = 0; fila < t.filas; fila++) {
   	 for (columna = 0; columna < t.columnas; columna++) {
   		 if (!casillaEstaVacia(t, fila, columna)) {
       		 valor = obtenerValorTablero(t, fila, columna);
       		 if (valor > maxValor) {
           		 maxValor = valor;
       		 }
   		 }
   	 }
    }

    return maxValor;
}


int obtenerPuntuacionTablero (Tablero t){
    int puntos;
    int i;
    int j;
    puntos = 0;
   	 for (i = 0; i < t.filas; i++) {
   		 for (j = 0; j < t.columnas; j++) {
   			 if (!casillaEstaVacia(t, i, j))
   				 puntos = puntos + obtenerValorTablero(t, i, j);
   		 }
   	 }
    return puntos;
}

int numeroFilas(Tablero t){
    return t.filas;
}

int numeroColumnas(Tablero t){
    return t.columnas;
}










