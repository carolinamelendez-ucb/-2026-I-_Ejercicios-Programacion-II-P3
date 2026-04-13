#include <iostream>
#include <string>
#include "Sistema.h"
#include "Pregrado.h"
#include "Postgrado.h"
#include "TiempoCompleto.h"
#include "MedioTiempo.h"
using namespace std;

int main()
{
    Sistema sistema(100, 60, 20);
    Estudiante* e1 = new Pregrado(123, "Carlos");
    Estudiante* e2 = new Postgrado(456, "Ana", 200);
    e1->pagar();
    e2->pagar();
    sistema.registrarEstudiante(e1);
    sistema.registrarEstudiante(e2);
    Docente* d1 = new MedioTiempo(789, "Pablo", 3000);
    Docente* d2 = new TiempoCompleto(101, "Maria", 5000, 8);
    d1->aprobar();
    d2->aprobar();
    sistema.registrarDocente(d1);
    sistema.registrarDocente(d2);
    sistema.registrarCurso(new Curso(1011, 10));
    sistema.registrarCurso(new Curso(1011, 15)); 
    sistema.asignarDocenteCurso(789, 1011);
    sistema.asignarEstudianteCurso(123, 1011);
    sistema.asignarEstudianteCurso(456, 1011);
    sistema.mostrarEstudiantes();
    sistema.mostrarDocentes();
    sistema.totalRecaudado();
    sistema.estudianteMayorPago();
    sistema.docenteMenorSalario();
}
