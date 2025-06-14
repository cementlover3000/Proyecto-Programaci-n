#ifndef TAD_JUEGO_H
#define TAD_JUEGO_H
#include "TAD_Tablero.h"

struct Juego {
    Tablero tablero;   // Tablero lógico del juego
    int puntuacion;    // Puntuación actual
};

/*
 * DESCRIPCIÓN: Inicializa una partida de juego. Carga parámetros desde el archivo de configuración,
 *              crea e inicializa el tablero lógico, y dibuja el estado inicial en la interfaz.
 * POST: El juego está listo para comenzar.
 * COMPLEJIDAD: O(n²)
 */
void iniciarJuego(Juego &g);

/*
 * DESCRIPCIÓN: Refresca el estado del juego después de una jugada.
 *              Genera una nueva ficha aleatoria, actualiza el tablero gráfico
 *              y comprueba si la partida ha terminado.
 * POST: Se actualiza el valor, la puntuación y el estado visual del tablero.
 * COMPLEJIDAD: O(n²)
 */
void refrescarJuego(Juego &g, string &mensaje, bool &salir, int &valor, int &fila, int &columna);

/*
 * DESCRIPCIÓN: Gestiona una jugada completa del usuario.
 *              Lee la tecla pulsada, inserta la ficha, gestiona fusiones,
 *              actualiza puntuación y comprueba condiciones de fin.
 * POST: Se actualiza el estado interno del juego y el tablero visual.
 * COMPLEJIDAD: O(n²)
 */
void jugar(Juego &g, string &mensaje, bool &salir, int &valor, int &fila, int &columna);

/*
 * DESCRIPCIÓN: Finaliza el juego, muestra un mensaje de fin y cierra la interfaz gráfica.
 * POST: La interfaz se cierra tras una pausa.
 * COMPLEJIDAD: O(1)
 */
void terminarJuego(Juego g, string mensaje);

#endif

#endif




