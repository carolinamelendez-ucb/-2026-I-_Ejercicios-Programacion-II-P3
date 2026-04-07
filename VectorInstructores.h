#pragma once
#include <iostream>
#include "Instructor.h"
using namespace std;

class VectorInstructores {
private:
    Instructor** datos;
    int capacidad;
    int tamano;

    void redimensionar() {
        capacidad *= 2;
        Instructor** nuevo = new Instructor * [capacidad];
        for (int i = 0; i < tamano; i++)
            nuevo[i] = datos[i];
        delete[] datos;
        datos = nuevo;
    }

public:
    VectorInstructores()
        : capacidad(5), tamano(0) {
        datos = new Instructor * [capacidad];
    }

    ~VectorInstructores() {
        for (int i = 0; i < tamano; i++)
            delete datos[i];
        delete[] datos;
    }

    void agregar(Instructor* instructor) {
        if (tamano == capacidad)
            redimensionar();
        datos[tamano++] = instructor;
    }

    Instructor* obtener(int index) {
        if (index >= 0 && index < tamano)
            return datos[index];
        return nullptr;
    }

    int getTamano() { return tamano; }

    void ordenarPorCursosDescendente() {
        for (int i = 0; i < tamano - 1; i++) {
            for (int j = 0; j < tamano - i - 1; j++) {
                if (datos[j]->getCursosRealizados() < datos[j + 1]->getCursosRealizados()) {
                    Instructor* aux = datos[j];
                    datos[j] = datos[j + 1];
                    datos[j + 1] = aux;
                }
            }
        }
    }

    Instructor* obtenerInstructorLibreConMenosCursos() {
        Instructor* seleccionado = nullptr;
        for (int i = 0; i < tamano; i++) {
            if (datos[i]->getEstado() == "libre") {
                if (seleccionado == nullptr ||
                    datos[i]->getCursosRealizados() < seleccionado->getCursosRealizados()) {
                    seleccionado = datos[i];
                }
            }
        }
        return seleccionado;
    }

    Instructor* obtenerInstructorConMasCursos() {
        if (tamano == 0) return nullptr;
        Instructor* maxInstructor = datos[0];
        for (int i = 1; i < tamano; i++) {
            if (datos[i]->getCursosRealizados() > maxInstructor->getCursosRealizados()) {
                maxInstructor = datos[i];
            }
        }
        return maxInstructor;
    }

    void mostrar() {
        cout << "\n=== Instructores ordenados por cursos realizados (mayor a menor) ===" << endl;
        for (int i = 0; i < tamano; i++) {
            datos[i]->mostrar();
        }
    }
};
