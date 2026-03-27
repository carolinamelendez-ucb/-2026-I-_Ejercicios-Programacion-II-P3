// TAREA1703FINAL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "PlataformaEducativa.h"
using namespace std;

int main()
{
	PlataformaEducativa miPlataforma(6, 3);

	miPlataforma.registrarInstructores(new Instructor("Luciana", 1, 3));
	miPlataforma.registrarInstructores(new Instructor("Luis", 2));
	miPlataforma.registrarInstructores(new Instructor("Ana", 3, 4));

	miPlataforma.mostrarInstrcutores();
	cout << endl;
	miPlataforma.registrarCursos(11, "Matematica", 5);
	miPlataforma.registrarCursos(22, "Biologia", 2);
	miPlataforma.registrarCursos(33, "Filosofia", 3);
	miPlataforma.registrarCursos(44, "Fisica", 7);
	miPlataforma.registrarCursos(55, "Lenguaje", 10);
	miPlataforma.registrarCursos(66, "Ingles", 4);


	miPlataforma.registrarEstudiantes(33, "Dani", "dani@gamil.com");
	miPlataforma.registrarEstudiantes(33, "Sol", "sol@gamil.com");
	miPlataforma.registrarEstudiantes(33, "Darian", "darian@gamil.com");
	miPlataforma.registrarEstudiantes(11, "Lucas", "lucas@gamil.com");
	miPlataforma.registrarEstudiantes(11, "Juan", "juan@gamil.com");
	miPlataforma.mostrarCursos();
	cout << endl;
	cout << "Cursos finalizan 1" << endl;
	cout << endl;
	miPlataforma.finalizarCurso(33);
	miPlataforma.mostrarCursos();

	cout << endl;
	cout << "Instructor con mayor Cantidad de Cursos Realizados: " << endl;
	miPlataforma.InstructorMayorCantidadCursos();
}

