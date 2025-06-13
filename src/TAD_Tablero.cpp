#include <iostream>
#include <fstream>
#include <cmath>
#include "TAD_Tablero.h"
#include "entorno.h"
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
   		 do{
   		 insertarValorTablero(t, i, j, pow(2,rand()%maximo + 1));
   		 } while(pistaFusionarCasillasAdyacentes(t, i, j) != 0);
   	 }
    }
}

void iniciarTablero(Tablero& t) {
	ifstream archivo("numberTiles.cnf");

	int filas, columnas, comoIniciar, filasIniciales;
	archivo >> filas >> columnas >> comoIniciar >> filasIniciales;

	vaciarTablero(t);
	t.filas = filas;
	t.columnas = columnas;

	if (comoIniciar == 0) {
    	string cadena;
    	int i, j;
    	getline(archivo, cadena);
    	for (i = 0; i < filas; i++) {
        	for (j = 0; j < columnas; j++) {
            	if(i < filasIniciales){
           		 if (j < columnas - 1) {
           		  	getline(archivo, cadena, ' ');
                	}
                	else {
           		  	getline(archivo, cadena);
                	}
                	int valor;
                	valor = atoi(cadena.c_str());
                	insertarValorTablero(t, i, j, valor);
            	}
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
  	  fila = t.filas;
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

int fusionarCasillasAdyacentesRecursivo(Tablero &t, int fila, int columna) {
    int valorActual;
    valorActual = obtenerValorTablero(t, fila, columna);
    int sumaFusionada;
    sumaFusionada = valorActual;
    vaciarCasillaTablero(t, fila, columna);

    if(fila != 0){
   	 int valorArriba;
   	 valorArriba = obtenerValorTablero(t, fila - 1, columna);
   	 if (valorArriba == valorActual) {
   	 	sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila - 1, columna);
   	  }
    }

   if(fila != (t.filas - 1)){
   	int valorAbajo;
   	valorAbajo = obtenerValorTablero(t, fila + 1, columna);
   	if (valorAbajo == valorActual) {
   		sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila + 1, columna);
   	}
   }
   if(columna != 0){
   	int valorIzquierda;
   	valorIzquierda = obtenerValorTablero(t, fila, columna - 1);
   	if (valorIzquierda == valorActual) {
   		sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila, columna - 1);
   	}
   }

   if(columna != t.columnas - 1){
   	int valorDerecha;
   	valorDerecha = obtenerValorTablero(t, fila, columna + 1);
   	if (valorDerecha == valorActual) {
   		sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila, columna + 1);
   	}
   }

   return sumaFusionada;
}

int fusionarCasillasAdyacentes(Tablero &t, int fila, int columna) {
    int valorActual;
    valorActual = obtenerValorTablero(t, fila, columna);
    int sumaFusionada;
    sumaFusionada = valorActual;
    vaciarCasillaTablero(t, fila, columna);

    if(fila != 0){
   	 int valorArriba;
   	 valorArriba = obtenerValorTablero(t, fila - 1, columna);
   	 if (valorArriba == valorActual) {
   	 	sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila - 1, columna);
   	 	vaciarCasillaTablero(t, fila - 1, columna);
   	  }
    }

   if(fila != (t.filas - 1)){
   	int valorAbajo;
   	valorAbajo = obtenerValorTablero(t, fila + 1, columna);
   	if (valorAbajo == valorActual) {
   		sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila + 1, columna);
   	 	vaciarCasillaTablero(t, fila + 1, columna);
   	}
   }
   if(columna != 0){
   	int valorIzquierda;
   	valorIzquierda = obtenerValorTablero(t, fila, columna - 1);
   	if (valorIzquierda == valorActual) {
   		sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila, columna - 1);
   	 	vaciarCasillaTablero(t, fila, columna - 1);
   	}
   }

   if(columna != t.columnas - 1){
   	int valorDerecha;
   	valorDerecha = obtenerValorTablero(t, fila, columna + 1);
   	if (valorDerecha == valorActual) {
   		sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila, columna + 1);
   	 	vaciarCasillaTablero(t, fila, columna + 1);
   	}
   }



   int nuevoValor;
   nuevoValor = 1;
   while (nuevoValor < sumaFusionada) {
  	 nuevoValor = nuevoValor * 2;
   }
   insertarValorTablero(t, fila, columna, nuevoValor);
   int i;
   for(i = 0; i < t.columnas; i++){
   	eliminarCasillasVaciasIntermedias(t, i);
   }
   int resultado;
   resultado = 0;
   if(nuevoValor == valorActual){
   	resultado = 0;
   }
   else{
   	if()
   	resultado = resultado + nuevoValor + fusionarCasillasAdyacentes(t, filaPrimeraCasillaVacia(t, columna) - 1, columna);
   }
   return resultado;
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
    maxValor = 2; //Porque el valor mínimo que puede haber en el tablero es 2
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



int numeroFilas(Tablero t){
    return t.filas;
}

int numeroColumnas(Tablero t){
    return t.columnas;
}

int pistaFusionarCasillasAdyacentes(Tablero t, int fila, int columna) {
    int valorActual;
    valorActual = obtenerValorTablero(t, fila, columna);
    int sumaFusionada;
    sumaFusionada = valorActual;
    vaciarCasillaTablero(t, fila, columna);

    if(fila != 0){
   	 int valorArriba;
   	 valorArriba = obtenerValorTablero(t, fila - 1, columna);
   	 if (valorArriba == valorActual) {
   	 	sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila - 1, columna);
   	 	vaciarCasillaTablero(t, fila - 1, columna);
   	  }
    }

   if(fila != (t.filas - 1)){
   	int valorAbajo;
   	valorAbajo = obtenerValorTablero(t, fila + 1, columna);
   	if (valorAbajo == valorActual) {
   		sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila + 1, columna);
   	 	vaciarCasillaTablero(t, fila + 1, columna);
   	}
   }
   if(columna != 0){
   	int valorIzquierda;
   	valorIzquierda = obtenerValorTablero(t, fila, columna - 1);
   	if (valorIzquierda == valorActual) {
   		sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila, columna - 1);
   	 	vaciarCasillaTablero(t, fila, columna - 1);
   	}
   }

   if(columna != t.columnas - 1){
   	int valorDerecha;
   	valorDerecha = obtenerValorTablero(t, fila, columna + 1);
   	if (valorDerecha == valorActual) {
   		sumaFusionada = sumaFusionada + fusionarCasillasAdyacentesRecursivo(t, fila, columna + 1);
   	 	vaciarCasillaTablero(t, fila, columna + 1);
   	}
   }



   int nuevoValor;
   nuevoValor = 1;
   while (nuevoValor < sumaFusionada) {
  	 nuevoValor = nuevoValor * 2;
   }
   insertarValorTablero(t, fila, columna, nuevoValor);
   eliminarCasillasVaciasIntermedias(t, columna);
  		 if(columna != 0){
  			  eliminarCasillasVaciasIntermedias(t, columna - 1);
  		 }
   	 if(columna != (numeroColumnas(t) - 1)){
  			  eliminarCasillasVaciasIntermedias(t, columna + 1);
   	 }
   int resultado;
   if(nuevoValor == valorActual){
   	resultado = 0;
   }
   else{
   	resultado = nuevoValor;
   	resultado = resultado + fusionarCasillasAdyacentes(t, filaPrimeraCasillaVacia(t, columna) - 1, columna);
   }
   return resultado;
}



