#pragma once
#include "Proyecto.h"

class VectorProyectos {

private:
    Proyecto** proyectos;
    int indice;
    int tamanio;

public:

    VectorProyectos(int tamanio) : tamanio(tamanio), indice(0) {
        proyectos = new Proyecto * [tamanio];
    }

    ~VectorProyectos() {
        for (int i = 0; i < indice; i++) delete proyectos[i];
        delete[] proyectos;
    }

    Proyecto* buscar(string codigo) {
        for (int i = 0; i < indice; i++) {
            if (proyectos[i]->getCodigo() == codigo) return proyectos[i];
        }
        return nullptr;
    }

    void agregar(Proyecto* nuevoProyecto) {
        if (buscar(nuevoProyecto->getCodigo()) != nullptr) {
            cout << "Codigo duplicado" << endl;
            delete nuevoProyecto;
            return;
        }

        if (indice < tamanio) {
            proyectos[indice++] = nuevoProyecto;
        }
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            cout << "PROYECTO " << i + 1 << endl;
            proyectos[i]->mostrar();
            cout << "Costo: " << proyectos[i]->calcularCosto() << endl;
            cout << endl;
        }
    }

    Proyecto* mayorCosto() {
        if (indice == 0) return nullptr;

        Proyecto* mayor = proyectos[0];

        for (int i = 1; i < indice; i++) {
            if (proyectos[i]->calcularCosto() > mayor->calcularCosto()) {
                mayor = proyectos[i];
            }
        }
        return mayor;
    }
};
