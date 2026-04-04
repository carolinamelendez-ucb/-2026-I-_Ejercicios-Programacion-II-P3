#pragma once
#include "Pago.h"

class VectorPagos {

private:
    Pago** pagos;
    int indice;
    int tamanio;

public:

    VectorPagos(int tamanio) : tamanio(tamanio), indice(0) {
        pagos = new Pago * [tamanio];
    }

    ~VectorPagos() {
        for (int i = 0; i < indice; i++) delete pagos[i];
        delete[] pagos;
    }

    void agregar(Pago* pagoNuevo) {
        if (indice < tamanio) {
            pagos[indice++] = pagoNuevo;
        }
    }

    float procesarTodo() {
        float total = 0;
        for (int i = 0; i < indice; i++) {
            total += pagos[i]->procesar();
        }
        return total;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            cout << "Pago " << i + 1 << ":" << endl;
            pagos[i]->mostrar();
            cout << endl;
        }
    }
};
