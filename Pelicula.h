#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pelicula {

private:
    string nombre;
    int codigo;

public:

    Pelicula(const string& nombre, int codigo)
        : nombre(nombre), codigo(codigo)
    {
    }

    string getNombre() {
        return nombre;
    }

    void mostrar() {
        cout << "Pelicula: " << nombre << endl;
        cout << "Codigo: " << codigo << endl;
    }
};