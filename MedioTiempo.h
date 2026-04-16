#pragma once
#include "Docente.h"

class MedioTiempo : public Docente {
private:
    int cantidadCursos;

public:
    MedioTiempo(string ci, string nombre, float salario)
        : Docente(ci, nombre, salario) {
        cantidadCursos = 0;
    }

    void incrementarCurso() {
        cantidadCursos++;
    }

    float calcularSalario() override {
        if (cantidadCursos >= 2)
            return salarioBase * 1.1;
        return salarioBase;
    }
};