#pragma once
#include "VectorPagos.h"
#include <string>

class Cliente {

private:
    string nombre;
    VectorPagos* pagos;

public:

    Cliente(const string& nombre) : nombre(nombre) {
        pagos = new VectorPagos(20);
    }

    ~Cliente() {
        delete pagos;
    }

    string getNombre() { return nombre; }

    void agregarPago(Pago* pagoNuevo) {
        pagos->agregar(pagoNuevo);
    }

    float procesarPagos() {
        return pagos->procesarTodo();
    }

    void mostrar() {
        cout << "Cliente: " << nombre << endl;
        cout << "----------------------------------" << endl;
        pagos->mostrar();
    }
};
