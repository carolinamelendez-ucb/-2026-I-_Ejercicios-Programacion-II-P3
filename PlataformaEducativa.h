#pragma once
#include <iostream>
#include <string>
#include "VectorInstructores.h"
#include "VectorCursos.h"
#include "Curso.h"
using namespace std;

class PlataformaEducativa {
private:
    VectorInstructores instructores;
    VectorCursos cursos;

public:
    PlataformaEducativa() {}

    void registrarInstructor(string nombre, string carnet) {
        Instructor* nuevo = new Instructor(nombre, carnet, 0, "libre");
        instructores.agregar(nuevo);
        cout << "Instructor " << nombre << " registrado exitosamente" << endl;
    }

    void mostrarInstructoresOrdenadosPorCursos() {
        if (instructores.getTamano() == 0) {
            cout << "No hay instructores registrados" << endl;
            return;
        }

        VectorInstructores copia = instructores;
        copia.ordenarPorCursosDescendente();
        copia.mostrar();
    }

    void registrarCurso(int id, string nombre, int maxEstudiantes) {
        Instructor* seleccionado = instructores.obtenerInstructorLibreConMenosCursos();

        if (seleccionado == nullptr) {
            cout << "No hay instructores libres para asignar al curso " << nombre << endl;
            return;
        }

        seleccionado->setEstado("ocupado");

        Curso* nuevoCurso = new Curso(id, nombre, maxEstudiantes, seleccionado);
        cursos.agregar(nuevoCurso);
        cout << "Curso " << nombre << " registrado con instructor " << seleccionado->getNombre() << endl;
    }

    void registrarEstudianteEnCurso(int idCurso, string nombreEstudiante, string emailEstudiante) {
        Curso* curso = cursos.buscarPorId(idCurso);

        if (curso == nullptr) {
            cout << "Curso con ID " << idCurso << " no encontrado" << endl;
            return;
        }

        Estudiante nuevo(nombreEstudiante, emailEstudiante);
        if (curso->agregarEstudiante(nuevo)) {
            cout << "Estudiante " << nombreEstudiante << " agregado al curso " << curso->getNombre() << endl;
        }
        else {
            cout << "Curso lleno, no se pudo agregar a " << nombreEstudiante << endl;
        }
    }

    void finalizarCurso(int idCurso) {
        Curso* curso = cursos.buscarPorId(idCurso);

        if (curso == nullptr) {
            cout << "Curso con ID " << idCurso << " no encontrado" << endl;
            return;
        }

        curso->finalizarCurso();
        cout << "Curso finalizado: " << curso->getNombre() << endl;
    }

    void mostrarInstructorConMasCursos() {
        Instructor* maxInstructor = instructores.obtenerInstructorConMasCursos();

        if (maxInstructor == nullptr) {
            cout << "No hay instructores registrados" << endl;
            return;
        }

        cout << "\n=== Instructor con mayor cantidad de cursos realizados ===" << endl;
        maxInstructor->mostrar();
    }
};
