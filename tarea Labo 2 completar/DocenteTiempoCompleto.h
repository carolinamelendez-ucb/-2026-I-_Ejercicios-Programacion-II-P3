#pragma once
#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

class DocenteTiempoCompleto : public Persona {
public:
    float salarioBase;
    int anosAntiguedad;
    float porcentajeBono;

    DocenteTiempoCompleto(int ci, const string& nombre, const string& email,
        float salarioBase, int anosAntiguedad)
        : Persona(ci, nombre, email) {
        this->salarioBase = salarioBase;
        this->anosAntiguedad = anosAntiguedad;

        if (anosAntiguedad >= 0 && anosAntiguedad <= 5) {
            this->porcentajeBono = 0.05;
        }
        else if (anosAntiguedad >= 6 && anosAntiguedad <= 10) {
            this->porcentajeBono = 0.15;
        }
        else {
            this->porcentajeBono = 0.25;
        }
    }

    float calcularSalario() {
        return salarioBase + (salarioBase * porcentajeBono);
    }

    float calcularPago() override {
        return calcularSalario();
    }

    void agregarPago() override {
        // Los docentes no pagan, reciben salario
    }

    void agregarSalario() override {
        salarioTotal += calcularSalario();
    }

    bool esEstudiante() override {
        return false;
    }

    bool esDocente() override {
        return true;
    }

    void mostrarInformacion() override {
        cout << "Docente Tiempo Completo - CI: " << ci << ", Nombre: " << nombre
            << ", Email: " << email << ", Antiguedad: " << anosAntiguedad << " anos"
            << ", Bono: " << (porcentajeBono * 100) << "%"
            << ", Salario total: " << salarioTotal << endl;
    }

    ~DocenteTiempoCompleto() {
    }
};