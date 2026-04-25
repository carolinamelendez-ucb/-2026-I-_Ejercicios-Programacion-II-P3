#pragma once
#include <iostream>
#include <string>

using namespace std;

// registro pelicula
template <typename t>
class Pelicula {
public:
    t codigo;
    string titulo;
    int duracion; // minutos de duracion de la pelicula

    Pelicula(t codigo = t(), string titulo = "", int duracion = 0) {
        this->codigo = codigo;
        this->titulo = titulo;
        this->duracion = duracion;
    }

    void mostrar() {
        cout << "codigo: " << codigo << " titulo: " << titulo << " duracion: " << duracion << " min" << endl;
    }
};
