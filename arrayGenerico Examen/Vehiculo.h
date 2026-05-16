#pragma once
#include <iostream>
#include <string>
#include "Espacio.h"

using namespace std;

class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;
    string tipoVehiculo;
    Espacio* espacioAsignado;
    static int totalVehiculosCreados;

public:
    Vehiculo(const string& placa, const string& marca, const string& modelo)
        : placa(placa), marca(marca), modelo(modelo) {
        espacioAsignado = nullptr;
        tipoVehiculo = "";
        totalVehiculosCreados++;
    }

    void asignarTipo(const string& tipo) {
        tipoVehiculo = tipo;
    }

    void asignarEspacio(Espacio* espacio) {
        espacioAsignado = espacio;
    }

    void mostrarInformacion() {
        cout << "Placa: " << placa << " Marca: " << marca
            << " Modelo: " << modelo << " Tipo: " << tipoVehiculo << endl;
        if (espacioAsignado != nullptr) {
            cout << "Espacio asignado: ";
            espacioAsignado->mostrarInformacion();
        }
        else {
            cout << "Sin espacio asignado" << endl;
        }
    }

    static void mostrarTotalVehiculosCreados() {
        cout << "Total vehiculos creados: " << totalVehiculosCreados << endl;
    }

    ~Vehiculo() {
        cout << "Vehiculo " << placa << " destruido" << endl;
        totalVehiculosCreados--;
    }
};

int Vehiculo::totalVehiculosCreados = 0;