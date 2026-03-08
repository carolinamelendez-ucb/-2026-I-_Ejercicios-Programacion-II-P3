#pragma once
#include <iostream>
#include <string>
#include "Socio.h"
using namespace std;

class VectorSocios {
private:
    Socio** socios;
    int cantidad;
    int capacidad;

    void expandir() {
        int nuevaCapacidad = this->capacidad * 2;
        Socio** nuevosSocios = new Socio * [nuevaCapacidad];

        for (int i = 0; i < this->cantidad; i++) {
            nuevosSocios[i] = this->socios[i];
        }

        delete[] this->socios;
        this->socios = nuevosSocios;
        this->capacidad = nuevaCapacidad;
    }

public:
    VectorSocios() {
        this->capacidad = 10;
        this->cantidad = 0;
        this->socios = new Socio * [this->capacidad];
    }

    ~VectorSocios() {
        for (int i = 0; i < this->cantidad; i++) {
            delete this->socios[i];
        }
        delete[] this->socios;
        cout << "Destructor de VectorSocios" << endl;
    }

    void agregarSocio(Socio* socio) {
        if (this->cantidad >= this->capacidad) {
            expandir();
        }
        this->socios[this->cantidad] = socio;
        this->cantidad++;
    }

    int getCantidad() {
        return this->cantidad;
    }

    Socio* getSocio(int indice) {
        if (indice >= 0 && indice < this->cantidad) {
            return this->socios[indice];
        }
        return NULL;
    }

    void ordenarAlfabeticamente() {
        for (int i = 0; i < this->cantidad - 1; i++) {
            for (int j = 0; j < this->cantidad - i - 1; j++) {
                if (this->socios[j]->getNombre() > this->socios[j + 1]->getNombre()) {
                    Socio* temp = this->socios[j];
                    this->socios[j] = this->socios[j + 1];
                    this->socios[j + 1] = temp;
                }
            }
        }
    }

    void mostrarTodos() {
        cout << "\n=== LISTA DE SOCIOS ===" << endl;
        for (int i = 0; i < this->cantidad; i++) {
            cout << i + 1 << ". ";
            this->socios[i]->mostrar();
        }
    }

    Socio* buscarPorCI(int ci) {
        for (int i = 0; i < this->cantidad; i++) {
            if (this->socios[i]->getCI() == ci) {
                return this->socios[i];
            }
        }
    }

    Socio* buscarPorNombre(const string& nombre) {
        for (int i = 0; i < this->cantidad; i++) {
            if (this->socios[i]->getNombre() == nombre) {
                return this->socios[i];
            }
        }
    }
};
