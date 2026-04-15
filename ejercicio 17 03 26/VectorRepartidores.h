#pragma once
#include <iostream>
#include <string>

#include "Repartidor.h"

using namespace std;

class VectorRepartidores {
private:
    Repartidor* datos;
    int capacidad;
    int cantidad;

    void redimensionar();

public:
    VectorRepartidores();
    ~VectorRepartidores();

    void agregar(Repartidor& r);
    Repartidor* obtener(int indice);
    int getCantidad();
    void intercambiar(int i, int j);
    void ordenarPorEntregas();
    Repartidor* buscarPorId(int id);
    Repartidor* buscarLibre();
    Repartidor* obtenerMenorEntregas();
};

