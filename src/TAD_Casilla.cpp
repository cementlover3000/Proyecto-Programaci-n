
#include <iostream>
#include "TAD_Casilla.h"
using namespace std;

void iniciar(Casilla &c) {
    c.ocupadas = 0;
}

void insertarValorCasilla(Casilla &c, int n) {
    if (c.ocupadas < MAX) {
   	 c.vector[0] = n;
   	 c.ocupadas++;
    }
}

bool estaVacia(Casilla c) {
    return c.ocupadas == 0;
}

int obtenerValorCasilla(Casilla c) {
    return c.vector[0];
}
    

void vaciarCasilla(Casilla &c) {
    c.ocupadas = 0;
}


