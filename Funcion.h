#pragma once
#include <iostream>
#include <string>
#include "Pelicula.h"
#include "Sala.h"
#include "Cliente.h"
using namespace std;

class Funcion {
private:
    Pelicula pelicula;
    Sala sala;

    Cliente* clientes;
    int capacidad;
    int cantidad;

public:
    Funcion(Pelicula p, Sala s, int cap = 100) {
        pelicula = p;
        sala = s;
        capacidad = cap;
        cantidad = 0;
        clientes = new Cliente[capacidad];
    }

    ~Funcion() {
        delete[] clientes;
    }

    void agregarCliente(Cliente c) {
        if (cantidad < capacidad) {
            clientes[cantidad++] = c;
        }
        else {
            cout << "No hay espacio para más clientes\n";
        }
    }

    void mostrarClientes() {
        for (int i = 0; i < cantidad; i++) {
            clientes[i].mostrar();
        }
    }
};
};

