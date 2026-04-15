#pragma once
#include <iostream>
#include <string>

#include "Entrega.h"

using namespace std;

class VectorEntregas {
private:
    Entrega* datos;
    int capacidad;
    int cantidad;

    void redimensionar();

public:
    VectorEntregas();
    ~VectorEntregas();

    void agregar(Entrega& e);
    Entrega* obtener(int indice);
    int getCantidad();
    Entrega* buscarPorId(int id);
};

