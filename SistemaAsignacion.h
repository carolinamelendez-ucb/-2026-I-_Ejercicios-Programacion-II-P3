#pragma once
#include "Vuelo.h"
#include "VectorVuelos.h"
#include "VueloNoExisteException.h"
#include "PasajeroNoExisteException.h"
#include "AsientoNoExisteException.h"
#include "AsientoOcupadoException.h"

class SistemaAsignacion {
private:
    VectorVuelos* vuelos;
public:
    SistemaAsignacion(int t) {
        vuelos = new VectorVuelos(t);
    }

    void registrarVuelo(Vuelo* v) {
        vuelos->agregar(v);
    }

    void asignar(int ci, int codVuelo, string codAsiento) {
        Vuelo* v = vuelos->buscarCodigo(codVuelo);
        if (v == nullptr) throw VueloNoExisteException();

        Pasajero* p = v->buscarPasajero(ci);
        if (p == nullptr) throw PasajeroNoExisteException();

        Asiento* a = v->buscarAsiento(codAsiento);
        if (a == nullptr) throw AsientoNoExisteException();

        if (a->getEstado()) throw AsientoOcupadoException();

        a->ocupar();
        p->asignarAsiento(a);
    }

    void mostrarVuelo(int cod) {
        Vuelo* v = vuelos->buscarCodigo(cod);
        if (v == nullptr) throw VueloNoExisteException();

        v->mostrarPasajeros();
        v->estadoAsientos();
    }
};
