#pragma once
#include "VectorOperadores.h"
#include "VectorTransportes.h"

class Sistema {
private:
    VectorOperadores* operadores;
    VectorTransportes* transportes;

public:
    Sistema() {
        operadores = new VectorOperadores(10);
        transportes = new VectorTransportes(10);
    }

    void registrarTransporte(Transporte* transporte) {
        if (!transportes->agregar(transporte))
            cout << "Placa duplicada";
    }

    void registrarOperador(Operador* operador) {
        if (!operadores->agregar(operador))
            cout << "CI duplicado";
    }

    void asignar(string ci, string placa, float distancia) {
        Operador* op = operadores->buscar(ci);
        Transporte* t = transportes->buscar(placa);

        if (op != nullptr && t != nullptr) {
            op->asignarTransporte(t, distancia);
        }
    }

    void mostrarTodo() {
        operadores->mostrar();
    }

    void mostrarTotal() {
        cout << "Costo total: " << operadores->costoTotal() << endl;
    }

    void mostrarMenor() {
        Operador* op = operadores->menorCosto();

        if (op != nullptr) {
            cout << "Menor costo:";
            op->mostrar();
        }
    }
};