#include <iostream>
#include "PruebasTADCasilla.h"
#include "TAD_Casilla.h"

using namespace std;

void testIniciar() {
	Casilla c;
	iniciar(c);
	if (c.ocupadas == 0) {
    	cout << "testIniciar: Bien." << endl;
	} else {
    	cout << "testIniciar: Fallido." << endl;
	}
}

void testEstaVacia() {
	Casilla c;
	iniciar(c);
	if (estaVacia(c)) {
    	cout << "testEstaVacia (casilla vacia): Bien." << endl;
	} else {
    	cout << "testEstaVacia (casilla vacia): Fallido." << endl;
	}

	insertarValorCasilla(c, 5);
	if (!estaVacia(c)) {
    	cout << "testEstaVacia (casilla no vacia): Bien." << endl;
	} else {
    	cout << "testEstaVacia (casilla no vacia): Fallido." << endl;
	}
}

void testVaciarCasilla() {
	Casilla c;
	iniciar(c);
	insertarValorCasilla(c, 10);
	vaciarCasilla(c);
	if (c.ocupadas == 0 && estaVacia(c)) {
    	cout << "testVaciarCasilla: Bien." << endl;
	} else {
    	cout << "testVaciarCasilla: Fallido." << endl;
	}
}

void testInsertarValor() {
	Casilla c;
	iniciar(c);
	insertarValorCasilla(c, 7);
	if (c.ocupadas == 1 && c.vector[0] == 7) {
   	cout << "testInsertarValor: Bien." << endl;
	} else {
    	cout << "testInsertarValor: Fallido. Debería haber valor 7 en la casilla. Valor obtenido: " << devolverValorCasilla(c) << endl;
	}

	// Prueba de inserción en casilla llena
	insertarValorCasilla(c, 8); // Intentar insertar un segundo valor
	if (c.ocupadas == 1) {
    	cout << "testInsertarValor (inserción en casilla llena): Bien." << endl;
	} else {
    	cout << "testInsertarValor (inserción en casilla llena): Fallido. Se insertó un segundo valor." << endl;
	}
}

void testDevolverValor() {
	Casilla c;
	iniciar(c);
	insertarValorCasilla(c, 42);
	int valor = devolverValorCasilla(c);
	if (valor == 42) {
    	cout << "testDevolverValor: Bien." << endl;
	} else {
    	cout << "testDevolverValor: Fallido. Debería devolver 42. En vez de eso, devuelve: " << valor << endl;
	}

	// Prueba de devolver valor de casilla vacía
	vaciarCasilla(c);
	valor = devolverValorCasilla(c);
	if (valor == -1) { // Asumiendo que -1 indica un error
    	cout << "testDevolverValor (casilla vacía): Bien." << endl;
	} else {
    	cout << "testDevolverValor (casilla vacía): Faillido" << endl;
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
