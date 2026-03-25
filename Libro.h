#pragma once
#include <iostream>
#include <string>

using namespace std;

class Libro {

private:
    int codigo;
    string titulo;
    bool disponible;

public:

    Libro(int codigo, const string& titulo)
        : codigo(codigo), titulo(titulo), disponible(true) {
    }

    int getCodigo() { return codigo; }
    bool estaDisponible() { return disponible; }

    void prestar() { disponible = false; }
    void devolver() { disponible = true; }

    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Estado: " << (disponible ? "Disponible" : "Prestado") << endl;
    }
};