#include <iostream>
#include <string>
#include "UniversidadSistema.h"
#include "Pregrado.h"
#include "Postgrado.h"
#include "TiempoCompleto.h"
#include "MedioTiempo.h"

using namespace std;

int main() {
	UniversidadSistema sistema(100, 60, 20);

	sistema.registrarEstudiante(new Prepago("123", "Carlos"));
	sistema.registrarEstudiante(new Postgrado("124", "Lucia", 2000));

	sistema.registrarDocente(new TiempoCompleto("789", "Dania", 4));
	sistema.registrarDocente(new MedioTiempo("1012", "Rosa"));

	sistema.registrarCurso(new Curso("A1", 45));
	sistema.registrarCurso(new Curso("B2", 30));

	sistema.asignarDocenteACurso("789", "A1");
	sistema.asignarDocenteACurso("1012", "B2");

	sistema.asignarEstudianteACurso("123", "A1");
	sistema.asignarEstudianteACurso("124", "B2");

	sistema.mostrarListaEstudiantes();
	cout << endl;

	sistema.mostrarListaDocentes();
	cout << endl;
	sistema.mostrarEstudianteQueMasPaga();
	sistema.mostrarDocenteQueMenosGana();

}