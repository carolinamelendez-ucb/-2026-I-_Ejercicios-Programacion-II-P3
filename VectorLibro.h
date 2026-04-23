#pragma once
#include "Libro.h"

class VectorLibro {
private:
    int indice;
    int tamanio;
    Libro** listaLibros;

public:
    VectorLibro(int tamanio) {
        this->indice = 0;
        this->tamanio = tamanio;
        this->listaLibros = new Libro * [tamanio];
    }

    void agregarLibro(Libro* libro) {
        if (indice < tamanio) {
            listaLibros[indice] = libro;
            indice++;
        }
    }

    Libro* buscarLibro(int codigo) {
        for (int i = 0; i < indice; i++) {
            if (listaLibros[i]->getCodigo() == codigo)
                return lista[i];
        }
        return nullptr;
    }

    Libro* masSolicitado() {
        Libro* max = lista[0];
        for (int i = 1; i < indice; i++) {
            if (listaLibros[i]->getVecesPrestado() > max->getVecesPrestado())
                max = lista[i];
        }
        return max;
    }
};
