#pragma once
#include "Prestamo.h"

class VectorPrestamos {

private:
    Prestamo** prestamos;
    int indice;
    int tamanio;

public:

    VectorPrestamos(int t) : tamanio(t), indice(0) {
        prestamos = new Prestamo * [t];
    }

    ~VectorPrestamos() {
        for (int i = 0; i < indice; i++) delete prestamos[i];
        delete[] prestamos;
    }

    void agregar(Prestamo* p) {
        if (indice < tamanio) {
            prestamos[indice++] = p;
        }
    }

    Prestamo* buscarActivo(int ci, int codigo) {
        for (int i = 0; i < indice; i++) {
            if (prestamos[i]->getCi() == ci &&
                prestamos[i]->getCodigoLibro() == codigo &&
                prestamos[i]->estaActivo()) {
                return prestamos[i];
            }
        }
        return nullptr;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            prestamos[i]->mostrar();
            cout << endl;
        }
    }
};
