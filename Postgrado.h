#pragma once
#include "Estudiante.h"

class Postgrado : public Estudiante {
public:
    Postgrado(string ci, string nombre, float matricula)
        : Estudiante(ci, nombre, matricula) {
    }

    float calcularPago() override {
        return matricula * 1.2;
    }
};