#include <iostream>
#include "PlataformaEducativa.h"

using namespace std;

int main() {
    PlataformaEducativa plataforma;

    cout << "=== REGISTRO DE INSTRUCTORES ===" << endl;
    plataforma.registrarInstructor("Carlos Perez", "123456");
    plataforma.registrarInstructor("Ana Gomez", "789012");
    plataforma.registrarInstructor("Luis Fernandez", "345678");

    cout << "\n=== MOSTRAR INSTRUCTORES ORDENADOS ===" << endl;
    plataforma.mostrarInstructoresOrdenadosPorCursos();

    cout << "\n=== REGISTRO DE CURSOS ===" << endl;
    plataforma.registrarCurso(101, "Matematica Basica", 3);
    plataforma.registrarCurso(102, "Programacion en C++", 2);
    plataforma.registrarCurso(103, "Estructuras de Datos", 2);

    cout << "\n=== REGISTRO DE ESTUDIANTES ===" << endl;
    plataforma.registrarEstudianteEnCurso(101, "Juan Rojas", "juan@mail.com");
    plataforma.registrarEstudianteEnCurso(101, "Maria Lozano", "maria@mail.com");
    plataforma.registrarEstudianteEnCurso(101, "Pedro Iglesias", "pedro@mail.com");
    plataforma.registrarEstudianteEnCurso(102, "Lucia Mendez", "lucia@mail.com");
    plataforma.registrarEstudianteEnCurso(103, "Roberto Diaz", "roberto@mail.com");

    cout << "\n=== FINALIZAR CURSO 101 ===" << endl;
    plataforma.finalizarCurso(101);

    cout << "\n=== REGISTRAR NUEVO CURSO ===" << endl;
    plataforma.registrarCurso(104, "Base de Datos", 2);

    cout << "\n=== MOSTRAR INSTRUCTOR CON MÁS CURSOS ===" << endl;
    plataforma.mostrarInstructorConMasCursos();

    cout << "\n=== MOSTRAR INSTRUCTORES ORDENADOS FINAL ===" << endl;
    plataforma.mostrarInstructoresOrdenadosPorCursos();

    return 0;
}