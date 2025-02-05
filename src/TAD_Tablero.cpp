#include <iostream>
#include "TAD_Tablero.h"
using namespace std;

void iniciarTableroAleatorio (Tablero &t,int filasIniciales, int maximo) {
	srand(time(nullptr));
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			if (i < filasIniciales) {
				insertarValorCasilla(t.tablero[i][j], pow(2,rand()%maximo + 1));
			}
			else {
				iniciar(t.tablero[i][j]);
			}
		}
	}
}

void insertarValorTablero(Tablero &t, int fila, int columna, int valor) {
	if (casillaEstaVacia(t, fila, columna)) {
    	insertarValorCasilla(t.tablero[fila][columna], valor);
    	t.ocupadas = t.ocupadas+1;
	}
}

bool casillaEstaVacia(Tablero t, int fila, int columna) {
	return estaVacia(t.tablero[fila][columna]);
}

int obtenerValorTablero(Tablero t, int fila, int columna) {
	return obtenerValorCasilla(t.tablero[fila][columna]);
}

void vaciarCasillaTablero(Tablero &t, int fila, int columna) {
	vaciarCasilla(t.tablero[fila][columna]);
	t.ocupadas = t.ocupadas-1;
}

bool columnaEstaLlena(Tablero t, int columna) {
	bool estaLlena;
	int fila;
	estaLlena = true;
	for (fila = 0; fila < FILAS; fila++) {
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
  	  int i;
  	  i = 0;
  	  while(i < FILAS && !estaVacia){
  	      if (casillaEstaVacia(t, i, columna)) {
  	  		 fila=i;
  	  		 estaVacia = true;
  	      }
  	      else{
  			  i++;
  	      }
  	  }
    }
    return fila;
}

bool tableroEstaLleno(Tablero t) {
	return t.ocupadas == FILAS * COLUMNAS;
}


int numeroFilas(Tablero t) {
	return FILAS;
}

int numeroColumnas(Tablero t) {
	return COLUMNAS;
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
	for (fila = 0; fila < FILAS; fila++) {
    	if (estaVacia(t.tablero[fila][columna])) {
        	cuantos = cuantos + 1;;
    	}
    	else {
        	if (cuantos > 0) {
            	t.tablero[fila - cuantos][columna] = t.tablero[fila][columna];
            	vaciarCasillaTablero(t, fila, columna);
        	}
    	}
	}
	t.ocupadas = t.ocupadas - cuantos;
}


int obtenerValorMaximo(Tablero t) {
    int maxValor;
    int valor;
    int fila;
    int columna;
	maxValor = 0; //Porque el valor mínimo que puede haber en el tablero es 2
	for (fila = 0; fila < FILAS; fila++) {
    	for (columna = 0; columna < COLUMNAS; columna++) {
        	if (!estaVacia(t.tablero[fila][columna])) {
            	valor = obtenerValorCasilla(t.tablero[fila][columna]);
            	if (valor > maxValor) {
                	maxValor = valor;
            	}
        	}
    	}
	}

	return maxValor;
}












