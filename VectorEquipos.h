#pragma once
#include <iostream>
#include <string>
#include "Equipo.h"
using namespace std;

class VectorEquipos {
private:
    Equipo** equipos;
    int cantidad;
    int capacidad;

    void expandir() {
        int nuevaCapacidad = this->capacidad * 2;
        Equipo** nuevosEquipos = new Equipo * [nuevaCapacidad];

        for (int i = 0; i < this->cantidad; i++) {
            nuevosEquipos[i] = this->equipos[i];
        }

        delete[] this->equipos;
        this->equipos = nuevosEquipos;
        this->capacidad = nuevaCapacidad;
    }

public:
    VectorEquipos() {
        this->capacidad = 10;
        this->cantidad = 0;
        this->equipos = new Equipo * [this->capacidad];
    }

    ~VectorEquipos() {
        for (int i = 0; i < this->cantidad; i++) {
            delete this->equipos[i];
        }
        delete[] this->equipos;
        cout << "Destructor de VectorEquipos" << endl;
    }

    void agregarEquipo(Equipo* equipo) {
        if (this->cantidad >= this->capacidad) {
            expandir();
        }
        this->equipos[this->cantidad] = equipo;
        this->cantidad++;
    }

    int getCantidad() {
        return this->cantidad;
    }

    Equipo* getEquipo(int indice) {
        if (indice >= 0 && indice < this->cantidad) {
            return this->equipos[indice];
        }
        return NULL;
    }

    void mostrarTodos() {
        cout << "\n=== LISTA DE EQUIPOS ===" << endl;
        for (int i = 0; i < this->cantidad; i++) {
            cout << i + 1 << ". ";
            this->equipos[i]->mostrar();
            cout << endl;
        }
    }

    bool socioEnAlgunEquipo(Socio* socio) {
        for (int i = 0; i < this->cantidad; i++) {
            if (this->equipos[i]->socioEnEquipo(socio)) {
                return true;
            }
        }
        return false;
    }

    void buscarEquiposDeSocio(Socio* socio) {
        cout << "\nEquipos en los que participa " << socio->getNombre() << ":" << endl;
        bool encontrado = false;
        for (int i = 0; i < this->cantidad; i++) {
            if (this->equipos[i]->socioEnEquipo(socio)) {
                this->equipos[i]->mostrar();
                cout << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "No participa en ningun equipo" << endl;
        }
    }
};