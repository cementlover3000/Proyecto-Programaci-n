#include <iostream>
#include "PruebasTAD_Tablero.h"
#include "fstream"
using namespace std;

bool esPotenciaDeDos(int valor) {
    int resultado;
	if (valor <= 0) {
    	resultado = false;
	}
	while (valor % 2 == 0) {
    	valor = valor / 2;
	}
	resultado = valor == 1;
	return resultado;
}

bool compararTableros(Tablero& t1, Tablero& t2) {
    bool resultado;
    resultado = true;
	if (t1.filas != t2.filas || t1.columnas != t2.columnas) {
    	resultado = false;
	}
	int i;
	int j;
	for (i = 0; i < t1.filas; ++i) {
    	for (j = 0; j < t1.columnas; ++j) {
        	if (obtenerValorTablero(t1, i, j) != obtenerValorTablero(t2, i, j)) {
       		 resultado = false;
        	}
    	}
	}

	return resultado;
}


void pruebaIniciarTablero() {
	Tablero tableroLeido;
	iniciarTablero(tableroLeido);
	Tablero tableroEsperado;
	ifstream archivo("numberTiles.cnf");


	int filas, columnas, comoIniciar, filasIniciales;
	archivo >> filas >> columnas >> comoIniciar >> filasIniciales;

	tableroEsperado.filas = filas;
	tableroEsperado.columnas = columnas;
	vaciarTablero(tableroEsperado);
	if (comoIniciar == 0) {
    	string cadena;
    	getline(archivo, cadena);
    	int i;
    	int j;
    	for (i = 0; i < filas; i++) {
        	for (j = 0; j < columnas; j++) {
            	if (i < filasIniciales) {
                	if (j < columnas - 1) {
                    	std::getline(archivo, cadena, ' ');
                	} else {
                    	std::getline(archivo, cadena);
                	}
                	int valor = std::atoi(cadena.c_str());
                	insertarValorTablero(tableroEsperado, i, j, valor);
            	}
        	}
    	}
	}

	if (compararTableros(tableroLeido, tableroEsperado)) {
    	cout << "Prueba Iniciar Tablero: OK" << endl;
	}
	else {
    	cout << "Prueba Iniciar Tablero: ERROR" << endl;
	}
}






void pruebaVaciarTablero() {
	Tablero t;
	iniciarTablero(t);
	vaciarTablero(t);
	bool estaVacio;
	int i;
	int j;
	estaVacio = true;
	for (i = 0; i < t.filas; i++) {
    	for (j = 0; j < t.columnas; j++) {
        	if (!casillaEstaVacia(t, i, j)) {
            	estaVacio = false;
        	}
    	}
	}
	if (estaVacio && t.ocupadas == 0) {
    	cout << "Prueba Vaciar Tablero: OK" << endl;
	}
	else{
   	 cout << "Prueba Vaciar Tablero: ERROR" << endl;
	}
}

void pruebaIniciarTableroAleatorio() {
	Tablero t;
	vaciarTablero(t);
	iniciarTableroAleatorio(t, FILAS, COLUMNAS, 3, 5); //

	bool potenciaDeDos;
	int i;
	int j;
	int valor;
	potenciaDeDos = true;
	for (i = 0; i < 3; i++) {
    	for (j = 0; j < COLUMNAS; j++) {
        	valor = obtenerValorTablero(t, i, j);
        	if (!esPotenciaDeDos(valor)) {
            	potenciaDeDos = false;
        	}
    	}
	}
	if (potenciaDeDos && t.ocupadas == 3 * COLUMNAS) {
    	cout << "Prueba Iniciar Tablero Aleatorio: OK" << endl;
	}
	else {
    	cout << "Prueba Iniciar Tablero Aleatorio: ERROR" << endl;
	}
}


