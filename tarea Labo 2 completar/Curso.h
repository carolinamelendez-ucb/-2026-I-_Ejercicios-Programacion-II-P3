#pragma once
#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

class Curso {
public:
    string codigo;
    string nombre;
    int costo;
    Persona* docenteAsignado;
    Persona** estudiantes;
    int cantidadEstudiantes;
    int maxEstudiantes;
    bool docenteSeleccionado;

    Curso(const string& codigo, const string& nombre, int costo, int maxEstudiantes)
        : codigo(codigo), nombre(nombre), costo(costo), maxEstudiantes(maxEstudiantes) {
        this->docenteAsignado = nullptr;
        this->cantidadEstudiantes = 0;
        this->docenteSeleccionado = false;
        this->estudiantes = new Persona * [maxEstudiantes];
    }

    void asignarDocente(Persona* docente) {
        docenteAsignado = docente;
        docenteSeleccionado = true;
    }

    bool agregarEstudiante(Persona* estudiante) {
        if (cantidadEstudiantes < maxEstudiantes) {
            estudiantes[cantidadEstudiantes] = estudiante;
            cantidadEstudiantes++;
            estudiante->agregarPago();

            if (docenteAsignado != nullptr) {
                docenteAsignado->agregarSalario();
            }
            return true;
        }
        return false;
    }

    float calcularTotalRecaudado() {
        float total = 0;
        for (int i = 0; i < cantidadEstudiantes; i++) {
            total += estudiantes[i]->calcularPago();
        }
        return total;
    }

    void mostrarInformacion() {
        cout << "Curso: " << codigo << " - " << nombre
            << ", Costo: " << costo << ", Estudiantes: " << cantidadEstudiantes
            << "/" << maxEstudiantes << endl;
    }

    ~Curso() {
        delete[] estudiantes;
    }
};