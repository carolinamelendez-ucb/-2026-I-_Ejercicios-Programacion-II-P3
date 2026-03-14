#pragma once
#include <iostream>

using namespace std;

class Sala {

private:
    int numero;
    int filas;
    int asientosFila;

public:

    Sala(int numero, int filas, int asientosFila)
        : numero(numero), filas(filas), asientosFila(asientosFila)
    {
    }

    int getCapacidad() {
        return filas * asientosFila;
    }

    int getNumero() {
        return numero;
    }

    void mostrar() {
        cout << "Sala: " << numero << endl;
        cout << "Filas: " << filas << endl;
        cout << "Asientos por fila: " << asientosFila << endl;
    }
};