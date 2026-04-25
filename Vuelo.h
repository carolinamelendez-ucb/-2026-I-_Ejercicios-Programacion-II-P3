#pragma once
#include <iostream>
#include <string>
#include "VectorPasajeros.h"
#include "VectorAsiento.h"

class Vuelo {
private:
    string codigo;
    int filas, columnas;

    VectorAsientos* asientos;
    VectorPasajeros* pasajeros;

public:
    Vuelo(string cod, int f, int c) {
        codigo = cod;
        filas = f;
        columnas = c;

        int cap = f * c;
        asientos = new VectorAsientos(cap);
        pasajeros = new VectorPasajeros(cap);
    }

    string getCodigo() { return codigo; }

    void agregarAsiento(string cod) {
        asientos->agregar(new Asiento(cod));
    }

    void agregarPasajero(Pasajero* p) {
        pasajeros->agregar(p);
    }

    void asignar(string ci, string codAsiento) {
        Pasajero* p = pasajeros->buscar(ci);
        if (!p) throw MiExcepcion("Pasajero no existe");

        Asiento* a = asientos->buscar(codAsiento);
        if (!a) throw MiExcepcion("Asiento no existe");

        if (!a->estaDisponible())
            throw MiExcepcion("Asiento ocupado");

        a->ocupar();
        p->asignarAsiento(a);
    }

    void mostrar() {
        pasajeros->mostrar();
        cout << "Disponibles: " << asientos->disponibles() << endl;
        cout << "Ocupados: " << asientos->ocupados() << endl;
    }
};