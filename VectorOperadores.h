#pragma once
#include "Operador.h"

class VectorOperadores {
private:
    Operador** operadores;
    int indice;
    int tamanio;

public:
    VectorOperadores(int tamanio) {
        tamanio = tamanio;
        indice = 0;
        operadores = new Operador * [tamanio];
    }

    bool agregar(Operador* operador) {
        for (int i = 0; i < indice; i++) {
            if (operadores[i]->getCi() == operador->getCi())
                return false;
        }

        operadores[indice++] = operador;
        return true;
    }

    Operador* buscar(string ci) {
        for (int i = 0; i < indice; i++) {
            if (operadores[i]->getCi() == ci)
                return operadores[i];
        }
        return nullptr;
    }

    float costoTotal() {
        float total = 0;
        for (int i = 0; i < indice; i++) {
            total += operadores[i]->calcularCosto();
        }
        return total;
    }

    Operador* menorCosto() {
        if (indice == 0) return nullptr;

        Operador* menor = operadores[0];

        for (int i = 1; i < indice; i++) {
            if (operadores[i]->calcularCosto() < menor->calcularCosto()) {
                menor = operadores[i];
            }
        }

        return menor;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            operadores[i]->mostrar();
        }
    }
};