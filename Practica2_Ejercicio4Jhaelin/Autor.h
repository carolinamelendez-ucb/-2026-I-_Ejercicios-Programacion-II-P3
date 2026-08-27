#pragma once


#include <string>

using namespace std;

class Autor {
private:
    string nombre;
    string nacionalidad;
    int cantidadLibrosPublicados;

public:
    Autor(string nombre, string nacionalidad, int cantidadLibrosPublicados) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadLibrosPublicados = cantidadLibrosPublicados;
    }

    string getNombre() { return nombre; }
    int getCantidadLibrosPublicados() { return cantidadLibrosPublicados; }
};
