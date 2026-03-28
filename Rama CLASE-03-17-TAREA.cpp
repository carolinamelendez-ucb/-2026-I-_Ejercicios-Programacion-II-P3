// Rama CLASE-03-17-TAREA.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "VectorInstructores.h"
#include "VectorClases.h"



class PlataformaEducativa {
private:
    VectorInstructores* listaInstructores;
    VectorCursos* listaClases;
public:
    PlataformaEducativa(int tamanioInstructores, int tamanioClases) {
        this->listaInstructores = new VectorInstructores(tamanioInstructores);
        this->listaClases = new VectorCursos(tamanioClases);
    }

    //1
    void agregarInstructor(Instructor* nuevoInstructor) {
        listaInstructores->agregarInstructor(nuevoInstructor);
        listaInstructores->ordenamientoPorCursos();
    }
    
    //2
    void registrarCurso(Curso* nuevoCurso) {
        Instructor* aux = listaInstructores->comprobarDisponibilidad();
        if (aux != nullptr) {
            nuevoCurso->asignarInstructor(aux);
            listaClases->agregarCurso(nuevoCurso);
        }
    }

    //3
    void registrarEstudianteACurso(int id, Estudiante* nuevoEstudiante) {
        listaClases->asignarEstudianteACurso(id, nuevoEstudiante);
    }

    //4
    void finalizarCurso(int id) {
        listaClases->finalizarCurso(id);
    }

    //5
    void instructorConMayorCurso() {
        listaInstructores->buscarAlInstructorConMayorCursos();
    }


    void mostrarInstructores() {
        listaInstructores->mostrar();
    }

    void mostrarCursos() {
        listaClases->mostrar();
    }
};

int main()
{

    PlataformaEducativa* plataforma = new PlataformaEducativa(20, 20);

    //1
    plataforma->agregarInstructor(new Instructor("Alan", 123, 6, true));
    plataforma->agregarInstructor(new Instructor("Fabian", 145, 4, false));
    plataforma->agregarInstructor(new Instructor("Jorge", 214, 7, true));
    plataforma->agregarInstructor(new Instructor("Jona", 546, 1, true));
    //plataforma->mostrarInstructores();


    cout << endl;
    cout << endl;
    cout << endl;
    //2
    plataforma->registrarCurso(new Curso(123, "Costos", 10));
    plataforma->registrarCurso(new Curso(456, "Pogramacion II", 5));
    // plataforma->mostrarCursos();
    // plataforma->mostrarInstructores();

    //3
    plataforma->registrarEstudianteACurso(123, new Estudiante("Sebas", "sebas@gmail.com"));
    plataforma->registrarEstudianteACurso(123, new Estudiante("Kiko", "Kiko@gmail.com"));
    plataforma->registrarEstudianteACurso(456, new Estudiante("Alan", "alan@gmail.com"));
    plataforma->registrarEstudianteACurso(176, new Estudiante("Brayan", "brayan@gmail.com"));
    plataforma->registrarEstudianteACurso(456, new Estudiante("chavo", "chavo@gmail.com"));
    //plataforma->mostrarCursos();

    //4
    plataforma->finalizarCurso(123);
    plataforma->mostrarInstructores();

    //5
    plataforma->instructorConMayorCurso();



}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
