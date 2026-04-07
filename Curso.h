#pragma once
#include <iostream>
#include <string>
#include "VectorEstudiantes.h"
#include "Instructor.h"
using namespace std;

class Curso {
private:
    int id;
    string nombre;
    int maxEstudiantes;
    VectorEstudiantes estudiantes;
    Instructor* instructorAsignado;

public:
    Curso(int id = 0, string nombre = "", int maxEstudiantes = 0, Instructor* instructor = nullptr)
        : id(id), nombre(nombre), maxEstudiantes(maxEstudiantes), instructorAsignado(instructor), estudiantes(maxEstudiantes) {
    }

    int getId() { return id; }
    string getNombre() { return nombre; }
    Instructor* getInstructor() { return instructorAsignado; }

    void setInstructor(Instructor* instructor) {
        instructorAsignado = instructor;
    }

    bool agregarEstudiante(Estudiante e) {
        if (estudiantes.getTamano() < maxEstudiantes) {
            estudiantes.agregar(e);
            return true;
        }
        return false;
    }

    void finalizarCurso() {
        if (instructorAsignado != nullptr) {
            instructorAsignado->incrementarCursos();
            instructorAsignado->setEstado("libre");
        }
    }

    void mostrar() {
        cout << "Curso ID: " << id << " | Nombre: " << nombre
            << " | Max estudiantes: " << maxEstudiantes
            << " | Estudiantes inscritos: " << estudiantes.getTamano()
            << " | Instructor: " << (instructorAsignado ? instructorAsignado->getNombre() : "Ninguno")
            << endl;
        estudiantes.mostrar();
    }
};