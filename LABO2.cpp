#include <iostream>
#include "DocenteMedioTiempo.h"
#include "DocenteTiempoCompleto.h"
#include "EstudiantePostgrado.h"
#include "EstudiantePregrado.h"
#include "SistemaUniversidad.h"
using namespace std;

int main()
{
    SistemaUniversidad sistema(20, 20, 20);
    sistema.agregarEstudiante(new EstudiantePostgrado(1, "Diego", 300, true));
    sistema.agregarEstudiante(new EstudiantePostgrado(2, "Mauricio", 300, true));
    sistema.agregarEstudiante(new EstudiantePregrado(3, "Omar", 300, true));
    sistema.agregarEstudiante(new EstudiantePregrado(4, "Benjamin", 300, true));
    sistema.agregarEstudiante(new EstudiantePostgrado(5, "Mariana", 300, true));
    sistema.agregarEstudiante(new EstudiantePostgrado(6, "Gabriel", 300, false));
    sistema.agregarEstudiante(new EstudiantePregrado(1, "Alisa", 300, true));

    sistema.agregarDocente(new DocenteMedioTiempo(7, "Gonzalo", 1000, true));
    sistema.agregarDocente(new DocenteMedioTiempo(8, "Francisco", 2000, true));
    sistema.agregarDocente(new DocenteMedioTiempo(9, "Diego", 3000, true));
    sistema.agregarDocente(new DocenteTiempoCompleto(10, "Brenda", 6000, 7, true));
    sistema.agregarDocente(new DocenteTiempoCompleto(11, "Gemio", 1500, 15, true));

    sistema.agregarCurso(new Curso(123, 10));
    sistema.agregarCurso(new Curso(124, 10));
    sistema.agregarCurso(new Curso(125, 10));
    sistema.agregarCurso(new Curso(126, 10));
    sistema.agregarCurso(new Curso(127, 10));
    sistema.agregarCurso(new Curso(128, 10));
    sistema.agregarCurso(new Curso(129, 10));
    sistema.agregarCurso(new Curso(110, 10));
    sistema.agregarCurso(new Curso(123, 10));

    sistema.asignarDocenteACurso(7, 123);
    sistema.asignarDocenteACurso(8, 124);
    sistema.asignarDocenteACurso(9, 125);
    sistema.asignarDocenteACurso(10, 126);
    sistema.asignarDocenteACurso(11, 127);
    sistema.asignarDocenteACurso(11, 128);
    sistema.asignarDocenteACurso(11, 129);


    sistema.mostrarEstudianteMasPaga();
    sistema.mostrarDocenteMenosCobra();
    sistema.mostrarTodo();
}
