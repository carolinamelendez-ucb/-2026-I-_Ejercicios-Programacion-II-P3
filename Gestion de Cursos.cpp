#include <iostream>
#include "PlataformaEducativa.h"
using namespace std;

int main()
{
    PlataformaEducativa miPlataforma(50, 50);
    miPlataforma.agregarInstructor(new Instructor("Omar",      1, 2, true));
    miPlataforma.agregarInstructor(new Instructor("Diego",     2, 1, true));
    miPlataforma.agregarInstructor(new Instructor("Benjamin",  3, 3, true));
    miPlataforma.agregarInstructor(new Instructor("Gabriel",   4, 0, true));
    miPlataforma.agregarInstructor(new Instructor("Mauricio",  5, 6, false));

    
    miPlataforma.mostrarInstructoresOrdenados();

    
    miPlataforma.agregarCurso(new Curso(1, "Curso 1", 29));
    miPlataforma.agregarCurso(new Curso(2, "Curso 2", 30));
    miPlataforma.agregarCurso(new Curso(3, "Curso 3", 31));
    miPlataforma.agregarCurso(new Curso(4, "Curso 4", 32));
    miPlataforma.agregarCurso(new Curso(5, "Curso 5", 33));

    miPlataforma.asignarInstructores();

    
    
    miPlataforma.registrarEstudiante(1, new Estudiante("Ana Lopez",    "ana@mail.com"));
    miPlataforma.registrarEstudiante(1, new Estudiante("Carlos Ruiz",  "carlos@mail.com"));
    miPlataforma.registrarEstudiante(3, new Estudiante("Maria Quispe", "maria@mail.com"));
    miPlataforma.registrarEstudiante(99, new Estudiante("Juan Perez",  "juan@mail.com"));

    
    
    miPlataforma.finalizarCurso(1);
    miPlataforma.finalizarCurso(3);

    
    miPlataforma.mostrarInstructorConMasCursos();

    return 0;
}
