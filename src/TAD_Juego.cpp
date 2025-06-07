

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
    	for (fila = 0; fila < numFilas; fila++) {
        	for (columna = 0; columna < numColumnas; columna++) {
       		 if(fila < filasIniciales){
       			 if(comoIniciar == 0){
       				 entornoPonerNumero(fila, columna, m[fila][columna]);
       			 }
       			 else{
       				 entornoPonerNumero(fila, columna, pow(2, rand()%comoIniciar+1));
       			 }
       		 }
       		 else{
       			 entornoEliminarNumero(fila, columna);
       		 }
        	}
    	}
    	g.puntuacion = 0;
    	entornoPonerPuntuacion(g.puntuacion);
	}
}


void refrescarJuego (Juego &g, string &mensaje, bool &salir, int &valor, int &fila, int &columna ){
    srand (time(NULL));
    int maxPotencia = log2(obtenerValorMaximo(g.tablero));
    maxPotencia = max(1, min(11, maxPotencia));
    valor = pow(2, rand() % maxPotencia + 1);
    entornoPonerNumeroLanzador(valor, columna);
    g.puntuacion = valor + obtenerPuntuacionTablero(g.tablero);
    entornoPonerPuntuacion(g.puntuacion);
    entornoContadorAyuda(g.vidas);
    for (int i = 0; i < numeroFilas(g.tablero); i++) {
   		 for (int j = 0; j < numeroColumnas(g.tablero); j++){
   			 if (casillaEstaVacia(g.tablero,i,j))
   				 entornoEliminarNumero(i,j);
   			 else
   				 entornoPonerNumero(i,j,obtenerValorTablero(g.tablero,i,j));

   		 }
    }

    if (tableroEstaLleno(g.tablero)){
   	 salir=true;
   	 mensaje="Has perdido";
   	 for (int i = 0; i < numeroColumnas(g.tablero);i++){
   		 if (obtenerValorTablero(g.tablero,numeroFilas(g.tablero)-1,i)==valor){
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
   				 fila = filaPrimeraCasillaVacia(g.tablero, columna);
   				  if (!columnaEstaLlena(g.tablero,columna)){
   					  entornoQuitarNumeroLanzador(columna);
   					  entornoPonerNumero(fila, columna, valor);
   					  insertarValorTablero (g.tablero,fila,columna,valor);
   					  fusionarCasillasAdyacentes(g.tablero,fila,columna);
   					  refrescarJuego(g,mensaje,salir,valor,fila,columna);
   					 }
   				  else if (obtenerValorTablero(g.tablero,numeroFilas(g.tablero)-1,columna)==valor){
   				     	 entornoQuitarNumeroLanzador(columna);
   				     	 entornoPonerNumero(numeroFilas(g.tablero)-1, columna, valor*2);
   				     	 insertarValorTablero (g.tablero,numeroFilas(g.tablero)-1, columna, valor*2);
   				     	 fusionarCasillasAdyacentes(g.tablero,fila,columna);
   				     	 refrescarJuego(g,mensaje,salir,valor,fila,columna);
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



