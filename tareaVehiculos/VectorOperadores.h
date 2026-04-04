#pragma once
#include <iostream>
#include <string>
#include "Operador.h"

using namespace std;

class VectorOperadores {
public:
    Operador** operadores;
    int tamanio;
    int cantidad;

public:
    VectorOperadores(int tamanioMax) {
        this->operadores = new Operador * [tamanioMax];
        this->tamanio = tamanioMax;
        this->cantidad = 0;
    }

    bool existeCi(int ci) {
        for (int i = 0; i < cantidad; i++) {
            if (operadores[i]->ci == ci) {
                return true;
            }
        }
        return false;
    }

    void agregar(Operador* nuevoOperador) {
        if (existeCi(nuevoOperador->ci)) {
            cout << "Error: Ya existe un operador con CI " << nuevoOperador->ci << endl;
            delete nuevoOperador;
            return;
        }

        if (cantidad < tamanio) {
            operadores[cantidad] = nuevoOperador;
            cantidad++;
            cout << "Operador agregado exitosamente" << endl;
        }
        else {
            cout << "Error: El vector de operadores esta lleno" << endl;
            delete nuevoOperador;
        }
    }

    Operador* buscarPorCi(int ci) {
        for (int i = 0; i < cantidad; i++) {
            if (operadores[i]->ci == ci) {
                return operadores[i];
            }
        }
        return nullptr;
    }

    void mostrarTodos() {
        for (int i = 0; i < cantidad; i++) {
            operadores[i]->mostrarInformacion();
            cout << endl;
        }
    }

    float calcularCostoTotalGeneral() {
        float total = 0;
        for (int i = 0; i < cantidad; i++) {
            total += operadores[i]->calcularCostoGenerado();
        }
        return total;
    }

    void mostrarOperadorMenorCosto() {
        if (cantidad == 0) {
            cout << "No hay operadores registrados" << endl;
            return;
        }

        int indiceMenor = 0;
        float menorCosto = operadores[0]->calcularCostoGenerado();

        for (int i = 1; i < cantidad; i++) {
            float costoActual = operadores[i]->calcularCostoGenerado();
            if (costoActual < menorCosto) {
                menorCosto = costoActual;
                indiceMenor = i;
            }
        }

        cout << "\n=== OPERADOR QUE GENERO MENOR COSTO ===" << endl;
        operadores[indiceMenor]->mostrarInformacion();
    }

    ~VectorOperadores() {
        for (int i = 0; i < cantidad; i++) {
            delete operadores[i];
        }
        delete[] operadores;
    }
};

