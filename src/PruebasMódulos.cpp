




#include <iostream>
#include "TAD_Casilla.h"
#include "TAD_Casilla.cpp"
#include "TAD_Tablero.h"
#include "TAD_Tablero.cpp"

using namespace std;



void testIniciar() {
	    Casilla c;
	    iniciar(c);
	    if (c.ocupadas == 0) {
	        cout << "testIniciar: Bien.\n";
	    } else {
	        cout << "testIniciar: Fallido.\n";
	    }
	}

void testEstaVacia() {
	    Casilla c;
	    iniciar(c);
	    if (estaVacia(c)) {
	        cout << "testEstaVacia (casilla vacia): Bien.\n";
	    } else {
	        cout << "testEstaVacia (casilla vacia): Fallido.\n";
	    }

	    insertarValor(c, 5);
	    if (!estaVacia(c)) {
	        cout << "testEstaVacia (casilla no vacia): Bien.\n";
	    } else {
	        cout << "testEstaVacia (casilla no vacia): Fallido.\n";
	    }
	}

void testVaciarCasilla() {
	    Casilla c;
	    iniciar(c);
	    insertarValor(c, 10);
	    vaciarCasilla(c);
	    if (c.ocupadas == 0 && estaVacia(c)) {
	        cout << "testVaciarCasilla: Bien.\n";
	    } else {
	        cout << "testVaciarCasilla: Fallido.\n";
	    }
	}

void testInsertarValor() {
	    Casilla c;
	    iniciar(c);
	    insertarValor(c, 7);
	    if (c.ocupadas == 1 && c.vector[0] == 7) {
	        cout << "testInsertarValor: Bien.\n";
	    } else {
	        cout << "testInsertarValor: Fallido.\n";
	    }
	}

void testDevolverValor() {
	    Casilla c;
	    iniciar(c);
	    insertarValor(c, 42);
	    int valor = devolverValor(c);
	    if (valor == 42) {
	        cout << "testDevolverValor: Bien.\n";
	    } else {
	        cout << "testDevolverValor: Fallido.\n";
	    }
	}

void pruebasTADCasilla(){
	cout << "Iniciando pruebas del TAD_Casilla." << endl;
	testIniciar();
	testEstaVacia();
	testVaciarCasilla();
	testInsertarValor();
	testDevolverValor();
	cout << "Fin de las pruebas del TAD_Casilla." << endl;
}
