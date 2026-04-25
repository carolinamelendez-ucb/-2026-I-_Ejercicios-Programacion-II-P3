#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pelicula {
    private:
    string nombre;
    string genero;
    public:
    Pelicula () : nombre (""), genero ("") {}

    Pelicula (const string& nombre, const string& genero)
        : nombre (nombre), genero (genero) {
    }

    string getNombre () 
    {
        return nombre; 
        }
    string getGenero () {
        return genero; 
        }

    void mostrar ()  {
        cout << "  Pelicula: " << nombre << " | Genero: " << genero << endl;
    }
};