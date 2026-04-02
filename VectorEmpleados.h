#pragma once
#include "Empleado.h"

class VectorEmpleados {

private:
    Empleado** empleados;
    int indice;
    int tamanio;

public:

    VectorEmpleados(int tamanio) : tamanio(tamanio), indice(0) {
        empleados = new Empleado * [tamanio];
    }

    ~VectorEmpleados() {
        for (int i = 0; i < indice; i++) delete empleados[i];
        delete[] empleados;
    }

    Empleado* buscar(string ci) {
        for (int i = 0; i < indice; i++) {
            if (empleados[i]->getCi() == ci) return empleados[i];
        }
        return nullptr;
    }

    void agregar(Empleado* nuevoEmpleado) {
        if (buscar(nuevoEmpleado->getCi()) != nullptr) {
            cout << "CI duplicado" << endl;
            delete nuevoEmpleado;
            return;
        }

        if (indice < tamanio) {
            empleados[indice++] = nuevoEmpleado;
        }
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            cout << "EMPLEADO " << i + 1 << endl;
            empleados[i]->mostrar();
            cout << "Salario: " << empleados[i]->calcularSalario() << endl;
            cout << endl;
        }
    }

    float totalSalarios() {
        float total = 0;
        for (int i = 0; i < indice; i++) {
            total += empleados[i]->calcularSalario();
        }
        return total;
    }
};
