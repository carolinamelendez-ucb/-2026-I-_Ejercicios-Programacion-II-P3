#pragma once
#include "Operador.h"

class VectorOperadores {

private:

    Operador* operadores[20];
    int cantidad;

public:

    VectorOperadores() {
        cantidad = 0;
    }

    bool ciDuplicado(string ci) {

        for (int i = 0;i < cantidad;i++)
            if (operadores[i]->getCI() == ci)
                return true;

        return false;
    }

    void agregar(Operador* operador) {

        if (!ciDuplicado(operador->getCI()))
            operadores[cantidad++] = operador;
    }

    float costoTotal() {

        float total = 0;

        for (int i = 0;i < cantidad;i++)
            total += operadores[i]->calcularCosto();

        return total;
    }

    void mostrar() {

        float menor = operadores[0]->calcularCosto();
        int pos = 0;

        for (int i = 0;i < cantidad;i++) {

            float costo = operadores[i]->calcularCosto();

            cout << "Operador: " << operadores[i]->getNombre() << endl;
            cout << "Placa: " << operadores[i]->getPlaca() << endl;
            cout << "Costo: " << costo << endl;
            cout << endl;
            cout << endl;

            if (costo < menor) {
                menor = costo;
                pos = i;
            }
        }

        cout << "Costo Total: " << costoTotal() << endl;
        cout << endl;
        cout << "Menor costo:" << endl;
        cout << "Operador: " << operadores[pos]->getNombre() << endl;
        cout << "Placa: " << operadores[pos]->getPlaca() << endl;
        cout << "Costo: " << menor << endl;
    }

    ~VectorOperadores() {

        for (int i = 0;i < cantidad;i++)
            delete operadores[i];
    }
};
