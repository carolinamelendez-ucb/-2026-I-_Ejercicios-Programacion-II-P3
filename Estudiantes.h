#pragma once
#include <string>
#include  <iostream> 
#include <exception>
using namespace std;

class Estudiante
{
private:
    string ci;
    string nombre;
    string libroAsignado;

public:

    Estudiante()
    {
        ci = "";
        nombre = "";
        libroAsignado = "";
    }

    Estudiante(string c, string n)
    {
        ci = c;
        nombre = n;
        libroAsignado = "";
    }

    string getCI() { return ci; }
    string getNombre() { return nombre; }
    string getLibroAsignado() { return libroAsignado; }

    void setLibroAsignado(string cod)
    {
        libroAsignado = cod;
    }
};



