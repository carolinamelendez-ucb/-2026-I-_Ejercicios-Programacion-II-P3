#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"

using namespace std;

class Operador {
public:
    int ci;
    string nombre;
    Transporte* transporteAsignado;
    float distanciaRecorrida;

public:
    Operador(int ci, const string& nombre)
        : ci(ci), nombre(nombre), transporteAsignado(nullptr), distanciaRecorrida(0) {
    }

    void asignarTransporte(Transporte* transporte, float distancia) {
        transporteAsignado = transporte;
        distanciaRecorrida = distancia;
    }

    float calcularCostoGenerado() {
        if (transporteAsignado == nullptr) {
            return 0;
        }
        return transporteAsignado->calcularCosto(distanciaRecorrida);
    }

    void mostrarInformacion() {
        cout << "Operador - CI: " << ci << ", Nombre: " << nombre << endl;
        if (transporteAsignado != nullptr) {
            cout << "  Transporte asignado: ";
            transporteAsignado->mostrarInformacion();
            cout << "  Distancia recorrida: " << distanciaRecorrida << " km" << endl;
            cout << "  Costo generado: " << calcularCostoGenerado() << endl;
        }
        else {
            cout << "  Sin transporte asignado" << endl;
        }
    }

    ~Operador() {
    }
};