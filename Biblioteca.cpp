// Biblioteca.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SistemaBiblioteca.h"
using namespace std;

int main()
{
    //registrar Estudiantes

    SistemaBibliotecas sis(10, 10, 10);

    sis.registrarEstudiante("123", "JUAN");
    sis.registrarEstudiante("456", "CRISTIAN");
    sis.registrarEstudiante("789", "lEON");
    sis.registrarEstudiante("910", "ADA");
    sis.registrarEstudiante("911", "DRAKE");
    sis.registrarEstudiante("123", "PEDRO");

    //Libros

    sis.registrarLibro("111", "Ana frank");
    sis.registrarLibro("222", "quijote");
    sis.registrarLibro("333", "pioneros");
    sis.registrarLibro("444", "c++");
    sis.registrarLibro("555", "progra");
    sis.registrarLibro("666", "mil leguas");
    sis.registrarLibro("111", "ta largo");

    sis.prestarLibro("123", "111");
    sis.prestarLibro("123", "222");
    sis.prestarLibro("123", "333");
    sis.prestarLibro("123", "444");
    sis.prestarLibro("123", "555");
    sis.prestarLibro("222", "666");
    sis.prestarLibro("333", "111");

    cout << " Prestamos------------------" << endl;
    sis.mostrarPrestamos();

    sis.devolverLibro("123", "111");
    cout << endl;
     
    cout << "ACTULIZADOS....................." << endl;
    sis.mostrarPrestamos();










    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
