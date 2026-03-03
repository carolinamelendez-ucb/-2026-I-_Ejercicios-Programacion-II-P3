#pragma once
#include "Pasajero.h"

class PasajerosVector {
private:
    Pasajero** pasajeros;
    int tamanio;
    int indice;

public:
    PasajerosVector(int tamanio) {
        this->tamanio = tamanio;
        this->indice = 0;
        pasajeros = new Pasajero * [tamanio];
    }

    void agregar(Pasajero* nuevo) {
        pasajeros[indice] = nuevo;
        indice++;
    }

 
    void mostrarSinAsiento() {
        for (int i = 0; i < indice; i++) {
            if (pasajeros[i]->getNumeroAsiento() == 0) {
                pasajeros[i]->mostrar();
            }
        }
    }


    void mostrarAsientoImpar() {
        for (int i = 0; i < indice; i++) {
            int asiento = pasajeros[i]->getNumeroAsiento();
            if (asiento != 0 && asiento % 2 != 0) {
                pasajeros[i]->mostrar();
            }
        }
    }


    void buscarPorNombre(string nombre) {
        for (int i = 0; i < indice; i++) {
            if (pasajeros[i]->getNombre() == nombre) {
                pasajeros[i]->mostrar();
                return;
            }
        }
        cout << "No encontrado." << endl;
    }


    void buscarPorCi(int ci) {
        for (int i = 0; i < indice; i++) {
            if (pasajeros[i]->getCi() == ci) {
                pasajeros[i]->mostrar();
                return;
            }
        }
        cout << "No encontrado." << endl;
    }
};