#include <iostream>
#include "TAD_Casilla.h"
#include "PruebasTAD_Casilla.h"
using namespace std;


void pruebaIniciar() {
    Casilla c;
    iniciar(c);
    if (c.ocupadas == 0) {
        cout << "Prueba Iniciar: OK" << endl;
    }
    else {
        cout << "Prueba Iniciar: ERROR" << endl;
    }
}

void pruebaInsertarValorCasilla() {
    Casilla c;
    iniciar(c);

    // Prueba 1
    insertarValorCasilla(c, 5);
    if (c.vector[0] == 5 && c.ocupadas == 1) {
        cout << "Prueba 1 Insertar Valor Casilla: OK" << endl;
    }
    else {
        cout << "Prueba 1 Insertar Valor Casilla: ERROR" << endl;
    }

    // Prueba 2
    insertarValorCasilla(c, 10);
    if (c.ocupadas == 1 && c.vector[0] == 5) {
        cout << "Prueba 2 Insertar Valor Casilla: OK" << endl;
    }
    else {
        cout << "Prueba 2 Insertar Valor Casilla: ERROR" << endl;
    }

    // Prueba 3
    vaciarCasilla(c);
    insertarValorCasilla(c, 15);
    if (c.vector[0] == 15 && c.ocupadas == 1) {
        cout << "Prueba 3 Insertar Valor Casilla: OK" << endl;
    }
    else {
        cout << "Prueba 3 Insertar Valor Casilla: ERROR" << endl;
    }
}

void pruebaEstaVacia() {
    Casilla c;
    iniciar(c);

    // Prueba 1
    if (estaVacia(c)) {
        cout << "Prueba 1 Esta Vacia: OK" << endl;
    }
    else {
        cout << "Prueba 1 Esta Vacia: ERROR" << endl;
    }

    // Prueba 2
    insertarValorCasilla(c, 10);
    if (!estaVacia(c)) {
        cout << "Prueba 2 Esta Vacia: OK" << endl;
    }
    else {
        cout << "Prueba 2 Esta Vacia: ERROR" << endl;
    }
}

void pruebaObtenerValorCasilla() {
    Casilla c;
    iniciar(c);
    int valor;

    // Prueba 1
    insertarValorCasilla(c, 10);
    valor = obtenerValorCasilla(c);
    if (valor == 10) {
        cout << "Prueba 1 Obtener Valor Casilla: OK" << endl;
    } else {
        cout << "Prueba 1 Obtener Valor Casilla: ERROR" << endl;
    }

    // Prueba 2
    vaciarCasilla(c);
    insertarValorCasilla(c, 20);
    valor = obtenerValorCasilla(c);
    if (valor == 20) {
        cout << "Prueba 2 Obtener Valor Casilla: OK" << endl;
    } else {
        cout << "Prueba 2 Obtener Valor Casilla: ERROR" << endl;
    }

    // Prueba 3
    vaciarCasilla(c);
    insertarValorCasilla(c, 30);
    valor = obtenerValorCasilla(c);
    if (valor == 30) {
        cout << "Prueba 3 Obtener Valor Casilla: OK" << endl;
    } else {
        cout << "Prueba 3 Obtener Valor Casilla: ERROR" << endl;
    }
}

void pruebaVaciarCasilla() {
    Casilla c;
    iniciar(c);
    insertarValorCasilla(c, 42);
    vaciarCasilla(c);
    if (c.ocupadas == 0) {
        cout << "Prueba Vaciar Casilla: OK" << endl;
    } else {
        cout << "Prueba Vaciar Casilla: ERROR" << endl;
    }
}

void ejecutarPruebasTAD_Casilla() {
    cout << "Inicio Pruebas TAD_Casilla" << endl;
    pruebaIniciar();
    pruebaInsertarValorCasilla();
    pruebaEstaVacia();
    pruebaObtenerValorCasilla();
    pruebaVaciarCasilla();
    cout << "Fin Pruebas TAD_Casilla" << endl;
}

