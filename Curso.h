#pragma once
#include <iostream>
#include <string>
#include "Instructor.h"
#include "Estudiante.h"
using namespace std;

class Curso {
private:
    int id;
    string nombre;
    int maxEstudiantes;
    Estudiante* estudiantes;
    int cantidad;
    Instructor* instructor;
    bool activo;

public:
    Curso(int id, string nombre, int maxEst, Instructor* inst)
        : id(id), nombre(nombre), maxEstudiantes(maxEst), instructor(inst) {
        estudiantes = new Estudiante[maxEstudiantes];
        cantidad = 0;
        activo = true;
    }

    int getId() {
        return id;
    }

    void agregarEstudiante(string nombre, string ci) {
        if (cantidad < maxEstudiantes) {
            estudiantes[cantidad++] = Estudiante(nombre, ci);
        }
        else {
            cout << "Curso lleno" << endl;
        }
    }

    void finalizarCurso() {
        if (instructor != nullptr) {
            instructor->liberar();
            instructor->incrementarCursos();
            activo = false;
        }
    }

    void mostrar() {
        cout << "Curso: " << nombre << " | Instructor: ";

        if (instructor != nullptr) {
            cout << instructor->getNombre();
        }

        cout << endl << "Estudiantes:" << endl;

        for (int i = 0; i < cantidad; i++) {
            estudiantes[i].mostrar();
        }

        cout << "----------------------" << endl;
    }
};