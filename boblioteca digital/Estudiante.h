#pragma once
#include <iostream>
#include <string>

using namespace std;

class Libro;

class Estudiante {
private:
    string ci;
    string nombre;
    Libro* libroAsignado;

public:
    Estudiante() : ci(""), nombre(""), libroAsignado(nullptr) {
    }

    Estudiante(string _ci, string _nombre)
        : ci(_ci), nombre(_nombre), libroAsignado(nullptr) {
    }

    string getCi() const { 
        return ci; 
    }

    string getNombre() const { 
        return nombre; 
    }

    Libro* getLibroAsignado() const { 
        return libroAsignado; 
    }

    void setLibroAsignado(Libro* libro) { 
        libroAsignado = libro; 
    }

    bool tieneLibroPrestado() const {
        return libroAsignado != nullptr;
    }

    void asignarLibro(Libro* libro) {
        libroAsignado = libro;
    }

    void devolverLibro() {
        libroAsignado = nullptr;
    }

    string obtenerTituloLibroPrestado() const {
        if (libroAsignado != nullptr) {
            return libroAsignado->getTitulo();
        }
        return "Ninguno";
    }
};
