#pragma once
#include "Docente.h"

class TiempoCompleto : public Docente {
private:
    int anios;
public:
    TiempoCompleto(string ci, string nombre, float salario, int anios)
        : Docente(ci, nombre, salario) {
        this->anios = anios;
    }

    float calcularSalario() override {
        float bono = 0;
        if (anios <= 5) bono = 0.05;
        else if (anios <= 10) bono = 0.15;
        else bono = 0.25;

        return salarioBase + salarioBase * bono;
    }
};