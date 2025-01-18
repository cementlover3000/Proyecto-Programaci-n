#include "TAD_Juego.h"
#include "entorno.h"
#include "TAD_Casilla.h"
#include "TAD_Tablero.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

void iniciarJuego(Juego &g) {
	int numFilas, numColumnas, comoIniciar, filasIniciales;
	int m[MAX_FILAS][MAX_COL];

	if (!entornoCargarConfiguracion(numFilas, numColumnas, comoIniciar, filasIniciales, m)) {
    	cout << "Error al cargar la configuración del juego." << endl;
    	return;
	}

	entornoIniciar(numFilas, numColumnas);
	g.puntuacion = 0;

	iniciarTablero(g.tablero);

	if (comoIniciar == 0) {
    	for (int i = 0; i < filasIniciales; i++) {
        	for (int j = 0; j < numColumnas; j++) {
                	insertarValorTablero(g.tablero, m[i][j], i, j);
        	}
    	}
	}
	else{
   	 if (comoIniciar > 0) {
	}
   	 int i, j, valor;
    	for (i = 0; i < filasIniciales; i++) {
        	for (j = 0; j < numColumnas; j++) {
            	valor = pow(2, rand() % comoIniciar + 1);
            	insertarValorTablero(g.tablero, valor, i, j);
        	}
    	}
	}
}
