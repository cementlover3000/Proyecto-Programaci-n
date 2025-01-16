/*
 * PruebasTADTablero.cpp
 *
 *  Created on: 13 ene 2025
 *      Autores: Alejandro Pulido Rodríguez y Alejandro Bravo González
 */

#include <iostream>
#include "TAD_Tablero.h"
#include "TAD_Casilla.h"
using namespace std;

// Función para inicializar un tablero vacío
void inicializarTableroVacio(Tablero &t) {
    t.ocupadas = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            iniciar(t.tablero[i][j]);
        }
    }
}

// Módulo de prueba para insertarValorTablero
void probarInsertarValor() {
    cout << "Prueba: insertarValorTablero" << endl;
    Tablero t;
    inicializarTableroVacio(t);
    insertarValorTablero(t, 5, 1, 1);

    int valor = obtenerValorTablero(t, 1, 1);
    if (valor == 5) {
        cout << "Bien: Se insertó el valor correctamente." << endl;
    } else {
        cout << "Error: El valor no coincide. Valor esperado: 5, obtenido: " << valor << endl;
    }
}

// Módulo de prueba para columnaEstaLlena
void probarColumnaLlena() {
    cout << "Prueba: columnaEstaLlena" << endl;
    Tablero t;
    inicializarTableroVacio(t);

    for (int i = 0; i < FILAS; i++) {
        insertarValorTablero(t, 1, i, 0);
    }

    if (columnaEstaLlena(t, 0)) {
        cout << "Bien: La columna está llena." << endl;
    } else {
        cout << "Error: La columna debería estar llena pero no lo está." << endl;
    }
}

// Módulo de prueba para tableroEstaLleno
void probarTableroLleno() {
    cout << "Prueba: tableroEstaLleno" << endl;
    Tablero t;
    inicializarTableroVacio(t);

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            insertarValorTablero(t, 1, i, j);
        }
    }

    if (tableroEstaLleno(t)) {
        cout << "Bien: El tablero está lleno." <<endl;
    } else {
        cout << "Error: El tablero debería estar lleno pero no lo está." << endl;
    }
}

// Módulo de prueba para eliminarCasillasVaciasIntermedias
void probarEliminarCasillasVaciasIntermedias() {
    cout << "Prueba: eliminarCasillasVaciasIntermedias" << endl;
    Tablero t;
    inicializarTableroVacio(t);

    insertarValorTablero(t, 3, 0, 0);
    insertarValorTablero(t, 5, 2, 0);

    eliminarCasillasVaciasIntermedias(t, 0);

    if (obtenerValorTablero(t, 0, 0) == 3 && obtenerValorTablero(t, 1, 0) == 5) {
        cout << "Bien: Las casillas vacías intermedias fueron eliminadas correctamente." << endl;
    } else {
        cout << "Error: Las casillas vacías intermedias no fueron eliminadas como se esperaba." << endl;
    }
}

// Módulo de prueba para maximoValorTablero
void probarMaximoValor() {
    cout << "Prueba: maximoValorTablero" << endl;
    Tablero t;
    inicializarTableroVacio(t);

    insertarValorTablero(t, 10, 0, 0);
    insertarValorTablero(t, 20, 1, 1);

    int maximo = maximoValorTablero(t);
    if (maximo == 20) {
        cout << "Bien: El valor máximo es correcto." << endl;
    } else {
        cout << "Error: El valor máximo no es correcto. Valor esperado: 20, obtenido: " << maximo << endl;
    }
}

// Función principal para ejecutar todas las pruebas
void pruebasTADTablero() {
    probarInsertarValor();
    probarColumnaLlena();
    probarTableroLleno();
    probarEliminarCasillasVaciasIntermedias();
    probarMaximoValor();
}

