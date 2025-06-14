#ifndef TAD_TABLERO_H_
#define TAD_TABLERO_H_
#include <iostream>
#include "TAD_Casilla.h"
using namespace std;

const int FILAS = 7;
const int COLUMNAS = 7;
typedef Casilla tMatriz[FILAS][COLUMNAS];
struct Tablero{
    tMatriz tablero;
    int ocupadas;
    int filas;
    int columnas;
};

/*
 * DESCRIPCIÓN: Vacía todas las casillas del tablero y reinicia el contador de casillas ocupadas.
 * POST: Todas las casillas estarán vacías y el contador será 0.
 * COMPLEJIDAD: O(n²)
 */
void vaciarTablero(Tablero& t);

/*
 * PRE: { maximo > 0 }
 * DESCRIPCIÓN: Inicializa el tablero con valores aleatorios (potencias de 2) en las primeras filas.
 *              Asegura que no haya fusiones posibles tras la generación.
 * COMPLEJIDAD: O(n²)
 */
void iniciarTableroAleatorio(Tablero &t, int filas, int columnas, int filasIniciales, int maximo);

/*
 * PRE: El archivo "numberTiles.cnf" debe existir y estar correctamente formateado.
 * DESCRIPCIÓN: Inicializa el tablero desde el fichero de configuración o aleatoriamente, según el valor leído.
 * COMPLEJIDAD: O(n²)
 */
void iniciarTablero(Tablero& t);

/*
 * PRE: { 0 <= fila < n, 0 <= columna < n }
 * DESCRIPCIÓN: Inserta un valor en la casilla del tablero, vaciando antes su contenido.
 * POST: La casilla tendrá el valor y se incrementará el contador de ocupadas.
 * COMPLEJIDAD: O(1)
 */
void insertarValorTablero(Tablero &t, int fila, int columna, int valor);

/*
 * PRE: { 0 <= fila < n, 0 <= columna < n }
 * DESCRIPCIÓN: Indica si una casilla del tablero está vacía.
 * COMPLEJIDAD: O(1)
 */
bool casillaEstaVacia(Tablero t, int fila, int columna);

/*
 * PRE: { 0 <= fila < n, 0 <= columna < n }
 * DESCRIPCIÓN: Devuelve el valor contenido en una casilla del tablero. Si está vacía, devuelve 0.
 * COMPLEJIDAD: O(1)
 */
int obtenerValorTablero(Tablero t, int fila, int columna);

/*
 * PRE: { 0 <= fila < n, 0 <= columna < n }
 * DESCRIPCIÓN: Vacía una casilla del tablero si no está vacía y decrementa el contador de ocupadas.
 * COMPLEJIDAD: O(1)
 */
void vaciarCasillaTablero(Tablero &t, int fila, int columna);

/*
 * PRE: { 0 <= columna < n }
 * DESCRIPCIÓN: Indica si una columna está completamente llena (sin casillas vacías).
 * COMPLEJIDAD: O(n)
 */
bool columnaEstaLlena(Tablero t, int columna);

/*
 * PRE: { 0 <= columna < n }
 * DESCRIPCIÓN: Devuelve la fila de la primera casilla vacía en una columna.
 *              Si la columna está llena, devuelve n (valor fuera de rango).
 * COMPLEJIDAD: O(n)
 */
int filaPrimeraCasillaVacia(Tablero t, int columna);

/*
 * DESCRIPCIÓN: Indica si el tablero está completamente lleno.
 * COMPLEJIDAD: O(1)
 */
bool tableroEstaLleno(Tablero t);

/*
 * PRE: { 0 <= fila < n, 0 <= columna < n }
 * DESCRIPCIÓN: Fusiona recursivamente casillas adyacentes con el mismo valor.
 * POST: Elimina las casillas fusionadas y devuelve la suma de los valores fusionados.
 * COMPLEJIDAD: O(n²)
 */
int fusionarCasillasAdyacentesRecursivo(Tablero &t, int fila, int columna);

/*
 * PRE: { 0 <= fila < n, 0 <= columna < n }
 * DESCRIPCIÓN: Fusiona casillas adyacentes del mismo valor y actualiza el tablero.
 * POST: Devuelve la puntuación ganada con la fusión.
 * COMPLEJIDAD: O(n²)
 */
int fusionarCasillasAdyacentes(Tablero &t, int fila, int columna);

/*
 * PRE: { 0 <= columna < n }
 * DESCRIPCIÓN: Elimina los huecos intermedios de una columna, desplazando hacia abajo los valores superiores.
 * COMPLEJIDAD: O(n)
 */
void eliminarCasillasVaciasIntermedias(Tablero &t, int columna);

/*
 * DESCRIPCIÓN: Devuelve el valor más alto contenido en el tablero.
 * COMPLEJIDAD: O(n²)
 */
int obtenerValorMaximo(Tablero t);

/*
 * DESCRIPCIÓN: Devuelve el número de filas del tablero actual.
 * COMPLEJIDAD: O(1)
 */
int numeroFilas(Tablero t);

/*
 * DESCRIPCIÓN: Devuelve el número de columnas del tablero actual.
 * COMPLEJIDAD: O(1)
 */
int numeroColumnas(Tablero t);

/*
 * PRE: { 0 <= fila < n, 0 <= columna < n }
 * DESCRIPCIÓN: Realiza una simulación de fusión de casillas sin modificar el tablero original.
 *              Usado para verificar si una celda generada aleatoriamente tiene alguna fusión posible.
 * POST: Devuelve la puntuación potencial.
 * COMPLEJIDAD: O(n²)
 */
int pistaFusionarCasillasAdyacentes(Tablero t, int fila, int columna);

#endif

