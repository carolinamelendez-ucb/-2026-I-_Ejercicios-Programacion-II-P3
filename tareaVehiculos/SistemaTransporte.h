#pragma once
#include <iostream>
#include <string>
#include "VectorTransportes.h"
#include "VectorOperadores.h"

using namespace std;

class SistemaTransporte {
public:
    VectorTransportes* listaTransportes;
    VectorOperadores* listaOperadores;

public:
    SistemaTransporte(int tamanioTransportes, int tamanioOperadores) {
        listaTransportes = new VectorTransportes(tamanioTransportes);
        listaOperadores = new VectorOperadores(tamanioOperadores);
    }

    void registrarTransporte(Transporte* nuevoTransporte) {
        listaTransportes->agregar(nuevoTransporte);
    }

    void registrarOperador(Operador* nuevoOperador) {
        listaOperadores->agregar(nuevoOperador);
    }

    void asociarOperadorTransporte(int ciOperador, const string& placaTransporte, float distancia) {
        Operador* operador = listaOperadores->buscarPorCi(ciOperador);
        Transporte* transporte = listaTransportes->buscarPorPlaca(placaTransporte);

        if (operador == nullptr) {
            cout << "Error: No se encontro operador con CI " << ciOperador << endl;
            return;
        }

        if (transporte == nullptr) {
            cout << "Error: No se encontro transporte con placa " << placaTransporte << endl;
            return;
        }

        operador->asignarTransporte(transporte, distancia);
        cout << "Asociacion exitosa: Operador " << operador->nombre
            << " -> Transporte " << transporte->placa
            << " con distancia " << distancia << " km" << endl;
    }

    void mostrarCostoPorOperador(int ciOperador) {
        Operador* operador = listaOperadores->buscarPorCi(ciOperador);
        if (operador == nullptr) {
            cout << "Error: No se encontro operador con CI " << ciOperador << endl;
            return;
        }

        cout << "Costo generado por " << operador->nombre << " (CI: " << ciOperador
            << "): " << operador->calcularCostoGenerado() << endl;
    }

    void mostrarCostoTotalGeneral() {
        float total = listaOperadores->calcularCostoTotalGeneral();
        cout << "\n=== COSTO TOTAL GENERAL DEL SISTEMA ===" << endl;
        cout << "Costo total: " << total << endl;
    }

    void mostrarOperadorMenorCosto() {
        listaOperadores->mostrarOperadorMenorCosto();
    }

    void mostrarTodosLosTransportes() {
        cout << "\n=== LISTA DE TRANSPORTES ===" << endl;
        if (listaTransportes->cantidad == 0) {
            cout << "No hay transportes registrados" << endl;
        }
        else {
            listaTransportes->mostrarTodos();
        }
    }

    void mostrarTodosLosOperadores() {
        cout << "\n=== LISTA DE OPERADORES ===" << endl;
        if (listaOperadores->cantidad == 0) {
            cout << "No hay operadores registrados" << endl;
        }
        else {
            listaOperadores->mostrarTodos();
        }
    }

    ~SistemaTransporte() {
        delete listaTransportes;
        delete listaOperadores;
    }
};