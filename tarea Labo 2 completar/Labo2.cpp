#include <iostream>
#include <string>

#include "Universidad.h"
#include "EstudiantePregrado.h"
#include "EstudiantePostgrado.h"
#include "DocenteTiempoCompleto.h"
#include "DocenteMedioTiempo.h"
#include "Curso.h"

using namespace std;

int main()
{
    Universidad uni = Universidad(20, 10);

    cout << "=== REGISTRO DE ESTUDIANTES ===" << endl;
    uni.registrarEstudiante(new EstudiantePregrado(111, "Carlos Perez", "carlos@mail.com"));
    uni.registrarEstudiante(new EstudiantePregrado(222, "Ana Lopez", "ana@mail.com"));
    uni.registrarEstudiante(new EstudiantePostgrado(333, "Maria Gomez", "maria@mail.com"));
    uni.registrarEstudiante(new EstudiantePostgrado(444, "Luis Fernandez", "luis@mail.com"));

    cout << "\n=== REGISTRO DE DOCENTES ===" << endl;
    uni.registrarDocente(new DocenteTiempoCompleto(555, "Jose Ramirez", "jose@mail.com", 2000, 8));
    uni.registrarDocente(new DocenteMedioTiempo(666, "Laura Torres", "laura@mail.com", 1500, 3));
    uni.registrarDocente(new DocenteTiempoCompleto(777, "Pedro Castro", "pedro@mail.com", 2500, 12));
    uni.registrarDocente(new DocenteTiempoCompleto(888, "Roberto Soto", "roberto@mail.com", 1800, 4));

    cout << "\n=== REGISTRO DE CURSOS ===" << endl;
    uni.registrarCurso(new Curso("C101", "Matematica Basica", 100, 3));
    uni.registrarCurso(new Curso("C102", "Fisica General", 120, 3));
    uni.registrarCurso(new Curso("C103", "Programacion", 150, 2));
    uni.registrarCurso(new Curso("C104", "Quimica", 130, 3));

    cout << "\n=== ASIGNAR DOCENTES A CURSOS ===" << endl;
    uni.asignarDocenteACurso(555, "C101");
    uni.asignarDocenteACurso(666, "C102");
    uni.asignarDocenteACurso(777, "C103");

    cout << "\n=== ASIGNAR ESTUDIANTES A CURSOS ===" << endl;
    uni.asignarEstudianteACurso(111, "C101");
    uni.asignarEstudianteACurso(222, "C101");
    uni.asignarEstudianteACurso(333, "C101");

    uni.asignarEstudianteACurso(333, "C102");
    uni.asignarEstudianteACurso(444, "C102");
    uni.asignarEstudianteACurso(111, "C102");

    uni.asignarEstudianteACurso(222, "C103");

    uni.mostrarEstudiantes();
    uni.mostrarDocentes();
    uni.mostrarCursos();
    uni.mostrarTotalGeneral();
    uni.mostrarEstudianteQueMasPaga();
    uni.mostrarCursoMasEconomico();

    return 0;
}