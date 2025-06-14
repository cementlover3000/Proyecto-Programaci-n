#ifndef PRUEBASTAD_TABLERO_H_
#define PRUEBASTAD_TABLERO_H_
#include <iostream>
#include "TAD_Tablero.h"
using namespace std;

/**
 * DESCRIPCIÓN: Comprueba si un valor entero es una potencia de 2.
 * PRE: valor > 0
 * COMPLEJIDAD: O(log(n))
 */
bool esPotenciaDeDos(int valor);

/**
 * DESCRIPCIÓN: Compara dos tableros por valor (dimensiones y contenido).
 * COMPLEJIDAD: O(n²)
 */
bool compararTableros(Tablero& t1, Tablero& t2);

// -------------------------------------------------------------
// PRUEBAS UNITARIAS
// -------------------------------------------------------------

/**
 * DESCRIPCIÓN: Verifica que la función iniciarTablero() inicializa correctamente el tablero,
 *              comparando contra la configuración leída desde archivo.
 * COMPLEJIDAD: O(n²)
 */
void pruebaIniciarTablero();

/**
 * DESCRIPCIÓN: Verifica que vaciarTablero() deja todas las casillas a 0
 *              y actualiza correctamente el contador de ocupadas.
 * COMPLEJIDAD: O(n²)
 */
void pruebaVaciarTablero();

/**
 * DESCRIPCIÓN: Verifica que iniciarTableroAleatorio() coloca potencias de 2 válidas
 *              en las filas iniciales del tablero.
 * COMPLEJIDAD: O(n²)
 */
void pruebaIniciarTableroAleatorio();

/**
 * DESCRIPCIÓN: Verifica que insertarValorTablero() inserta valores correctamente
 *              y actualiza el contador de casillas ocupadas.
 * COMPLEJIDAD: O(1)
 */
void pruebaInsertarValorTablero();

/**
 * DESCRIPCIÓN: Verifica que casillaEstaVacia() detecta correctamente el estado vacío de una celda.
 * COMPLEJIDAD: O(1)
 */
void pruebaCasillaEstaVacia();

/**
 * DESCRIPCIÓN: Verifica que obtenerValorTablero() devuelve el valor correcto de una celda.
 * COMPLEJIDAD: O(1)
 */
void pruebaObtenerValorTablero();

/**
 * DESCRIPCIÓN: Verifica que vaciarCasillaTablero() borra una celda correctamente,
 *              sin modificar el contador si ya estaba vacía.
 * COMPLEJIDAD: O(1)
 */
void pruebaVaciarCasillaTablero();

/**
 * PRE: -
 * POST: Prueba columnaEstaLlena.
 * COMPLEJIDAD: O(n)  // Recorre una columna de n filas
 */
void pruebaColumnaEstaLlena();

/**
 * PRE: -
 * POST: Prueba filaPrimeraCasillaVacia.
 * COMPLEJIDAD: O(n)  // Busca casilla vacía en columna de n filas
 */
void pruebaFilaPrimeraCasillaVacia();

/**
 * PRE: -
 * POST: Prueba tableroEstaLleno.
 * COMPLEJIDAD: O(n^2)  // Recorre todo el tablero de n x n
 */
void pruebaTableroEstaLleno();

/**
 * PRE: -
 * POST: Prueba fusionarCasillasAdyacentes.
 * COMPLEJIDAD: O(1)
 */
void pruebaFusionarCasillasAdyacentes();

/**
 * PRE: -
 * POST: Prueba eliminarCasillasVaciasIntermedias.
 * COMPLEJIDAD: O(n)  // Recorre columna para compactar n filas
 */
void pruebaEliminarCasillasVaciasIntermedias();

/**
 * PRE: -
 * POST: Prueba obtenerValorMaximo.
 * COMPLEJIDAD: O(n^2)  // Recorre todo el tablero de n x n
 */
void pruebaObtenerValorMaximo();

/**
 * PRE: -
 * POST: Prueba numeroFilas.
 * COMPLEJIDAD: O(1)
 */
void pruebaNumeroFilas();

/**
 * PRE: -
 * POST: Prueba numeroColumnas.
 * COMPLEJIDAD: O(1)
 */
void pruebaNumeroColumnas();

/**
 * PRE: -
 * POST: Ejecuta todas las pruebas del TAD Tablero.
 * COMPLEJIDAD: Suma de las pruebas anteriores.
 */
void ejecutarPruebasTAD_Tablero();


#endif



