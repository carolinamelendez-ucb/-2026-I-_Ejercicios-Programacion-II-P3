#pragma once
#include "Empleado.h"

class VectorEmpleados {
private:
    Empleado** lista;
    int indice, tamanio;

public:
    VectorEmpleados(int tamanio) {
        tamanio = tamanio;
        indice = 0;
        lista = new Empleado * [tamanio];
    }

    bool agregar(Empleado* nuevoEmpleado) {
        for (int i = 0; i < indice; i++)
            if (lista[i]->getCi() == nuevoEmpleado->getCi())
                return false;

        lista[indice++] = nuevoEmpleado;
        return true;
    }

    float totalSalarios() {
        float total = 0;
        for (int i = 0; i < indice; i++)
            total += lista[i]->calcularSalario();
        return total;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++)
            lista[i]->mostrarInformacion();
    }
};