

#include "TAD_Juego.h"
#include "entorno.h"
#include "TAD_Casilla.h"
#include "TAD_Tablero.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

void iniciarJuego(Juego &g) {
	int numFilas, numColumnas, comoIniciar, filasIniciales;
	int m[MAX_FILAS][MAX_COL];
	if (entornoCargarConfiguracion(numFilas, numColumnas, comoIniciar, filasIniciales, m)) {
    	iniciarTablero(g.tablero);
    	entornoIniciar(numFilas, numColumnas);
    	int fila;
    	int columna;
    	for (fila = 0; fila < numeroFilas(g.tablero); fila++) {
   				 for (columna = 0; columna < numeroColumnas(g.tablero); columna++){
   					 if (casillaEstaVacia(g.tablero,fila,columna))
   						 entornoEliminarNumero(fila, columna);
   					 else
   						 entornoPonerNumero(fila, columna, obtenerValorTablero(g.tablero,fila, columna));
   				 }
    	}
    	g.puntuacion = 0;
    	entornoPonerPuntuacion(g.puntuacion);
	}
}


void refrescarJuego (Juego &g, string &mensaje, bool &salir, int &valor, int &fila, int &columna ){
    srand (time(NULL));
    int maxPotencia;
    maxPotencia = log2(obtenerValorMaximo(g.tablero));
    valor = pow(2, rand() % maxPotencia + 1);
    entornoPonerNumeroLanzador(valor, columna);
    entornoPonerPuntuacion(g.puntuacion);
    int i;
    int j;
    for (i = 0; i < numeroFilas(g.tablero); i++) {
   		 for (j = 0; j < numeroColumnas(g.tablero); j++){
   			 if (casillaEstaVacia(g.tablero,i,j))
   				 entornoEliminarNumero(i,j);
   			 else
   				 entornoPonerNumero(i,j,obtenerValorTablero(g.tablero,i,j));

   		 }
    }

    if (tableroEstaLleno(g.tablero)){
   	 salir = true;
   	 mensaje="Has perdido";
   	 for (i = 0; i < numeroColumnas(g.tablero);i++){
   		 if (obtenerValorTablero(g.tablero,numeroFilas(g.tablero) - 1,i) == valor){
   			 salir=false;
   			 mensaje = "";
   		 }
   	 }
    }
}


void jugar(Juego &g, string &mensaje, bool &salir, int &valor, int &fila, int &columna){
    TipoTecla tecla;
    tecla = entornoLeerTecla();

   			 switch (tecla) {
   			 case TEnter:
   				  if (!columnaEstaLlena(g.tablero,columna)){
   					  fila = filaPrimeraCasillaVacia(g.tablero, columna);
   					  entornoQuitarNumeroLanzador(columna);
   					  entornoPonerNumero(fila, columna, valor);
   					  insertarValorTablero (g.tablero,fila,columna,valor);
   					  entornoPausa(0.5);
   					  g.puntuacion = g.puntuacion + fusionarCasillasAdyacentes(g.tablero, fila, columna);
   					  eliminarCasillasVaciasIntermedias(g.tablero, columna);
   					  eliminarCasillasVaciasIntermedias(g.tablero, columna - 1);
   					  eliminarCasillasVaciasIntermedias(g.tablero, columna + 1);
   					  refrescarJuego(g,mensaje,salir,valor,fila,columna);
   					 }
   				  else {
   					  if (obtenerValorTablero(g.tablero,numeroFilas(g.tablero) -1,columna) == valor){
   				     	 entornoQuitarNumeroLanzador(columna);
   				     	 entornoPonerNumero(numeroFilas(g.tablero)-1, columna, valor*2);
   				     	 insertarValorTablero (g.tablero,numeroFilas(g.tablero)-1, columna, valor*2);
   				     	 entornoPausa(0.5);
   				     	 g.puntuacion = g.puntuacion + valor * 2;
   				     	 refrescarJuego(g,mensaje,salir,valor,fila,columna);
   					  }
   				  }

   				 break;
   			 case TDerecha:
   				 entornoQuitarNumeroLanzador(columna);

   				 if (columna < numeroColumnas(g.tablero) - 1)
   					 columna++;
   				 else
   					 columna = 0;

   				 entornoPonerNumeroLanzador(valor, columna);

   				 break;
   			 case TIzquierda:
   					 entornoQuitarNumeroLanzador(columna);

   				 if (columna > 0)
   					 columna--;
   				 else
   					 columna = numeroColumnas(g.tablero) - 1;

   				 entornoPonerNumeroLanzador(valor, columna);

   				 break;

   			 case TF1:
   				 break;
   			 case TF2:
   				 break;

   			 case TSalir:
   				 mensaje = "Has abandonado";
   				 salir = true;
   				 break;
   			 case TNada:
   				 break;
   			 }
}


void terminarJuego(Juego g, string mensaje){
    entornoMostrarMensajeFin(mensaje);
    entornoPausa(1.222);
    entornoTerminar();
}





