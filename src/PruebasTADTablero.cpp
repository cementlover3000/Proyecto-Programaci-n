void pruebaInsertarValorTablero() {
    Tablero t;
    insertarValorTablero(t, 0, 0, 2);
    if (obtenerValorTablero(t, 0, 0) == 2) {
        cout << "Prueba insertarValorTablero: Correcta" << endl;
    } else {
        cout << "Prueba insertarValorTablero: Incorrecta" << endl;
    }
}

void pruebaCasillaEstaVacia() {
    Tablero t;
    if (casillaEstaVacia(t, 0, 0)) {
        cout << "Prueba casilla vacía inicial: Correcta" << endl;
    } else {
        cout << "Prueba casilla vacía inicial: Incorrecta" << endl;
    }
    insertarValorTablero(t, 0, 0, 4);
    if (!casillaEstaVacia(t, 0, 0)) {
        cout << "Prueba casilla ocupada: Correcta" << endl;
    } else {
        cout << "Prueba casilla ocupada: Incorrecta" << endl;
    }
}

void pruebaObtenerValorTablero() {
    Tablero t;
    insertarValorTablero(t, 1, 1, 4);
    if (obtenerValorTablero(t, 1, 1) == 4) {
        cout << "Prueba obtenerValorTablero: Correcta" << endl;
    } else {
        cout << "Prueba obtenerValorTablero: Incorrecta" << endl;
    }
}

void pruebaVaciarCasillaTablero() {
    Tablero t;
    insertarValorTablero(t, 0, 1, 8);
    vaciarCasillaTablero(t, 0, 1);
    if (casillaEstaVacia(t, 0, 1)) {
        cout << "Prueba vaciarCasillaTablero: Correcta" << endl;
    } else {
        cout << "Prueba vaciarCasillaTablero: Incorrecta" << endl;
    }
}

void pruebaColumnaEstaLlena() {
    Tablero t;
    for (int i = 0; i < FILAS; i++) {
        insertarValorTablero(t, i, 0, 2);
    }
    if (columnaEstaLlena(t, 0)) {
        cout << "Prueba columna llena: Correcta" << endl;
    } else {
        cout << "Prueba columna llena: Incorrecta" << endl;
    }
    vaciarCasillaTablero(t, 0, 0);
    if (!columnaEstaLlena(t, 0)) {
        cout << "Prueba columna no llena después de vaciar: Correcta" << endl;
    } else {
        cout << "Prueba columna no llena después de vaciar: Incorrecta" << endl;
    }
}

void pruebaTableroEstaLleno() {
    Tablero t;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            insertarValorTablero(t, i, j, 2);
        }
    }
    if (tableroEstaLleno(t)) {
        cout << "Prueba tablero lleno: Correcta" << endl;
    } else {
        cout << "Prueba tablero lleno: Incorrecta" << endl;
    }
}

void ejecutarPruebasTAD_Tablero() {
    pruebaIniciarTablero();
    pruebaInsertarValorTablero();
    pruebaCasillaEstaVacia();
    pruebaObtenerValorTablero();
    pruebaVaciarCasillaTablero();
    pruebaColumnaEstaLlena();
    pruebaTableroEstaLleno();
}
