#pragma once
#include "VectorPasajeros.h"
#include "VectorVuelos.h"
#include <exception>

class SistemaAsignacion {
private:
	string nombreAerolinea;
	VectorPasajeros* listaPasajeros;
	VectorVuelos* listaVuelos;
public:
    SistemaAsignacion(string nombreAerolinea, int maxPasajeros, int maxVuelos) {
        this->nombreAerolinea = nombreAerolinea;
        this->listaPasajeros = new VectorPasajeros(maxPasajeros);
        this->listaVuelos = new VectorVuelos(maxVuelos);
    }
    void registrarVuelo(string cod, int hp, int hle, int hla, int f, int c) {
        listaVuelos->agregarVuelos(new Vuelo(cod, hp, hle, hla, f, c, f * c, 100));
    }
    void registrarAsiento(string codVuelo, string codAsiento) {
        Vuelo* v = listaVuelos->buscar(codVuelo);
        if (v != nullptr)
            v->getAsientos()->agregarAsientos(new Asiento(codAsiento));
    }
    void registrarPasajero (string codVuelo, int ci, string nombre, string apellido) {
        Vuelo* v = listaVuelos->buscar(codVuelo);
        if (v != nullptr)
            v->getPasajeros()->agregarPasajeros(new Pasajero(ci, nombre, apellido));
    }
    void asignarAsiento(string codVuelo, int ci, string codAsiento) {
        Vuelo* v = listaVuelos->buscar(codVuelo);
        if (v == nullptr) {
            throw exception();
        }
        Pasajero* p = v->getPasajeros()->buscar(ci);
        if (p == nullptr) {
            throw exception();
        }
        Asiento* a = v->getAsientos()->buscar(codAsiento);
        if (a == nullptr) {
            throw exception();
        }
        if (!a->getDiponibilidad()) {
            throw exception();
        }
        p->asignarAsiento(a);
        a->ocupado();
    }
    void mostrarPasajeros(string codVuelo) {
        Vuelo* v = listaVuelos->buscar(codVuelo);
        if (v != nullptr)
            v->getPasajeros()->mostrar();
    }
    void estadoAsientos(string codVuelo) {
        Vuelo* v = listaVuelos->buscar(codVuelo);
        if (v != nullptr)
            v->getAsientos()->mostrarEstado();
    }
};