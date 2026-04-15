#pragma once
#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

class EstudiantePostgrado : public Persona {
public:
    float matriculaBase;
    float recargo;

    EstudiantePostgrado(int ci, const string& nombre, const string& email)
        : Persona(ci, nombre, email) {
        this->matriculaBase = 100;
        this->recargo = 0.20;
    }

    float calcularPago() override {
        return matriculaBase + (matriculaBase * recargo);
    }

    void agregarPago() override {
        totalPagado += calcularPago();
    }

    void agregarSalario() override {
        // Los estudiantes no tienen salario
    }

    bool esEstudiante() override {
        return true;
    }

    bool esDocente() override {
        return false;
    }

    void mostrarInformacion() override {
        cout << "Estudiante Postgrado - CI: " << ci << ", Nombre: " << nombre
            << ", Email: " << email << ", Total a pagar: " << totalPagado << endl;
    }

    ~EstudiantePostgrado() {
    }
};