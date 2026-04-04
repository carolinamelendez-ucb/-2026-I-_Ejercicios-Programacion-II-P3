#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "sistema.h"

class VectorSistemas {

private:

    Sistema** sistemas;
    int cantidad;
    int indice;

public:

    VectorSistemas(int cantidad) {
        indice = 0;
        this->cantidad=cantidad;
        sistemas=new Sistema*[cantidad];
    }

    bool ciDuplicado(string ci) {

        for (int i = 0;i < cantidad;i++)
            if (sistemas[i]->getCI() == ci)
                return true;

        return false;
    }

    void agregar(Sistema* operador) {
    for(int i=0;i<cantidad;i++){
        if (!ciDuplicado(operador->getCI()))
            sistemas[i] = operador;
            indice ++;
    }
    }

    float costoTotal() {

        float total = 0;

        for (int i = 0;i < cantidad;i++)
            total += sistemas[i]->calcularCosto();

        return total;
    }

    void mostrar() {

        int indiceMenor = 0;
        float costoMinimo = sistemas[0]->calcularCosto();

        for (int i = 0; i < cantidad; i++) {

            float valorActual = sistemas[i]->calcularCosto();

            cout << "Operador: " << sistemas[i]->getNombre() <<endl;
            cout << "Placa: " << sistemas[i]->getPlaca() <<endl;
            cout << "Costo: " << valorActual <<endl;

            if (valorActual < costoMinimo) {
                costoMinimo = valorActual;
                indiceMenor = i;
            }
        }

        float total = costoTotal();

        cout << "Costo Total: " << total << endl;

        cout << "Menor costo: ";
        cout << "Operador: " << sistemas[indiceMenor]->getNombre() <<endl;
        cout << "Placa: " << sistemas[indiceMenor]->getPlaca() <<endl;
        cout << "Costo: " << costoMinimo << endl;
    }

    ~VectorSistemas() {

        for (int i = 0;i < cantidad;i++)
            delete sistemas[i];
    }
};