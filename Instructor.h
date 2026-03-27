#pragma once
#include <iostream>
#include <string>
using namespace std;

class Instructor {
private:
    string nombre;
    string ci;
    int cursosRealizados;
    bool estaLibre;

public:
    Instructor(string nombre, string ci, int cursos, bool estado)
        : nombre(nombre), ci(ci), cursosRealizados(cursos), estaLibre(estado) {
    }

    string getNombre() {
        return nombre;
    }

    int getCursosRealizados() {
        return cursosRealizados;
    }

    bool getDisponibilidad() {
        return estaLibre;
    }

    void ocupar() {
        estaLibre = false;
    }

    void liberar() {
        estaLibre = true;
    }

    void incrementarCursos() {
        cursosRealizados++;
    }

    void mostrar() {
        cout << nombre << " | CI: " << ci
            << " | Cursos: " << cursosRealizados << endl;

        if (estaLibre) {
            cout << "Estado: Libre" << endl;
        }
        else {
            cout << "Estado: Ocupado" << endl;
        }
    }
};