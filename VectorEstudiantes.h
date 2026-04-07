#pragma once
#include <iostream>
#include "Estudiante.h"
using namespace std;

class VectorEstudiantes {
private:
    Estudiante* datos;
    int capacidad;
    int tamano;

    void redimensionar() {
        capacidad *= 2;
        Estudiante* nuevo = new Estudiante[capacidad];
        for (int i = 0; i < tamano; i++)
            nuevo[i] = datos[i];
        delete[] datos;
        datos = nuevo;
    }

public:
    VectorEstudiantes(int capacidadInicial = 5)
        : capacidad(capacidadInicial), tamano(0) {
        datos = new Estudiante[capacidad];
    }

    ~VectorEstudiantes() {
        delete[] datos;
    }

    bool agregar(Estudiante e) {
        if (tamano == capacidad)
            redimensionar();
        datos[tamano++] = e;
        return true;
    }

    Estudiante obtener(int index) {
        if (index >= 0 && index < tamano)
            return datos[index];
        return Estudiante();
    }

    int getTamano() { return tamano; }
    int getCapacidad() { return capacidad; }

    bool estaLleno() { return tamano == capacidad; }

    void mostrar() {
        for (int i = 0; i < tamano; i++) {
            datos[i].mostrar();
        }
    }
};