#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class VectorEmpleados {
private:
    Empleado** empleados;
    int tamanio;
    int cantidad;

public:
    VectorEmpleados(int tamanioMax) {
        this->empleados = new Empleado * [tamanioMax];
        this->tamanio = tamanioMax;
        this->cantidad = 0;
    }

    void agregar(Empleado* nuevoEmpleado) {
        if (cantidad < tamanio) {
            empleados[cantidad] = nuevoEmpleado;
            cantidad++;
        }
        else {
            cout << "El vector de empleados esta lleno, no se puede agregar" << endl;
        }
    }

    Empleado* buscarPorCi(int ciBuscado) {
        for (int i = 0; i < cantidad; i++) {
            if (empleados[i]->getCi() == ciBuscado) {
                return empleados[i];
            }
        }
        return nullptr;
    }

    void mostrarTodos() {
        for (int i = 0; i < cantidad; i++) {
            empleados[i]->mostrarInformacion();
        }
    }

    float calcularTotalSalarios() {
        float total = 0;
        for (int i = 0; i < cantidad; i++) {
            total += empleados[i]->calcularSalario();
        }
        return total;
    }

    int getCantidad() {
        return cantidad;
    }

    void liberarMemoria() {
        for (int i = 0; i < cantidad; i++) {
            delete empleados[i];
        }
        delete[] empleados;
    }
};

