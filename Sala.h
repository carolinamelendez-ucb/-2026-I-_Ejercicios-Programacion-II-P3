#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Funcion.h"
#include "ArrayGenerico.h"

class Sala {
    private:
    int nroSala;
    int numeroFilas;
    int asientosPorFila;
    Funcion* funcionAsignada;   // 6. Asignar función a una sala

    public:
    Sala () : nroSala (0), numeroFilas (0), asientosPorFila (0), funcionAsignada (nullptr) {}

    Sala (int nroSala, int filas, int asientos)
        : nroSala (nroSala), numeroFilas (filas),
        asientosPorFila (asientos), funcionAsignada (nullptr) {
    }

    int getNroSala () const { return nroSala; }

    // 6. Asignar función a una sala
    void asignarFuncion (Funcion* f) {
        funcionAsignada = f;
        cout << "  Funcion #" << f->getNroFuncion ()
            << " asignada a sala " << nroSala << endl;
    }

    void mostrar () const {
        cout << "  Sala #" << nroSala
            << " | Filas: " << numeroFilas
            << " | Asientos/Fila: " << asientosPorFila;
        if(funcionAsignada)
            cout << " | Funcion asignada: #" << funcionAsignada->getNroFuncion ();
        else
            cout << " | Sin funcion asignada";
        cout << endl;
    }
};