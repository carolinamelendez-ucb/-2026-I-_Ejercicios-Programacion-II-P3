#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"

using namespace std;

class VectorTransportes {
public:
    Transporte** transportes;
    int tamanio;
    int cantidad;

public:
    VectorTransportes(int tamanioMax) {
        this->transportes = new Transporte * [tamanioMax];
        this->tamanio = tamanioMax;
        this->cantidad = 0;
    }

    bool existePlaca(const string& placa) {
        for (int i = 0; i < cantidad; i++) {
            if (transportes[i]->placa == placa) {
                return true;
            }
        }
        return false;
    }

    void agregar(Transporte* nuevoTransporte) {
        if (existePlaca(nuevoTransporte->placa)) {
            cout << "Error: Ya existe un transporte con placa " << nuevoTransporte->placa << endl;
            delete nuevoTransporte;
            return;
        }

        if (cantidad < tamanio) {
            transportes[cantidad] = nuevoTransporte;
            cantidad++;
            cout << "Transporte agregado exitosamente" << endl;
        }
        else {
            cout << "Error: El vector de transportes esta lleno" << endl;
            delete nuevoTransporte;
        }
    }

    Transporte* buscarPorPlaca(const string& placa) {
        for (int i = 0; i < cantidad; i++) {
            if (transportes[i]->placa == placa) {
                return transportes[i];
            }
        }
        return nullptr;
    }

    void mostrarTodos() {
        for (int i = 0; i < cantidad; i++) {
            transportes[i]->mostrarInformacion();
        }
    }

    ~VectorTransportes() {
        for (int i = 0; i < cantidad; i++) {
            delete transportes[i];
        }
        delete[] transportes;
    }
};