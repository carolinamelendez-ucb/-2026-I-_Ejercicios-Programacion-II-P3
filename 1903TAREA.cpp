#include <iostream>
#include "SistemaBiblioteca.h"

using namespace std;

int main() {

    SistemaBiblioteca sistema(5, 5, 10);

    sistema.registrarEstudiante(1, "Juan");
    sistema.registrarEstudiante(2, "Ana");

    sistema.registrarLibro(101, "Guia de C++");
    sistema.registrarLibro(102, "Guia de Java");

    sistema.prestarLibro(1, 101);
    sistema.prestarLibro(1, 102);

    sistema.mostrarPrestamos();

    sistema.devolverLibro(1, 101);

    cout << "TOP (5 prestamos)" << endl;
    sistema.mostrarTop();

    return 0;
}