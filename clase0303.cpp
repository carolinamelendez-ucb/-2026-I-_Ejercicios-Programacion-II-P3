#include <string>
#include <iostream>
#include "Alumno.h"

using namespace std;

void editarNombreSinPuntero(Alumno alumno) {
    alumno.setNombre("Daniel");
}

void editarNombreConPuntero(Alumno* alumno) {
    alumno->setNombre("Daniel");
}

int main()
{
    //OBJETO SIN PUNTERO
    cout << "------------------SIN PUNTERO--" << endl;
    Alumno alumnoAna = Alumno("Ana", 5);
    alumnoAna.mostrar();
    cout << "Despues..." << endl;
    editarNombreSinPuntero(alumnoAna);
    alumnoAna.mostrar();

    //OBJETO CON PUNTERO
    cout << "------------------CON PUNTERO--" << endl;
    Alumno* alumnoMarcos = new Alumno("Marcos", 2);
    alumnoMarcos->mostrar();
    cout << "Despues..." << endl;
    editarNombreConPuntero(alumnoMarcos);
    alumnoMarcos->mostrar();
}
