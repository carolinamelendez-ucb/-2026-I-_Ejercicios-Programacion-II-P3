#pragma once
#include <iostream>
#include <string>
#include "Curso.h"

using namespace std;

class VectorCursos {
public:
    Curso** cursos;
    int cantidad;
    int tamanio;

    VectorCursos(int tamanioMax) {
        this->cursos = new Curso * [tamanioMax];
        this->tamanio = tamanioMax;
        this->cantidad = 0;
    }

    bool existeCodigo(const string& codigo) {
        for (int i = 0; i < cantidad; i++) {
            if (cursos[i]->codigo == codigo) {
                return true;
            }
        }
        return false;
    }

    void agregar(Curso* nuevoCurso) {
        if (existeCodigo(nuevoCurso->codigo)) {
            cout << "Error: Ya existe un curso con codigo " << nuevoCurso->codigo << endl;
            delete nuevoCurso;
            return;
        }

        if (cantidad < tamanio) {
            cursos[cantidad] = nuevoCurso;
            cantidad++;
            cout << "Curso agregado exitosamente" << endl;
        }
        else {
            cout << "Error: El vector de cursos esta lleno" << endl;
            delete nuevoCurso;
        }
    }

    Curso* buscarPorCodigo(const string& codigo) {
        for (int i = 0; i < cantidad; i++) {
            if (cursos[i]->codigo == codigo) {
                return cursos[i];
            }
        }
        return nullptr;
    }

    void mostrarCursos() {
        cout << "\n=== LISTA DE CURSOS ===" << endl;
        for (int i = 0; i < cantidad; i++) {
            cursos[i]->mostrarInformacion();
        }
    }

    Curso* getCursoMasEconomico() {
        if (cantidad == 0) return nullptr;

        Curso* masEconomico = cursos[0];
        for (int i = 1; i < cantidad; i++) {
            if (cursos[i]->costo < masEconomico->costo) {
                masEconomico = cursos[i];
            }
        }
        return masEconomico;
    }

    float calcularTotalGeneral() {
        float total = 0;
        for (int i = 0; i < cantidad; i++) {
            total += cursos[i]->calcularTotalRecaudado();
        }
        return total;
    }

    ~VectorCursos() {
        for (int i = 0; i < cantidad; i++) {
            delete cursos[i];
        }
        delete[] cursos;
    }
};