void pruebaInsertarValorTablero() {
	//Prueba 1
    Tablero t;
    vaciarTablero(t);
	iniciarTableroAleatorio(t, 5, 5, 3, 5);
	insertarValorTablero(t, 0, 0, 5);

	if(obtenerValorTablero(t, 0, 0) == 5 && t.ocupadas == 15){
   	 cout << "Prueba 1 Insertar Valor Tablero: OK" << endl;
	}
	else{
   	 cout << "Prueba 1 Insertar Valor Tablero: ERROR" << endl;
	}

	//Prueba 2
	insertarValorTablero(t, 5, 5, 7);
	if(obtenerValorTablero(t, 5, 5) == 7 && t.ocupadas == 16){
    	cout << "Prueba 2 Insertar Valor Tablero: OK" << endl;
	}
	else{
   	 cout << "Prueba 2 Insertar Valor Tablero: ERROR" << endl;
	}

	//Prueba 3
    	insertarValorTablero(t, 4, 3, 22);
    	if(obtenerValorTablero(t, 4, 3) == 22 && t.ocupadas == 17){
        	cout << "Prueba 3 Insertar Valor Tablero: OK" << endl;
    	}
    	else{
   		 cout << "Prueba 3 Insertar Valor Tablero: ERROR" << endl;
    	}
}


void pruebaCasillaEstaVacia() {
	// Prueba 1
	Tablero t;
	vaciarTablero(t);
	bool resultado;
	resultado = casillaEstaVacia(t, 2, 1);

	if (resultado) {
    	cout << "Prueba 1 Casilla Esta Vacía: OK" << endl;
	} else {
    	cout << "Prueba 1 Casilla Esta Vacía: ERROR" << endl;
	}

	// Prueba 2
	iniciarTableroAleatorio(t, 5, 5, 3, 5);
	resultado = casillaEstaVacia(t, 0, 0);

	if (!resultado) {
    	cout << "Prueba 2 Casilla Esta Vacía: OK" << endl;
	} else {
    	cout << "Prueba 2 Casilla Esta Vacía: ERROR" << endl;
	}
}


void pruebaObtenerValorTablero() {
	Tablero t;
	vaciarTablero(t);

	// Prueba 1
	int valor;
	valor = obtenerValorTablero(t, 1, 1);
	if (valor == 0) {
    	cout << "Prueba 1 Obtener Valor Tablero: OK" << endl;
	} else {
    	cout << "Prueba 1 Obtener Valor Tablero: ERROR" << endl;
	}

	// Prueba 2:
	insertarValorTablero(t, 0, 0, 16);
	valor = obtenerValorTablero(t, 0, 0);
	if (valor == 16) {
    	cout << "Prueba 2 Obtener Valor Tablero: OK" << endl;
	} else {
    	cout << "Prueba 2 Obtener Valor Tablero: ERROR" << endl;
	}

	// Prueba 3
	insertarValorTablero(t, 3, 2, 64);
	valor = obtenerValorTablero(t, 3, 2);
	if (valor == 64) {
    	cout << "Prueba 3 Obtener Valor Tablero: OK" << endl;
	} else {
    	cout << "Prueba 3 Obtener Valor Tablero: ERROR" << endl;
	}
}


void pruebaVaciarCasillaTablero(){
    Tablero t;

    // Prueba 1
    vaciarTablero(t);
    int ocupadas;
    ocupadas = t.ocupadas;
    vaciarCasillaTablero(t, 1, 1);
    if (t.ocupadas == ocupadas && casillaEstaVacia(t, 1, 1)) {
    	cout << "Prueba 1 Vaciar Casilla Tablero: OK" << endl;
    }
    else {
    	cout << "Prueba 1 Vaciar Casilla Tablero: ERROR" << endl;
    }

    // Prueba 2
    vaciarTablero(t);
    insertarValorTablero(t, 2, 2, 32);
    ocupadas = t.ocupadas;
    vaciarCasillaTablero(t, 2, 2);
    if (t.ocupadas == ocupadas - 1 && casillaEstaVacia(t, 2, 2)) {
    	cout << "Prueba 2 Vaciar Casilla Tablero: OK" << endl;
    }
    else {
    	cout << "Prueba 2 Vaciar Casilla Tablero: ERROR" << endl;
    }
}

