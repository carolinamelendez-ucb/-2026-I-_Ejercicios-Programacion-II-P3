#include <iostream>
#include "PlataformaEducativa.h"

using namespace std;

int main() {

    PlataformaEducativa plataforma(5, 5);

    plataforma.registrarInstructor("Carlos", 111);
    plataforma.registrarInstructor("Ana", 222);
    plataforma.registrarInstructor("Luis", 333);

    cout << "INSTRUCTORES ORDENADOS" << endl;
    cout << endl;
    plataforma.mostrarInstructoresOrdenados();

    plataforma.registrarCurso(1, "C++", 3);
    plataforma.registrarCurso(2, "Java", 2);
    cout << endl;
    cout << "CURSOS REGISTRADOS" << endl;
    cout << endl;
    plataforma.mostrarCursos();

    plataforma.registrarEstudiante(1);
    plataforma.registrarEstudiante(1);
    plataforma.registrarEstudiante(1);
    plataforma.registrarEstudiante(1);
    plataforma.registrarEstudiante(2);

    cout << endl;
    cout << "CURSOS ACTTUALIZADOS" << endl;
    cout << endl;
    plataforma.mostrarCursos();

    plataforma.finalizarCurso(1);

    cout << endl;
    cout << "TOP" << endl;
    cout << endl;
    plataforma.mostrarTop();
}