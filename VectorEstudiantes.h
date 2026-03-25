#pragma once
#include "Estudiante.h"

class VectorEstudiantes {

private:
    Estudiante** estudiantes;
    int indice;
    int tamanio;

public:

    VectorEstudiantes(int t) : tamanio(t), indice(0) {
        estudiantes = new Estudiante * [t];
    }

    ~VectorEstudiantes() {
        for (int i = 0; i < indice; i++) delete estudiantes[i];
        delete[] estudiantes;
    }

    void agregar(Estudiante* e) {
        if (buscar(e->getCi()) != nullptr) {
            cout << "CI duplicado" << endl;
            delete e;
            return;
        }

        if (indice < tamanio) {
            estudiantes[indice++] = e;
        }
    }

    Estudiante* buscar(int ci) {
        for (int i = 0; i < indice; i++) {
            if (estudiantes[i]->getCi() == ci) return estudiantes[i];
        }
        return nullptr;
    }

    void mostrarTop() {
        for (int i = 0; i < indice; i++) {
            if (estudiantes[i]->getPrestamos() == 5) {
                estudiantes[i]->mostrar();
                cout << endl;
            }
        }
    }
};