void pruebaColumnaEstaLlena(){
    Tablero t;
    t.filas = FILAS;
    t.columnas = COLUMNAS;
    vaciarTablero(t);

    // Prueba 1
    bool resultado;
    resultado = columnaEstaLlena(t, 1);
    if (!resultado) {
    	cout << "Prueba 1 Columna Esta Llena: OK" << endl;
    } else {
    	cout << "Prueba 1 Columna Esta Llena: ERROR" << endl;
    }

    // Prueba 2
    int fila;
    for (fila = 0; fila < t.filas; fila++) {
    	insertarValorTablero(t, fila, 0, 3);
    }
    resultado = columnaEstaLlena(t, 0);
    if (resultado) {
    	cout << "Prueba 2 Columna Esta Llena: OK" << endl;
    } else {
    	cout << "Prueba 2 Columna Esta Llena: ERROR" << endl;
    }

    // Prueba 3

    for (fila = 0; fila < t.filas - 1; fila++) {
    	insertarValorTablero(t, fila, 2, 3);
    }
    resultado = columnaEstaLlena(t, 2);
    if (!resultado) {
    	cout << "Prueba 3 Columna Esta Llena: OK" << endl;
    } else {
    	cout << "Prueba 3 Columna Esta Llena: ERROR" << endl;
    }

}


void pruebaFilaPrimeraCasillaVacia(){
    Tablero t;
    t.filas = FILAS;
    t.columnas = COLUMNAS;
    vaciarTablero(t);

    // Prueba 1
    int fila;
    int resultado;
    for (fila = 0; fila < t.filas; fila++) {
    	insertarValorTablero(t, fila, 0, 2);
    }
    resultado = filaPrimeraCasillaVacia(t, 0);
    if (resultado == t.filas) {
    	cout << "Prueba 1 Fila Primera Casilla Vacia: OK" << endl;
    }
    else {
    	cout << "Prueba 1 Fila Primera Casilla Vacia: ERROR" << endl;
    }

    // Prueba 2
    vaciarTablero(t);
    resultado = filaPrimeraCasillaVacia(t, 1);
    if (resultado == 0) {
    	cout << "Prueba 2 Fila Primera Casilla Vacia: OK" << endl;
    }
    else {
    	cout << "Prueba 2 Fila Primera Casilla Vacia: ERROR" << endl;
    }

    // Prueba 3:
    insertarValorTablero(t, 0, 2, 4);
    insertarValorTablero(t, 1, 2, 8);
    resultado = filaPrimeraCasillaVacia(t, 2);
    if (resultado == 2) {
    	cout << "Prueba 3 Fila Primera Casilla Vacia: OK" << endl;
    }
    else {
    	cout << "Prueba 3 Fila Primera Casilla Vacia: ERROR" << endl;
    }
}


void pruebaTableroEstaLleno(){
    Tablero t;
    t.filas = FILAS;
    t.columnas = COLUMNAS;

    // Prueba 1
    vaciarTablero(t);
    if (!tableroEstaLleno(t)) {
    	cout << "Prueba 1 Tablero Esta Lleno: OK" << endl;
    }
    else {
    	cout << "Prueba 1 Tablero Esta Lleno: ERROR" << endl;
    }

    // Prueba 2
    int fila;
    int columna;
    for (fila = 0; fila < t.filas; fila++) {
    	for (columna = 0; columna < t.columnas; columna++) {
        	insertarValorTablero(t, fila, columna, 2);
    	}
    }
    if (tableroEstaLleno(t)) {
    	cout << "Prueba 2 Tablero Esta Lleno: OK" << endl;
    }
    else {
    	cout << "Prueba 2 Tablero Esta Lleno: ERROR" << endl;
    }

    // Prueba 3
    vaciarTablero(t);
    for (fila = 0; fila < t.filas; fila++) {
    	for (columna = 0; columna < t.columnas; columna++) {
        	if (!(fila == 0 && columna == 0)) {
            	insertarValorTablero(t, fila, columna, 4);
        	}
    	}
    }
    if (!tableroEstaLleno(t)) {
    	cout << "Prueba 3 Tablero Esta Lleno: OK" << endl;
    }
    else {
    	cout << "Prueba 3 Tablero Esta Lleno: ERROR" << endl;
    }
}

