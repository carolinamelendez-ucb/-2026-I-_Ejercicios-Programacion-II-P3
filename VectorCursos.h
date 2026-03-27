#pragma once
#include <iostream>
#include <string>
#include "Curso.h"
using namespace std;

class VectorCursos {
private:
    Curso** datos;
    int cantidad;
    int tamanio;

public:
    VectorCursos(int t) {
        tamanio = t;
        cantidad = 0;
        datos = new Curso * [t];
    }

    void agregar(Curso* c) {
        datos[cantidad++] = c;
    }

    Curso* buscar(int id) {
        for (int i = 0; i < cantidad; i++) {
            if (datos[i]->getId() == id)
                return datos[i];
        }
        return nullptr;
    }

    void mostrar() {
        for (int i = 0; i < cantidad; i++) {
            datos[i]->mostrar();
        }
    }
};
