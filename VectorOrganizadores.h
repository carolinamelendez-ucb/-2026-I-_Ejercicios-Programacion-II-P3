#pragma once
#include <iostream>
#include "Organizador.h"

using namespace std;

class OrganizadoresVector {

private:
    Organizador** organizadores;
    int indice;
    int tamanio;

public:
    OrganizadoresVector(int tamanio)
        : tamanio(tamanio), indice(0)
    {
        organizadores = new Organizador * [tamanio];
    }

    ~OrganizadoresVector() {
        for (int i = 0; i < indice; i++) {
            delete organizadores[i];
        }
        delete[] organizadores;
    }

    void agregar(Organizador* organizador) {
        organizadores[indice] = organizador;
        indice++;
    }

    Organizador* buscarDisponibleMayorRank() {
        Organizador* mejor = nullptr;
        for (int i = 0; i < indice; i++) {
            if (organizadores[i]->estaDisponible()) {
                if (mejor == nullptr || organizadores[i]->getRank() > mejor->getRank()) {
                    mejor = organizadores[i];
                }
            }
        }
        return mejor;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            cout << "ORGANIZADOR " << i + 1 << endl;
            organizadores[i]->mostrar();
            cout << endl;
        }
    }
};
