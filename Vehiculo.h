#pragma once
#include "Espacio.h"

class Vehiculo {
private:
    string  placa;
    string  marca;
    string  modelo;
    string  tipoVehiculo;
    Espacio* espacioAsignado;

public:
    Vehiculo(const string& placa, const string& marca,
        const string& modelo, const string& tipoVehiculo)
        : placa(placa), marca(marca), modelo(modelo),
        tipoVehiculo(tipoVehiculo), espacioAsignado(nullptr) {
    }

    ~Vehiculo() {
    }

    string getPlaca() { return placa; }
    string getMarca() { return marca; }

    static bool compararPlaca(Vehiculo* vehiculoAcomparar, string placa) {
        return vehiculoAcomparar->placa == placa;
    }

    static bool compararMarca(Vehiculo* a, Vehiculo* b) {
        return a->marca < b->marca;
    }

    void asignarEspacio(Espacio* espacio) {
        this->espacioAsignado = espacio;
        this->espacioAsignado->cambiarEstadoAOcupado();
    }

    bool tieneEspacioAsignado() {
        return this->espacioAsignado != nullptr;
    }

    void mostrar() {
        cout << "  Vehiculo [" << placa << "] "
            << marca << " " << modelo
            << " | Tipo: " << tipoVehiculo;
        if (espacioAsignado != nullptr) {
            cout << " | Espacio asignado: " << espacioAsignado->getCodigo();
        }
        else {
            cout << " | Sin espacio asignado";
        }
        cout << endl;
    }
};