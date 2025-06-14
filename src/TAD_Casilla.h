#ifndef TAD_CASILLA_H_
#define TAD_CASILLA_H_

const int MAX = 1;  // Solo se almacena un valor por casilla en este TAD

// -------------------------------------------------------------
// Definición de tipos
// -------------------------------------------------------------

/*
 * Tipo de dato que representa una casilla del tablero.
 * Una casilla almacena como máximo un número entero.
 */
struct Casilla {
    int vector[MAX];   // Vector con un único valor posible (la casilla)
    int ocupadas;      // 0 si la casilla está vacía, 1 si contiene un número
};

/*
 * PRE:  { }
 * POST: La casilla c queda vacía (ocupadas = 0)
 * COMPLEJIDAD: O(1)
 */
void iniciar(Casilla &c);

/*
 * PRE:  { c.ocupadas == 0, 0 <= n }
 * POST: Inserta el valor n en la casilla c si está vacía
 * COMPLEJIDAD: O(1)
 */
void insertarValorCasilla(Casilla &c, int n);

/*
 * PRE:  { }
 * POST: Devuelve true si la casilla está vacía, false en caso contrario
 * COMPLEJIDAD: O(1)
 */
bool estaVacia(Casilla c);

/*
 * PRE:  { c.ocupadas > 0 }
 * POST: Devuelve el valor almacenado en la casilla
 * COMPLEJIDAD: O(1)
 */
int obtenerValorCasilla(Casilla c);

/*
 * PRE:  { }
 * POST: La casilla queda vacía (ocupadas = 0)
 * COMPLEJIDAD: O(1)
 */
void vaciarCasilla(Casilla &c);

#endif
