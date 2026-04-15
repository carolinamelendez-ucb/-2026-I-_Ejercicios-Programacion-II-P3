
#include <iostream>
#include <string>
#include "DocenteMedioTiempo.h"
#include "DocenteTiempoCompleto.h"
#include "EstudiantePostgrado.h"
#include "EstudiantePregrado.h"
#include "UniversidadSitema.h"
using namespace std;

int main()
{
    UniversidadSistema sistema = UniversidadSistema(30, 20, 60);
  
    sistema.agregarEstudiante(new EstudiantePostgrado("carlos", 123,true));
    sistema.agregarEstudiante(new EstudiantePregrado("felipe", 345,false));
    sistema.mostrarEstudiantes();
    cout << endl;

    sistema.agregarDocente(new DocenteMedioTiempo("pablito",3344,3,true));
    sistema.agregarDocente(new DocenteTiempoCompleto("jacinto",1212,8,true));
    sistema.mostrarDocentes();
    cout << endl;

    sistema.agregarCurso(new Curso(444, 10));
    sistema.agregarCurso(new Curso(222, 10));
   
    cout << endl;

 
    cout << endl;
    sistema.asignarDocente(3344, 444);
    sistema.asignarDocente(1212, 222);
 
    cout << endl;


    cout << endl;
    sistema.asignarEstudiantes(123, 444);
    sistema.asignarEstudiantes(345, 222);

    sistema.mostrarCursos();


    sistema.mostrarTotalRecaudado();
    sistema.mostrarEstudinateMasPaga();
    sistema.mostrarDocenteMenosPaga();
}

