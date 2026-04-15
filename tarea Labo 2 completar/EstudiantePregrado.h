#pragma once
#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

class EstudiantePregrado : public Persona {
public:
    float matriculaFija;

    EstudiantePregrado(int ci, const string& nombre, const string& email)
        : Persona(ci, nombre, email) {
        this->matriculaFija = 100;
    }

    float calcularPago() override {
        return matriculaFija;
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
        cout << "Estudiante Pregrado - CI: " << ci << ", Nombre: " << nombre
            << ", Email: " << email << ", Total a pagar: " << totalPagado << endl;
    }

    ~EstudiantePregrado() {
    }
};