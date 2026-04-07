#pragma once
#include <iostream>
#include "Curso.h"
using namespace std;

class VectorCursos {
private:
    Curso** datos;
    int capacidad;
    int tamano;

    void redimensionar() {
        capacidad *= 2;
        Curso** nuevo = new Curso * [capacidad];
        for (int i = 0; i < tamano; i++)
            nuevo[i] = datos[i];
        delete[] datos;
        datos = nuevo;
    }

public:
    VectorCursos()
        : capacidad(5), tamano(0) {
        datos = new Curso * [capacidad];
    }

    ~VectorCursos() {
        for (int i = 0; i < tamano; i++)
            delete datos[i];
        delete[] datos;
    }

    void agregar(Curso* curso) {
        if (tamano == capacidad)
            redimensionar();
        datos[tamano++] = curso;
    }

    Curso* obtener(int index) {
        if (index >= 0 && index < tamano)
            return datos[index];
        return nullptr;
    }

    Curso* buscarPorId(int id) {
        for (int i = 0; i < tamano; i++) {
            if (datos[i]->getId() == id)
                return datos[i];
        }
        return nullptr;
    }

    int getTamano() { return tamano; }

    void mostrar() {
        for (int i = 0; i < tamano; i++) {
            datos[i]->mostrar();
        }
    }
};