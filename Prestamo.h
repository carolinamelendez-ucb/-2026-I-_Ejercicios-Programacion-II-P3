#pragma once
#include <iostream>

using namespace std;

class Prestamo {

private:
    int ciEstudiante;
    int codigoLibro;
    bool activo;

public:

    Prestamo(int ci, int codigo)
        : ciEstudiante(ci), codigoLibro(codigo), activo(true) {
    }

    int getCi() { return ciEstudiante; }
    int getCodigoLibro() { return codigoLibro; }
    bool estaActivo() { return activo; }

    void finalizar() { activo = false; }

    void mostrar() {
        cout << "CI Estudiante: " << ciEstudiante << endl;
        cout << "Codigo Libro: " << codigoLibro << endl;
        cout << "Estado: " << (activo ? "Activo" : "Inactivo") << endl;
    }
};
