#pragma once
#include "Curso.h"

class VectorCursos {
private:
    int indice, tamanio;
    Curso** arr;
public:
    VectorCursos(int t) {
        indice = 0;
        tamanio = t;
        arr = new Curso * [t];
    }

    void agregar(Curso* c) {
        if (indice < tamanio)
            arr[indice++] = c;
    }

    Curso* buscar(string cod) {
        for (int i = 0; i < indice; i++)
            if (arr[i]->getCodigo() == cod)
                return arr[i];
        return nullptr;
    }

    int getIndice() { return indice; }
    Curso* get(int i) { return arr[i]; }
};
