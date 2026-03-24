#pragma once
#include <iostream>
#include <string>
#include "Instructor.h"

using namespace std;

class Curso {

private:
    int id;
    string nombre;
    int maxEst;
    int inscritos;
    Instructor* instructor;
    bool finalizado;

public:
    Curso(int id, const string& nombre, int maxEst, Instructor* instructor)
        : id(id), nombre(nombre), maxEst(maxEst), inscritos(0), instructor(instructor), finalizado(false)
    {
        instructor->ocupar();
    }

    int getId() { return id; }

    void registrarEstudiante() {
        if (inscritos < maxEst) {
            inscritos++;
            cout << "Estudiante registrado en el curso: " << id << endl;
        }
        else {
            cout << "No se pueden registrar mas estudiantes en el curso: " << id << endl;
        }
    }

    void finalizar() {
        if (!finalizado) {
            instructor->incrementarCursos();
            instructor->liberar();
            finalizado = true;
        }
    }

    void mostrar() {
        cout << "Curso: " << nombre << endl;
        cout << "ID: " << id << endl;
        cout << "Max estudiantes: " << maxEst << endl;
        cout << "Inscritos: " << inscritos << endl;
        cout << "Instructor: " << instructor->getNombre() << endl;
    }
};