#pragma once
#include <iostream>
#include "Instructor.h"

using namespace std;

class InstructoresVector {

private:
    Instructor** instructores;
    int indice;
    int tamanio;

public:

    InstructoresVector(int tamanio)
        : tamanio(tamanio), indice(0)
    {
        instructores = new Instructor * [tamanio];
    }

    ~InstructoresVector() {
        for (int i = 0; i < indice; i++) {
            delete instructores[i];
        }

        delete[] instructores;
    }

    void agregar(Instructor* instructorNuevo) {
        if (indice < tamanio) {
            instructores[indice] = instructorNuevo;
            indice++;
        }
        else {
            cout << "No se pueden agregar mas instructores" << endl;
        }
    }

    Instructor* buscarLibreMenorCursos() {
        Instructor* mejor = nullptr;
        for (int i = 0; i < indice; i++) {
            if (instructores[i]->estaLibre()) {
                if (mejor == nullptr || instructores[i]->getCursos() < mejor->getCursos()) {
                    mejor = instructores[i];
                }
            }
        }
        return mejor;
    }

    void ordenarPorCursos() {
        for (int i = 0; i < indice - 1; i++) {
            for (int j = i + 1; j < indice; j++) {
                if (instructores[i]->getCursos() > instructores[j]->getCursos()) {
                    Instructor* aux = instructores[i];
                    instructores[i] = instructores[j];
                    instructores[j] = aux;
                }
            }
        }
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            cout << "INSTRUCTOR " << i + 1 << endl;
            instructores[i]->mostrar();
            cout << endl;
        }
    }

    Instructor* get(int i) { return instructores[i]; }
    int getIndice() { return indice; }
};
