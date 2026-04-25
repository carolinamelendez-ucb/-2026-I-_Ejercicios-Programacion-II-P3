#pragma once
#include <iostream>
#include <string>
#include "VectorVuelos.h"
using namespace std;

class SistemaAsignacion {
private:
    VectorVuelos* vuelos;

public:
    SistemaAsignacion() {
        vuelos = new VectorVuelos(10);
    }

    void registrarVuelo(string cod, int f, int c) {
        vuelos->agregar(new Vuelo(cod, f, c));
    }

    void registrarAsiento(string codVuelo, string codAsiento) {
        Vuelo* v = vuelos->buscar(codVuelo);
        if (!v) throw MiExcepcion("Vuelo no existe");

        v->agregarAsiento(codAsiento);
    }

    void registrarPasajero(string codVuelo, Pasajero* p) {
        Vuelo* v = vuelos->buscar(codVuelo);
        if (!v) throw MiExcepcion("Vuelo no existe");

        v->agregarPasajero(p);
    }

    void asignar(string codVuelo, string ci, string codAsiento) {
        Vuelo* v = vuelos->buscar(codVuelo);
        if (!v) throw MiExcepcion("Vuelo no existe");

        v->asignar(ci, codAsiento);
    }
};