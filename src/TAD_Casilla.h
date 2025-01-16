#ifndef TAD_CASILLA_H_
#define TAD_CASILLA_H_

#include <iostream>
using namespace std;

const int MAX = 1;
typedef int tVector[MAX];

struct Casilla {
	tVector vector;
	int ocupadas; // Indica cuántos elementos están ocupando la casilla
};

// PRE: La casilla no ha sido inicializada
// POST: Inicializa la casilla vacía
void iniciar(Casilla &c);

// PRE: La casilla ha sido inicializada
// POST: Devuelve true si la casilla está vacía y false si está llena
bool estaVacia(Casilla &c);

// PRE: La casilla ha sido inicializada
// POST: Borra la información almacenada en la casilla
void vaciarCasilla(Casilla &c);

// PRE: La casilla ha sido inicializada y no está llena
// POST: Inserta el valor n en la casilla
void insertarValorCasilla(Casilla &c, int n);

// PRE: La casilla ha sido inicializada y no está vacía
// POST: Devuelve el valor almacenado en la casilla
int devolverValorCasilla(Casilla &c);

#endif

