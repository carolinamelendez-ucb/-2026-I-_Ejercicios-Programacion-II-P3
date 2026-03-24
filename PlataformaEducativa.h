#pragma once
#include <iostream>
#include "VectorInstructores.h"
#include "VectorCursos.h"

using namespace std;

class PlataformaEducativa {

private:

    InstructoresVector* instructores;
    CursosVector* cursos;

public:

    PlataformaEducativa(int tamanioInstructores, int tamanioCursos) {

        instructores = new InstructoresVector(tamanioInstructores);
        cursos = new CursosVector(tamanioCursos);
    }

    ~PlataformaEducativa() {
        delete instructores;
        delete cursos;
    }

    void registrarInstructor(const string& nombre, int ci) {
        instructores->agregar(new Instructor(nombre, ci));
    }

    void mostrarInstructoresOrdenados() {
        instructores->ordenarPorCursos();
        instructores->mostrar();
    }

    void registrarCurso(int id, const string& nombre, int maxEst) {
        Instructor* i = instructores->buscarLibreMenorCursos();
        if (i == nullptr) {
            cout << "No hay instructores disponibles" << endl;
            return;
        }
        cursos->agregar(new Curso(id, nombre, maxEst, i));
    }

    void registrarEstudiante(int idCurso) {
        Curso* curso = cursos->buscar(idCurso);
        if (curso != nullptr) {
            curso->registrarEstudiante();
        }
    }

    void finalizarCurso(int idCurso) {
        Curso* curso = cursos->buscar(idCurso);
        if (curso != nullptr) {
            curso->finalizar();
            cout << "Se finalizo el curso " << idCurso << endl;
        }
    }

    void mostrarTop() {
        Instructor* mejor = instructores->get(0);
        for (int i = 1; i < instructores->getIndice(); i++) {
            if (instructores->get(i)->getCursos() > mejor->getCursos()) {
                mejor = instructores->get(i);
            }
        }
        cout << "INSTRUCTOR TOP" << endl;
        cout << endl;
        mejor->mostrar();
    }

    void mostrarCursos() {
        cursos->mostrar();
    }
};