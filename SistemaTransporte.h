#pragma once
#include "VectorTransportes.h"
#include "VectorOperadores.h"

class SistemaTransporte {

private:
    VectorTransportes* transportes;
    VectorOperadores* operadores;

public:

    SistemaTransporte(int tamanioTranportes, int tamanioOperadores) {
        transportes = new VectorTransportes(tamanioTranportes);
        operadores = new VectorOperadores(tamanioOperadores);
    }

    ~SistemaTransporte() {
        delete transportes;
        delete operadores;
    }

    void registrarTransporte(Transporte* transporteNuevo) {
        transportes->agregar(transporteNuevo);
    }

    void registrarOperador(const string& nombre, const string& ci) {
        operadores->agregar(new Operador(nombre, ci));
    }

    void asignar(string ci, string placa, float distancia) {
        Operador* operador = operadores->buscar(ci);
        Transporte* transporte = transportes->buscar(placa);

        if (operador != nullptr && transporte != nullptr) {
            operador->asignarTransporte(transporte, distancia);
        }
    }

    float costoTotal() {
        float total = 0;

        for (int i = 0; i < operadores->size(); i++) {
            total += operadores->get(i)->calcularCosto();
        }

        return total;
    }

    void menorCosto() {
        if (operadores->size() == 0) return;

        Operador* menor = operadores->get(0);

        for (int i = 1; i < operadores->size(); i++) {
            if (operadores->get(i)->calcularCosto() < menor->calcularCosto()) {
                menor = operadores->get(i);
            }
        }

        cout << "Operador con menor costo:" << endl;
        menor->mostrar();
    }
};
