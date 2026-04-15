#pragma once
#include <iostream>
#include <string>

#include "VectorRepartidores.h"
#include "VectorEntregas.h"

using namespace std;

class SistemaEntregas {
private:
    VectorRepartidores repartidores;
    VectorEntregas entregas;

public:
    bool registrarRepartidor(string nombre, int id);
    bool registrarEntrega(int id, string direccion);
    void mostrarRepartidoresOrdenados();
    bool aumentarPaquetesEntrega(int idEntrega, int cantidad);
    bool finalizarEntrega(int idEntrega);
    void mostrarRepartidorMenorEntregas();
};
