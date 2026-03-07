#pragma once
#include <iostream>
#include "Competencia.h"

using namespace std;

class CompetenciasVector {

private:

    Competencia** competencias;
    int tamanio;
    int indice;

public:

    CompetenciasVector(int tamanio) {
        this->competencias = new Competencia * [tamanio];
        this->indice = 0;
        this->tamanio = tamanio;
    }

    void agregar(Competencia* nuevaCompetencia) {
        competencias[indice] = nuevaCompetencia;
        indice++;
    }

    void mostrar() {

        for (int i = 0; i < indice; i++) {

            competencias[i]->mostrar();
            cout << endl;
        }
    }
};