#pragma once
#include "Libro.h"

class VectorLibros {

private:
    Libro** libros;
    int indice;
    int tamanio;

public:

    VectorLibros(int t) : tamanio(t), indice(0) {
        libros = new Libro * [t];
    }

    ~VectorLibros() {
        for (int i = 0; i < indice; i++) delete libros[i];
        delete[] libros;
    }

    void agregar(Libro* l) {
        if (buscar(l->getCodigo()) != nullptr) {
            cout << "Codigo duplicado" << endl;
            delete l;
            return;
        }

        if (indice < tamanio) {
            libros[indice++] = l;
        }
    }

    Libro* buscar(int codigo) {
        for (int i = 0; i < indice; i++) {
            if (libros[i]->getCodigo() == codigo) return libros[i];
        }
        return nullptr;
    }
};
