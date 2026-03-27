#include <iostream>
#include <string>
#include "PlataformaEducativa.h"
using namespace std;

int main() {
    PlataformaEducativa sistema(20, 20);
    sistema.registrarInstructor(new Instructor("Juan", "123", 2, true));
    sistema.registrarInstructor(new Instructor("Maria", "456", 0, true));
    sistema.registrarInstructor(new Instructor("Luis", "789", 1, true));
    cout << "Instructores ordenados: " << endl;
    sistema.mostrarInstructoresOrdenados();
    sistema.registrarCurso(1, "C++", 2);
    sistema.registrarCurso(2, "Python", 2);
    sistema.registrarEstudiante(1, "Ana", "111");
    sistema.registrarEstudiante(1, "Carlos", "222");
    cout << endl << "Cursos: " << endl;
    sistema.mostrarCursos();
    sistema.finalizarCurso(1);
    cout << endl << "Mejor instructor: " << endl;
    sistema.mejorInstructor();
}
