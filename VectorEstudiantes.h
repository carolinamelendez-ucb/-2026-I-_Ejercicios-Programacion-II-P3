#pragma once
#include "Estudiante.h"

class VectorEstudiantes {
private:
    int indice;
    int tamanio;
    Estudiante** arr;
public:
    VectorEstudiantes(int t) {
        indice = 0;
        tamanio = t;
        arr = new Estudiante * [t];
    }

    void agregar(Estudiante* e) {
        if (indice < tamanio)
            arr[indice++] = e;
    }

    Estudiante* buscarPorCi(string ci) {
        for (int i = 0; i < indice; i++)
            if (arr[i]->getCi() == ci)
                return arr[i];
        return nullptr;
    }

    int getIndice() { return indice; }
    Estudiante* get(int i) { return arr[i]; }
};
