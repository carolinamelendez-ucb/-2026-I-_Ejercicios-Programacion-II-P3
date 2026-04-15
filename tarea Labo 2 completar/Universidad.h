#pragma once
#include <iostream>
#include <string>
#include "VectorPersonas.h"
#include "VectorCursos.h"

using namespace std;

class Universidad {
public:
    VectorPersonas* listaPersonas;
    VectorCursos* listaCursos;

    Universidad(int maxPersonas, int maxCursos) {
        listaPersonas = new VectorPersonas(maxPersonas);
        listaCursos = new VectorCursos(maxCursos);
    }

    void registrarEstudiante(Persona* estudiante) {
        listaPersonas->agregar(estudiante);
    }

    void registrarDocente(Persona* docente) {
        listaPersonas->agregar(docente);
    }

    void registrarCurso(Curso* curso) {
        listaCursos->agregar(curso);
    }

    void asignarDocenteACurso(int ciDocente, const string& codigoCurso) {
        Persona* persona = listaPersonas->buscarPorCi(ciDocente);
        Curso* curso = listaCursos->buscarPorCodigo(codigoCurso);

        if (persona == nullptr) {
            cout << "Error: No se encontro docente con CI " << ciDocente << endl;
            return;
        }

        if (curso == nullptr) {
            cout << "Error: No se encontro curso con codigo " << codigoCurso << endl;
            return;
        }

        if (!persona->esDocente()) {
            cout << "Error: La persona con CI " << ciDocente << " no es un docente" << endl;
            return;
        }

        curso->asignarDocente(persona);
        cout << "Docente " << persona->nombre << " asignado al curso " << curso->nombre << endl;
    }

    void asignarEstudianteACurso(int ciEstudiante, const string& codigoCurso) {
        Persona* persona = listaPersonas->buscarPorCi(ciEstudiante);
        Curso* curso = listaCursos->buscarPorCodigo(codigoCurso);

        if (persona == nullptr) {
            cout << "Error: No se encontro estudiante con CI " << ciEstudiante << endl;
            return;
        }

        if (curso == nullptr) {
            cout << "Error: No se encontro curso con codigo " << codigoCurso << endl;
            return;
        }

        if (!persona->esEstudiante()) {
            cout << "Error: La persona con CI " << ciEstudiante << " no es un estudiante" << endl;
            return;
        }

        if (curso->agregarEstudiante(persona)) {
            cout << "Estudiante " << persona->nombre << " inscrito en el curso " << curso->nombre << endl;
        }
        else {
            cout << "Error: El curso " << curso->nombre << " esta lleno" << endl;
        }
    }

    void mostrarEstudiantes() {
        listaPersonas->mostrarEstudiantes();
    }

    void mostrarDocentes() {
        listaPersonas->mostrarDocentes();
    }

    void mostrarCursos() {
        listaCursos->mostrarCursos();
    }

    void mostrarTotalGeneral() {
        float total = listaCursos->calcularTotalGeneral();
        cout << "\n=== TOTAL GENERAL RECAUDADO POR LA UNIVERSIDAD ===" << endl;
        cout << "Total: " << total << endl;
    }

    void mostrarEstudianteQueMasPaga() {
        Persona* estudiante = listaPersonas->getEstudianteQueMasPaga();
        if (estudiante != nullptr) {
            cout << "\n=== ESTUDIANTE QUE MAS PAGA ===" << endl;
            estudiante->mostrarInformacion();
        }
    }

    void mostrarCursoMasEconomico() {
        Curso* curso = listaCursos->getCursoMasEconomico();
        if (curso != nullptr) {
            cout << "\n=== CURSO MAS ECONOMICO ===" << endl;
            cout << "Curso: " << curso->codigo << " - " << curso->nombre
                << ", Costo: " << curso->costo << endl;
        }
    }

    ~Universidad() {
        delete listaPersonas;
        delete listaCursos;
    }
};