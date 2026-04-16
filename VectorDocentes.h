#pragma once
#include "Docente.h"

class VectorDocentes {
private:
    int indice, tamanio;
    Docente** arr;
public:
    VectorDocentes(int t) {
        indice = 0;
        tamanio = t;
        arr = new Docente * [t];
    }

    void agregar(Docente* d) {
        if (indice < tamanio)
            arr[indice++] = d;
    }

    Docente* buscarPorCi(string ci) {
        for (int i = 0; i < indice; i++)
            if (arr[i]->getCi() == ci)
                return arr[i];
        return nullptr;
    }

    int getIndice() { return indice; }
    Docente* get(int i) { return arr[i]; }
};