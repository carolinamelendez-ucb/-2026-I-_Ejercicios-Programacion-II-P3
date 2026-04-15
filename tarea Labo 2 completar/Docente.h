#pragma once
#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

class Docente : public Persona {
public:
    float salarioBase;
    float salarioTotal;

    Docente(int ci, const string& nombre, const string& email, float salarioBase)
        : Persona(ci, nombre, email) {
        this->salarioBase = salarioBase;
        this->salarioTotal = 0;
    }

    virtual float calcularSalario() = 0;

    float calcularPago() override {
        return calcularSalario();
    }

    virtual void mostrarInformacion() = 0;

    ~Docente() {
    }
};