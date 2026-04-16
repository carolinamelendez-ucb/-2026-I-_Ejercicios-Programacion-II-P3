#pragma once
#include "Persona.h"

class Estudiante : public Persona {
protected:
    float matricula;
    bool pagoRealizado;

public:
    Estudiante(string ci, string nombre, float matricula)
        : Persona(ci, nombre) {
        this->matricula = matricula;
        pagoRealizado = false;
    }

    void pagar() {
        pagoRealizado = true;
    }

    bool getPago() {
        return pagoRealizado;
    }

    virtual float calcularPago() {
        return matricula;
    }

    void mostrar() override {
        cout << "CI: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Pago: " << calcularPago() << endl;
    }
};