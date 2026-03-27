#pragma once
#include <iostream>
#include <string>
#include "Organizador.h"
using namespace std;

class OrganizadorVector {
private:
    Organizador** organizadores;
    int tamanio;
    int indice;
public:
    OrganizadorVector(int tamanio) {
        this->organizadores = new Organizador * [tamanio];
        this->tamanio = tamanio;
        this->indice = 0;
    }
    void agregarOrganizador(Organizador* newOrganizador) {
        organizadores[indice] = newOrganizador;
        indice++;
    }
    void ordenar() {
        for (int i = 0; i < indice - 1; i++) {
            for (int j = i + 1; j < indice; j++) {
                if (organizadores[i]->getDisponible() < organizadores[j]->getDisponible() || (organizadores[i]->getDisponible() == organizadores[j]->getDisponible() &&
                    organizadores[i]->getRank() < organizadores[j]->getRank())) {
                    Organizador* aux = organizadores[i];
                    organizadores[i] = organizadores[j];
                    organizadores[j] = aux;
                }
            }
        }
    }
    void mostrar() {
        ordenar();
        for (int i = 0; i < indice; i++) {
            organizadores[i]->mostrar();
        }
    }
    Organizador* mejorDisponible() {
        int pos = -1;
        for (int i = 0; i < indice; i++) {
            if (organizadores[i]->getDisponible()) {
                if (pos == -1 ||
                    organizadores[i]->getRank() >
                    organizadores[pos]->getRank()) {
                    pos = i;
                }
            }
        }
        if (pos != -1)
            return organizadores[pos];
    }
};
