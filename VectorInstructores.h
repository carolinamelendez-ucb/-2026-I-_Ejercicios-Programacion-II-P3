#pragma once
#include <iostream>
#include <string>
#include "Instructor.h"
using namespace std;

class VectorInstructores {
private:
    Instructor** datos;
    int cantidad;
    int tamanio;

public:
    VectorInstructores(int t) {
        tamanio = t;
        cantidad = 0;
        datos = new Instructor * [t];
    }

    void agregar(Instructor* i) {
        datos[cantidad++] = i;
    }

    Instructor* buscarLibreMenorCursos() {
        Instructor* mejor = nullptr;
        for (int i = 0; i < cantidad; i++) {
            if (datos[i]->getDisponibilidad()) {
                if (mejor == nullptr ||
                    datos[i]->getCursosRealizados() < mejor->getCursosRealizados()) {
                    mejor = datos[i];
                }
            }
        }
        return mejor;
    }

    void ordenar() {
        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = i + 1; j < cantidad; j++) {
                if (datos[i]->getCursosRealizados() >
                    datos[j]->getCursosRealizados()) {
                    swap(datos[i], datos[j]);
                }
            }
        }
    }

    void mostrar() {
        for (int i = 0; i < cantidad; i++) {
            datos[i]->mostrar();
        }
    }

    Instructor* obtener(int i) {
        return datos[i];
    }

    int getCantidad() {
        return cantidad;
    }
};
