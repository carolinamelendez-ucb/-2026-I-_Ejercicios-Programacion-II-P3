#include "VectorRepartidores.h"

#include <iostream>
#include <string>

using namespace std;

VectorRepartidores::VectorRepartidores() {
    capacidad = 5;
    cantidad = 0;
    datos = new Repartidor[capacidad];
}

VectorRepartidores::~VectorRepartidores() {
    delete[] datos;
}

void VectorRepartidores::redimensionar() {
    capacidad *= 2;
    Repartidor* nuevosDatos = new Repartidor[capacidad];

    for (int i = 0; i < cantidad; i++) {
        nuevosDatos[i] = datos[i];
    }

    delete[] datos;
    datos = nuevosDatos;
}

void VectorRepartidores::agregar(Repartidor& r) {
    if (cantidad >= capacidad) {
        redimensionar();
    }
    datos[cantidad] = r;
    cantidad++;
}

Repartidor* VectorRepartidores::obtener(int indice) {
    if (indice >= 0 && indice < cantidad) {
        return &datos[indice];
    }
    return 0;
}

int VectorRepartidores::getCantidad() {
    return cantidad;
}

void VectorRepartidores::intercambiar(int i, int j) {
    if (i >= 0 && i < cantidad && j >= 0 && j < cantidad) {
        Repartidor temp = datos[i];
        datos[i] = datos[j];
        datos[j] = temp;
    }
}

void VectorRepartidores::ordenarPorEntregas() {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (datos[j].entregasRealizadas > datos[j + 1].entregasRealizadas) {
                intercambiar(j, j + 1);
            }
        }
    }
}

Repartidor* VectorRepartidores::buscarPorId(int id) {
    for (int i = 0; i < cantidad; i++) {
        if (datos[i].id == id) {
            return &datos[i];
        }
    }
    return 0;
}

Repartidor* VectorRepartidores::buscarLibre() {
    for (int i = 0; i < cantidad; i++) {
        if (datos[i].estado == "libre") {
            return &datos[i];
        }
    }
    return 0;
}

Repartidor* VectorRepartidores::obtenerMenorEntregas() {
    if (cantidad == 0) {
        return 0;
    }

    Repartidor* menor = &datos[0];

    for (int i = 1; i < cantidad; i++) {
        if (datos[i].entregasRealizadas < menor->entregasRealizadas) {
            menor = &datos[i];
        }
    }

    return menor;
}