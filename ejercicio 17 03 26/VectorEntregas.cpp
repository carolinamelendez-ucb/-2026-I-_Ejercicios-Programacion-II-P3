#include "VectorEntregas.h"

#include <iostream>
#include <string>

using namespace std;

VectorEntregas::VectorEntregas() {
    capacidad = 5;
    cantidad = 0;
    datos = new Entrega[capacidad];
}

VectorEntregas::~VectorEntregas() {
    delete[] datos;
}

void VectorEntregas::redimensionar() {
    capacidad *= 2;
    Entrega* nuevosDatos = new Entrega[capacidad];

    for (int i = 0; i < cantidad; i++) {
        nuevosDatos[i] = datos[i];
    }

    delete[] datos;
    datos = nuevosDatos;
}

void VectorEntregas::agregar(Entrega& e) {
    if (cantidad >= capacidad) {
        redimensionar();
    }
    datos[cantidad] = e;
    cantidad++;
}

Entrega* VectorEntregas::obtener(int indice) {
    if (indice >= 0 && indice < cantidad) {
        return &datos[indice];
    }
    return 0;
}

int VectorEntregas::getCantidad() {
    return cantidad;
}

Entrega* VectorEntregas::buscarPorId(int id) {
    for (int i = 0; i < cantidad; i++) {
        if (datos[i].id == id) {
            return &datos[i];
        }
    }
    return 0;
}