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
#include <fstream> // Para leer desde un archivo
#include <iostream>
#include "TAD_Casilla.h"
#include "TAD_Tablero.h"
using namespace std;



void iniciarTablero(Tablero &t) {
	ifstream archivo("numberTiles.cnf");
	if (!archivo.is_open()) {
    	cout << "No se pudo abrir el archivo de configuración." << endl;
    	return;
	}

	int filas, columnas, generacionAleatoria, numFilasIniciales;
	archivo >> filas >> columnas >> generacionAleatoria >> numFilasIniciales;

	// Validar filas y columnas
	if (filas < 3 || filas > 7 || columnas < 5 || columnas > 7) {
    	cout << "Número de filas o columnas fuera de rango." << endl;
    	return;
	}

	// Inicializar el tablero
	t.ocupadas = 0; // Inicializamos el contador de ocupadas a 0

	// Leer valores iniciales del tablero
	for (int fila = 0; fila < filas; fila++) {
    	for (int columna = 0; columna < columnas; columna++) {
        	// Si estamos en las filas iniciales con valores
        	if (fila < numFilasIniciales) {
            	int valor;
            	archivo >> valor; // Leer el valor desde el archivo
            	if (valor > 0 && (valor & (valor - 1)) == 0 && valor < 4096) { // Verificar que sea potencia de 2
                	insertarValorTablero(t, valor, fila, columna);
            	} else {
                	cout << "Valor no válido en la configuración: " << valor << endl;
            	}
        	} else {
            	// Rellenar el resto del tablero con casillas vacías
            	vaciarCasillaTablero(t, fila, columna); // Aseguramos que las casillas estén vacías
        	}
    	}
	}

	archivo.close(); // Cerrar el archivo
}

void insertarValorTablero(Tablero &t, int n, int fila, int columna) {
	if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS && !estaVacia(t.tablero[fila][columna])) {
    	insertarValorCasilla(t.tablero[fila][columna], n);
    	t.ocupadas++;
	}
}

int obtenerValorTablero(Tablero t, int fila, int columna) {
	return devolverValorCasilla(t.tablero[fila][columna]);
}

bool columnaEstaLlena(Tablero t, int columna) {
	for (int i = 0; i < FILAS; i++) {
    	if (estaVacia(t.tablero[i][columna])) {
        	return false; // Si encontramos una casilla vacía, la columna no está llena
    	}
	}
	return true; // Si no encontramos casillas vacías, la columna está llena
}

bool tableroEstaLleno(Tablero t) {
	for (int i = 0; i < FILAS; i++) {
    	for (int j = 0; j < COLUMNAS; j++) {
        	if (estaVacia(t.tablero[i][j])) {
            	return false; // Si encontramos una casilla vacía, el tablero no está lleno
        	}
    	}
	}
	return true; // Si no encontramos casillas vacías, el tablero está lleno
}

void eliminarCasillasVaciasIntermedias(Tablero &t, int columna) {
	int cuantos = 0;
	for (int i = 0; i < FILAS; i++) {
    	if (estaVacia(t.tablero[i][columna])) {
        	cuantos++;
    	} else if (cuantos > 0) {
        	t.tablero[i - cuantos][columna] = t.tablero[i][columna];
        	vaciarCasillaTablero(t, i, columna); // Vaciamos la casilla original
    	}
	}
	t.ocupadas = cuantos; // Actualizamos el contador de ocupadas
}

bool casillaEstaVacia(Tablero t, int fila, int columna) {
	return estaVacia(t.tablero[fila][columna]);
}

void vaciarCasillaTablero(Tablero &t, int fila, int columna) {
	// Verificamos que la posición esté dentro de los límites del tablero
	if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS) {
    	// Vaciamos la casilla
    	vaciarCasilla(t.tablero[fila][columna]);

    	// Decrementamos el contador de ocupadas si la casilla estaba ocupada
    	if (!estaVacia(t.tablero[fila][columna])) {
        	t.ocupadas--;
    	}
	}
}

int filaPrimeraCasillaVacia(Tablero t, int columna) {
	// Verificamos que la columna esté dentro de los límites
	if (columna < 0 || columna >= COLUMNAS) {
    	return -1; // Retornamos -1 si la columna es inválida
	}

	for (int fila = 0; fila < FILAS; fila++) {
    	if (casillaEstaVacia(t, fila, columna)) {
        	return fila; // Retorna la fila de la primera casilla vacía
    	}
	}

	return -1; // Retorna -1 si no hay casillas vacías en la columna
}

int numeroFilas(Tablero t) {
	return FILAS; // Retorna el número de filas definidas en el tablero
}

int numeroColumnas(Tablero t) {
	return COLUMNAS; // Retorna el número de columnas definidas en el tablero
}

int maximoValorTablero(Tablero t) {
	int max = -1; // Suponemos que los valores son no negativos, así que comenzamos con -1

	for (int i = 0; i < FILAS; i++) {
    	for (int j = 0; j < COLUMNAS; j++) {
        	if (!casillaEstaVacia(t, i, j)) { // Verificamos si la casilla no está vacía
            	int valor = obtenerValorTablero(t, i, j); // Obtenemos el valor de la casilla
            	if (valor > max) {
                	max = valor; // Actualizamos el máximo si encontramos un valor mayor
            	}
        	}
    	}
	}

	return max; // Retornamos el valor máximo encontrado
}

void fusionarCasillasAdyacentes(Tablero &t, int fila, int columna) {
	// Verificamos que la posición esté dentro de los límites del tablero
	if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
    	return; // Salimos si la posición es inválida
	}

	// Verificamos que no estamos en la última fila
	if (fila < FILAS - 1) { // Aseguramos que no estamos en la última fila
    	if (!casillaEstaVacia(t, fila, columna) && !casillaEstaVacia(t, fila + 1, columna)) {
        	int valorActual = obtenerValorTablero(t, fila, columna);
        	int valorAbajo = obtenerValorTablero(t, fila + 1, columna);

        	// Fusionamos los valores
        	int nuevoValor = valorActual + valorAbajo;
        	vaciarCasillaTablero(t, fila + 1, columna); // Vaciamos la casilla de abajo
        	vaciarCasillaTablero(t, fila, columna); // Vaciamos la casilla actual
        	insertarValorTablero(t, nuevoValor, fila, columna); // Insertamos el nuevo valor en la casilla actual
    	}
	}
}










