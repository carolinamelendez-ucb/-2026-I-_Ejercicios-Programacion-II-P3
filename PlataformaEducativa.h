#pragma once
#include <iostream>
#include <string>
#include "VectorInstructores.h"
#include "VectorCursos.h"
using namespace std;

class PlataformaEducativa {
private:
    VectorInstructores* instructores;
    VectorCursos* cursos;

public:
    PlataformaEducativa(int t1, int t2) {
        instructores = new VectorInstructores(t1);
        cursos = new VectorCursos(t2);
    }

    void registrarInstructor(Instructor* i) {
        instructores->agregar(i);
    }

    void mostrarInstructoresOrdenados() {
        instructores->ordenar();
        instructores->mostrar();
    }

    void registrarCurso(int id, string nombre, int maxEst) {
        Instructor* inst = instructores->buscarLibreMenorCursos();
        if (inst != nullptr) {
            inst->ocupar();
            cursos->agregar(new Curso(id, nombre, maxEst, inst));
        }
        else {
            cout << "No hay instructores libres" << endl;
        }
    }

    void registrarEstudiante(int idCurso, string nombre, string ci) {
        Curso* c = cursos->buscar(idCurso);
        if (c != nullptr) {
            c->agregarEstudiante(nombre, ci);
        }
    }

    void finalizarCurso(int idCurso) {
        Curso* c = cursos->buscar(idCurso);
        if (c != nullptr) {
            c->finalizarCurso();
            cout << "Curso finalizado" << endl;
        }
    }

    void mostrarCursos() {
        cursos->mostrar();
    }

    void mejorInstructor() {
        if (instructores->getCantidad() == 0) return;

        Instructor* mejor = instructores->obtener(0);

        for (int i = 1; i < instructores->getCantidad(); i++) {
            Instructor* actual = instructores->obtener(i);
            if (actual->getCursosRealizados() > mejor->getCursosRealizados()) {
                mejor = actual;
            }
        }

        mejor->mostrar();
    }
};