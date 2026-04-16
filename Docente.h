#pragma once
#include "Persona.h"

class Docente : public Persona {
protected:
    float salarioBase;
public:
    Docente(string ci, string nombre, float salarioBase)
        : Persona(ci, nombre) {
        this->salarioBase = salarioBase;
    }

    virtual float calcularSalario() {
        return salarioBase;
    }

    virtual bool aproboEntrevista() {
        return true;
    }

    void mostrar() override {
        cout << "CI: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
    }
};