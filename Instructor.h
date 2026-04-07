#pragma once
#include <iostream>
#include <string>
using namespace std;

class Instructor {
private:
    string nombre;
    string carnet;
    int cursosRealizados;
    string estado;

public:
    Instructor(string nombre = "", string carnet = "", int cursosRealizados = 0, string estado = "libre")
        : nombre(nombre), carnet(carnet), cursosRealizados(cursosRealizados), estado(estado) {
    }

    string getNombre() { return nombre; }
    string getCarnet() { return carnet; }
    int getCursosRealizados() { return cursosRealizados; }
    string getEstado() { return estado; }

    void setEstado(string nuevoEstado) { estado = nuevoEstado; }
    void incrementarCursos() { cursosRealizados++; }

    void mostrar() {
        cout << "Instructor: " << nombre << " | Carnet: " << carnet
            << " | Cursos realizados: " << cursosRealizados
            << " | Estado: " << estado << endl;
    }
};
