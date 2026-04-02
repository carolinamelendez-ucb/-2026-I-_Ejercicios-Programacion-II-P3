#pragma once
#include <iostream>
#include <string>
#include "Proyecto.h"

using namespace std;

class VectorProyectos {
private:
    Proyecto** proyectos;
    int tamanio;
    int cantidad;

public:
    VectorProyectos(int tamanioMax) {
        this->proyectos = new Proyecto * [tamanioMax];
        this->tamanio = tamanioMax;
        this->cantidad = 0;
    }

    void agregar(Proyecto* nuevoProyecto) {
        if (cantidad < tamanio) {
            proyectos[cantidad] = nuevoProyecto;
            cantidad++;
        }
        else {
            cout << "El vector de proyectos esta lleno, no se puede agregar" << endl;
        }
    }

    Proyecto* buscarPorCodigo(int codigoBuscado) {
        for (int i = 0; i < cantidad; i++) {
            if (proyectos[i]->getCodigo() == codigoBuscado) {
                return proyectos[i];
            }
        }
        return nullptr;
    }

    void mostrarTodos() {
        for (int i = 0; i < cantidad; i++) {
            proyectos[i]->mostrarInformacion();
        }
    }

    Proyecto* getProyectoMayorCosto() {
        if (cantidad == 0) 
        return nullptr;

        Proyecto* mayor = proyectos[0];
        for (int i = 1; i < cantidad; i++) {
            if (proyectos[i]->calcularCosto() > mayor->calcularCosto()) {
                mayor = proyectos[i];
            }
        }
        return mayor;
    }

    int getCantidad() {
        return cantidad;
    }

    void liberarMemoria() {
        for (int i = 0; i < cantidad; i++) {
            delete proyectos[i];
        }
        delete[] proyectos;
    }
};

