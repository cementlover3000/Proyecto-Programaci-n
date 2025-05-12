#ifndef TAD_CASILLA_H_
#define TAD_CASILLA_H_
#include <iostream>
using namespace std;

const int MAX = 1;
typedef int tVector[MAX];

struct Casilla {
    tVector vector;
    int ocupadas;
};


void iniciar(Casilla &c);

void insertarValorCasilla(Casilla &c, int n);

bool estaVacia(Casilla c);

int obtenerValorCasilla(Casilla c);

void vaciarCasilla(Casilla &c);

#endif
