#include <iostream>
#include <string>
#include <exception>
#include "Estudiantes.h"
#include "Libro.h"
#include "Biblioteca.h"

using namespace std;


int main()
{
    Biblioteca biblio("lumen");


    biblio.agregarLibro(Libro("L1", "Calculo", "Stewart"));
    biblio.agregarLibro(Libro("L2", "Algebra", "Lay"));


    biblio.agregarEstudiante(Estudiante("111", "Juan"));
    biblio.agregarEstudiante(Estudiante("222", "Maria"));


    try
    {
        biblio.prestarLibro("111", "L1");

        biblio.listarPrestamos();

        biblio.libroMasSolicitado();
    }
    catch (exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

}