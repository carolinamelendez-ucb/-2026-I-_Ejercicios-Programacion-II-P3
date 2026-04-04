#pragma once
#include "Transporte.h"

class VectorTransportes {

private:

    Transporte* transportes[20];
    int cantidad;

public:

    VectorTransportes() {
        cantidad = 0;
    }

    bool placaDuplicada(string placa) {

        for (int i = 0;i < cantidad;i++)
            if (transportes[i]->getPlaca() == placa)
                return true;

        return false;
    }

    void agregar(Transporte* transporte) {

        if (!placaDuplicada(transporte->getPlaca()))
            transportes[cantidad++] = transporte;
    }

    Transporte* get(int i) {
        return transportes[i];
    }

    int getCantidad() {
        return cantidad;
    }

    ~VectorTransportes() {

        for (int i = 0;i < cantidad;i++)
            delete transportes[i];
    }
};