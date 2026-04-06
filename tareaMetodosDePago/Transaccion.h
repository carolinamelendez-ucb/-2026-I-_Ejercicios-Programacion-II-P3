#pragma once
#include <iostream>
#include <string>
#include "MetodoPago.h"

using namespace std;

class Transaccion {
public:
    float monto;
    MetodoPago* metodoPago;
    bool procesada;
    float totalPagado;

public:
    Transaccion(float monto, MetodoPago* metodoPago)
        : monto(monto), metodoPago(metodoPago), procesada(false), totalPagado(0) {
    }

    bool procesar() {
        if (!metodoPago->esValido(monto)) {
            procesada = false;
            totalPagado = 0;
            return false;
        }

        totalPagado = metodoPago->procesarPago(monto);
        procesada = true;
        return true;
    }

    void mostrarDetalle() {
        if (procesada) {
            metodoPago->mostrarDetalle(monto);
        }
        else {
            metodoPago->esValido(monto);
        }
    }

    ~Transaccion() {
    }
};
