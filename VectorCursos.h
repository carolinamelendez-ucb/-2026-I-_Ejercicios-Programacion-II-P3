#pragma once
#include <iostream>
#include "Curso.h"

using namespace std;

class CursosVector {

private:
    Curso** cursos;
    int indice;
    int tamanio;

public:

    CursosVector(int tamanio)
        : tamanio(tamanio), indice(0)
    {
        cursos = new Curso * [tamanio];
    }

    ~CursosVector() {
        for (int i = 0; i < indice; i++) {
            delete cursos[i];
        }

        delete[] cursos;
    }

    void agregar(Curso* cursoNuevo) {
        if (indice < tamanio) {
            cursos[indice] = cursoNuevo;
            indice++;
        }
        else {
            cout << "No se pueden agregar mas cursos" << endl;
        }
    }

    Curso* buscar(int id) {
        for (int i = 0; i < indice; i++) {
            if (cursos[i]->getId() == id)
                return cursos[i];
        }
        return nullptr;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            cout << "CURSO " << i + 1 << endl;
            cursos[i]->mostrar();
            cout << endl;
        }
    }
};