#pragma once
#include <iostream>
#include <string>

using namespace std;

// registro sala
template <typename t>
class Sala {
public:
    t numero;
    int filas;
    int asientos_por_fila;

    Sala(t numero = t(), int filas = 0, int asientos_por_fila = 0) {
        this->numero = numero;
        this->filas = filas;
        this->asientos_por_fila = asientos_por_fila;
    }

    void mostrar() {
        cout << "sala numero: " << numero << " filas: " << filas << " asientos por fila: " << asientos_por_fila << endl;
    }
};
