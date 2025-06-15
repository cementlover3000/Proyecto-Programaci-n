#ifndef PRUEBASTAD_CASILLA_H_
#define PRUEBASTAD_CASILLA_H_

#include <iostream>
#include "TAD_Casilla.h"
using namespace std;

/*
 * PRE:  { }
 * POST: Ejecuta la prueba de la función iniciar del TAD Casilla, mostrando el resultado por pantalla
 * COMPLEJIDAD: O(1)
 */
void pruebaIniciar();

/*
 * PRE:  { }
 * POST: Ejecuta distintas pruebas sobre la función insertarValorCasilla.
 *       Comprueba si se inserta correctamente el valor cuando la casilla está vacía
 *       y si se ignoran inserciones cuando está ocupada.
 * COMPLEJIDAD: O(1)
 */
void pruebaInsertarValorCasilla();

/*
 * PRE:  { }
 * POST: Ejecuta distintas pruebas sobre la función estaVacia, mostrando si el comportamiento es el esperado.
 * COMPLEJIDAD: O(1)
 */
void pruebaEstaVacia();

/*
 * PRE:  { }
 * POST: Ejecuta pruebas sobre obtenerValorCasilla comprobando que se recupera el valor correcto tras insertar.
 * COMPLEJIDAD: O(1)
 */
void pruebaObtenerValorCasilla();

/*
 * PRE:  { }
 * POST: Verifica si la función vaciarCasilla deja correctamente la casilla en estado vacío.
 * COMPLEJIDAD: O(1)
 */
void pruebaVaciarCasilla();

/*
 * PRE:  { }
 * POST: Llama a todas las pruebas anteriores en orden, mostrando el resultado global del módulo TAD Casilla.
 * COMPLEJIDAD: O(1)
 */
void ejecutarPruebasTAD_Casilla();

#endif
