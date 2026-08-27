#pragma once
#include <string>
#include "Autor.h"

using namespace std;

class Libro {
private:
    string titulo;
    double precio;
    Autor* autor;

public:
    Libro(string titulo, double precio, Autor* autor) {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }

    string getTitulo() { return titulo; }
    double getPrecio() { return precio; }
    Autor* getAutor() { return autor; }

    bool esBestSeller() {
        return autor->getCantidadLibrosPublicados() > 5;
    }
};