void pruebaFusionarCasillasAdyacentes(){
    	Tablero t;
    	t.filas = FILAS;
    	t.columnas = COLUMNAS;

    	// Prueba 1
    	int resultado;
    	vaciarTablero(t);
    	insertarValorTablero(t, 1, 1, 2);
    	insertarValorTablero(t, 1, 2, 2);
    	resultado = fusionarCasillasAdyacentes(t, 1, 1);
    	if (obtenerValorTablero(t, 1, 1) == 4 && casillaEstaVacia(t, 1, 2) && resultado == 4) {
        	cout << "Prueba 1 Fusionar Casillas Adyacentes: OK" << endl;
    	}
    	else {
        	cout << "Prueba 1 Fusionar Casillas Adyacentes: ERROR" << endl;
    	}


    	//Prueba 2
    	vaciarTablero(t);
    	insertarValorTablero(t, 2, 1, 2);
    	insertarValorTablero(t, 2, 2, 4);
    	resultado = fusionarCasillasAdyacentes(t, 2, 1);
    	if (obtenerValorTablero(t, 2, 1) == 2 && obtenerValorTablero(t, 2, 2) == 4 && resultado == 0) {
        	cout << "Prueba 2 Fusionar Casillas Adyacentes: OK" << endl;
    	}
    	else {
        	cout << "Prueba 2 Fusionar Casillas Adyacentes: ERROR" << endl;
    	}

    	// Prueba 3
    	vaciarTablero(t);
    	insertarValorTablero(t, 3, 1, 2);
    	insertarValorTablero(t, 2, 1, 2);
    	insertarValorTablero(t, 3, 2, 2);
    	resultado = fusionarCasillasAdyacentes(t, 3, 1);
    	if (obtenerValorTablero(t, 3, 1) == 8 && casillaEstaVacia(t, 2, 1) && casillaEstaVacia(t, 3, 2) && resultado == 8) {
        	cout << "Prueba 3 Fusionar Casillas Adyacentes: OK" << endl;
    	}
    	else {
        	cout << "Prueba 3 Fusionar Casillas Adyacentes: ERROR" << endl;
    	}
}


void pruebaEliminarCasillasVaciasIntermedias() {
	Tablero t;
	t.filas = FILAS;
	t.columnas = COLUMNAS;

	// Prueba 1
	vaciarTablero(t);
	insertarValorTablero(t, 0, 0, 2);
	insertarValorTablero(t, 1, 0, 4);
	insertarValorTablero(t, 3, 0, 8);
	eliminarCasillasVaciasIntermedias(t, 0);
	if (obtenerValorTablero(t, 1, 0) == 4 && obtenerValorTablero(t, 2, 0) == 8) {
    	cout << "Prueba 1 Eliminar Casillas Vacias Intermedias: OK" << endl;
	} else {
    	cout << "Prueba 1 Eliminar Casillas Vacias Intermedias: ERROR" << endl;
	}

	//Prueba 2
	vaciarTablero(t);
	insertarValorTablero(t, 0, 0, 2);
	insertarValorTablero(t, 1, 0, 4);
	eliminarCasillasVaciasIntermedias(t, 0);
	if (obtenerValorTablero(t, 0, 0) == 2 && obtenerValorTablero(t, 1, 0) == 4) {
    	cout << "Prueba 2 Eliminar Casillas Vacias Intermedias: OK" << endl;
	} else {
    	cout << "Prueba 2 Eliminar Casillas Vacias Intermedias: ERROR" << endl;
	}

	// Prueba 3
	vaciarTablero(t);
	insertarValorTablero(t, 0, 0, 2);
	insertarValorTablero(t, 1, 0, 4);
	insertarValorTablero(t, 4, 0, 8);
	insertarValorTablero(t, 5, 0, 16);
	eliminarCasillasVaciasIntermedias(t, 0);
	if (obtenerValorTablero(t, 1, 0) == 4 && obtenerValorTablero(t, 2, 0) == 8 && obtenerValorTablero(t, 3, 0) == 16) {
    	cout << "Prueba 3 Eliminar Casillas Vacias Intermedias: OK" << endl;
	} else {
    	cout << "Prueba 3 Eliminar Casillas Vacias Intermedias: ERROR" << endl;
	}
}


