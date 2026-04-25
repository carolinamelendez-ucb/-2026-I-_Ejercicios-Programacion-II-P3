#pragma once
#include <iostream>
using namespace std;

class Sala {
private:
    int numeroSala;
    int filas;
    int asientosPorFila;

public:
    Sala() : numeroSala(0), filas(0), asientosPorFila(0) {}

    Sala(int num, int f, int asientos)
        : numeroSala(num), filas(f), asientosPorFila(asientos) {
    }

    void registrar() {
        cout << "Número de sala: ";
        cin >> numeroSala;
        cout << "Número de filas: ";
        cin >> filas;
        cout << "Asientos por fila: ";
        cin >> asientosPorFila;
    }

    void mostrar() const {
        cout << "Sala " << numeroSala << " | Filas: " << filas
            << " | Asientos/fila: " << asientosPorFila
            << " | Capacidad total: " << (filas * asientosPorFila);
    }

    int getNumeroSala() const { return numeroSala; }
    int getFilas() const { return filas; }
    int getAsientosPorFila() const { return asientosPorFila; }
};