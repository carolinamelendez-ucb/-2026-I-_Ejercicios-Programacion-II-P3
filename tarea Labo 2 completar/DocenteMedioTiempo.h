#pragma once
#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

class DocenteMedioTiempo : public Persona {
public:
    float salarioBase;
    int cantidadCursos;
    float bono;

    DocenteMedioTiempo(int ci, const string& nombre, const string& email,
        float salarioBase, int cantidadCursos)
        : Persona(ci, nombre, email) {
        this->salarioBase = salarioBase;
        this->cantidadCursos = cantidadCursos;

        if (cantidadCursos >= 2) {
            this->bono = 0.10;
        }
        else {
            this->bono = 0;
        }
    }

    float calcularSalario() {
        return salarioBase + (salarioBase * bono);
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
        cout << "Docente Medio Tiempo - CI: " << ci << ", Nombre: " << nombre
            << ", Email: " << email << ", Cursos: " << cantidadCursos
            << ", Bono: " << (bono * 100) << "%"
            << ", Salario total: " << salarioTotal << endl;
    }

    ~DocenteMedioTiempo() {
    }
};