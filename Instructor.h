#pragma once
#include <iostream>
#include <string>

using namespace std;

class Instructor {

private:
    string nombre;
    int ci;
    int cursosRealizados;
    bool estado;

public:

    Instructor(const string& nombre, int ci)
        : nombre(nombre), ci(ci), cursosRealizados(0), estado(true)
    {
    }

    string getNombre() { return nombre; }
    int getCursos() { return cursosRealizados; }
    bool estaLibre() { return estado; }

    void ocupar() { estado = false; }
    void liberar() { estado = true; }

    void incrementarCursos() { cursosRealizados++; }

    void mostrar() {

        cout << "Nombre: " << nombre << endl;
        cout << "CI: " << ci << endl;
        cout << "Cursos realizados: " << cursosRealizados << endl;
        cout << "Estado: " << (estado ? "Libre" : "Ocupado") << endl;
    }
};