void pruebaObtenerValorMaximo() {
	Tablero t;
	t.filas = FILAS;
	t.columnas = COLUMNAS;

	// Prueba 1
	vaciarTablero(t);
	int maxValor;
	maxValor = obtenerValorMaximo(t);
	if (maxValor == 0) {
    	cout << "Prueba 1 Obtener Valor Maximo: OK" << endl;
	}
	else {
    	cout << "Prueba 1 Obtener Valor Maximo: ERROR" << endl;
	}

	// Prueba 2
	vaciarTablero(t);
	insertarValorTablero(t, 0, 0, 4);
	insertarValorTablero(t, 1, 1, 4);
	insertarValorTablero(t, 2, 2, 4);
	maxValor = obtenerValorMaximo(t);
	if (maxValor == 4) {
    	cout << "Prueba 2 Obtener Valor Maximo: OK" << endl;
	} else {
    	cout << "Prueba 2 Obtener Valor Maximo: ERROR" << endl;
	}

	// Prueba 3
	vaciarTablero(t);
	int i;
	int j;
	for (i = 0; i < FILAS; i++) {
    	for (j = 0; j < COLUMNAS; j++) {
        	insertarValorTablero(t, i, j, (i + 1) * (j + 1));
    	}
	}
	maxValor = obtenerValorMaximo(t);
	if (maxValor == 49) {
    	cout << "Prueba 3 Obtener Valor Maximo: OK" << endl;
	}
	else {
    	cout << "Prueba 3 Obtener Valor Maximo: ERROR" << endl;
	}
}


void pruebaNumeroFilas() {
	Tablero t;
	t.filas = FILAS;
	if (numeroFilas(t) == FILAS) {
    	cout << "Prueba Numero Filas: OK" << endl;
	}
	else {
    	cout << "Prueba Numero Filas: ERROR" << endl;
	}
}

void pruebaNumeroColumnas() {
	Tablero t;
	t.columnas = COLUMNAS;
	if (numeroColumnas(t) == COLUMNAS) {
    	cout << "Prueba Numero Columnas: OK" << endl;
	}
	else {
    	cout << "Prueba Numero Columnas: ERROR" << endl;
	}
}


void ejecutarPruebasTAD_Tablero() {
	cout << "Inicio Pruebas TAD_Tablero:" << endl;

	pruebaVaciarTablero();
	pruebaIniciarTableroAleatorio();
	pruebaIniciarTablero();
	pruebaInsertarValorTablero();
	pruebaCasillaEstaVacia();
	pruebaObtenerValorTablero();
	pruebaVaciarCasillaTablero();
	pruebaColumnaEstaLlena();
	pruebaFilaPrimeraCasillaVacia();
	pruebaTableroEstaLleno();
	pruebaFusionarCasillasAdyacentes();
	pruebaEliminarCasillasVaciasIntermedias();
	pruebaObtenerValorMaximo();
	pruebaNumeroFilas();
	pruebaNumeroColumnas();

	cout << "Fin Pruebas TAD_Tablero" << endl;
}







































