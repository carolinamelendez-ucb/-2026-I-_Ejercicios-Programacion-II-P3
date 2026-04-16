#pragma once
#include "Docente.h"
#include "VectorEstudiantes.h"

class Curso {
private:
    string codigo;
    Docente* docente;
    VectorEstudiantes* estudiantes;
    int maxCupo;

public:
    Curso(string codigo, int maxCupo) {
        this->codigo = codigo;
        this->maxCupo = maxCupo;
        docente = nullptr;
        estudiantes = new VectorEstudiantes(maxCupo);
    }

    string getCodigo() { return codigo; }

    void asignarDocente(Docente* d) {
        docente = d;
    }

    bool agregarEstudiante(Estudiante* e) {
        if (estudiantes->getIndice() < maxCupo) {
            estudiantes->agregar(e);
            return true;
        }
        return false;
    }

    VectorEstudiantes* getEstudiantes() {
        return estudiantes;
    }

    float costoCurso() {
        float total = 0;
        for (int i = 0; i < estudiantes->getIndice(); i++) {
            total += estudiantes->get(i)->calcularPago();
        }
        return total;
    }

    void mostrar() {
        cout << "Curso: " << codigo << endl;

        cout << "Docente asignado:" << endl;
        if (docente != nullptr) {
            docente->mostrar();
        }
        else {
            cout << "No asignado" << endl;
        }

        cout << "Lista de alumnos:" << endl;

        for (int i = 0; i < estudiantes->getIndice(); i++) {
            estudiantes->get(i)->mostrar();
            cout << "-----" << endl;
        }

        cout << "Total recaudado en curso: " << costoCurso() << endl;
        cout << "=========================" << endl;
    }
};