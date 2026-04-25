#pragma once
#include "VectorPasajeros.h"
#include "VectorAsientos.h"
#include "PasajeroDuplicadoException.h"

class Vuelo {
private:
    int codigo;
    string partida;
    string llegadaEsp;
    string llegadaReal;
    VectorPasajeros* pasajeros;
    VectorAsientos* asientos;
public:
    Vuelo(int c, string p, string le, string lr, int capacidad) {
        codigo = c;
        partida = p;
        llegadaEsp = le;
        llegadaReal = lr;
        pasajeros = new VectorPasajeros(capacidad);
        asientos = new VectorAsientos(capacidad);
    }

    int getCodigo() { return codigo; }

    void agregarAsiento(Asiento* a) {
        asientos->agregar(a);
    }

    void agregarPasajero(Pasajero* p) {
        if (pasajeros->buscar(p->getCi()) != nullptr) {
            throw PasajeroDuplicadoException();
        }
        pasajeros->agregar(p);
    }

    Pasajero* buscarPasajero(int ci) {
        return pasajeros->buscar(ci);
    }

    Asiento* buscarAsiento(string cod) {
        return asientos->buscar(cod);
    }

    void mostrarPasajeros() {
        pasajeros->mostrar();
    }

    void estadoAsientos() {
        cout << "Disponibles: " << asientos->contarDisponibles() << endl;
        cout << "Ocupados: " << asientos->contarOcupados() << endl;
    }
};
