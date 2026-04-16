// Practica Exa.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "VectorCursos.h"
#include "VectorDocentes.h"
#include "VectorEstudiantes.h"

class SistemaCursos {
private:
    VectorCursos* listaCursos;
    VectorDocentes* listaDocentes;
    VectorEstudiantes* listaEstudiantes;
public:
    SistemaCursos(int tamCursos, int tamDocentes, int tamEstudiantes) {
        this->listaCursos = new VectorCursos(tamCursos);
        this->listaDocentes = new VectorDocentes(tamDocentes);
        this->listaEstudiantes = new VectorEstudiantes(tamEstudiantes);
    }

    void agregarEstudiante(Estudiante* nuevoEstudiante) {
        Estudiante* aux = listaEstudiantes->buscarCiDuplicado(nuevoEstudiante->getCi());
        if (aux == nullptr) {
            listaEstudiantes->agregarEstudiante(nuevoEstudiante);
        }
    }
    void agregarDocente(Docente* nuevoDocente) {
        Docente* aux = listaDocentes->buscarCiDuplicado(nuevoDocente->getCi());
        if (aux == nullptr) {
            listaDocentes->agregarDocente(nuevoDocente);
        }
    }
    void agregarCurso(Curso* nuevoCurso) {
        Curso* aux = listaCursos->buscarCodigoDuplicado(nuevoCurso->getCodigo());
        if (aux == nullptr) {
            listaCursos->agregarCurso(nuevoCurso);
        }
    }

    void asignarDocenteACurso(int ci, int codigo) {
        Curso* aux = listaCursos->buscarCodigoDuplicado(codigo);
        Docente* docenteAsigando = listaDocentes->buscarCiDuplicado(ci);
        if (aux != nullptr) {
            if (docenteAsigando != nullptr && docenteAsigando->getEstado() == true) {
                aux->agregarDocente(docenteAsigando);
                docenteAsigando->actualizarCursos();
            }
        }
    }
    void asignarEstudianteACurso(int ci, int codigo) {
        Curso* aux = listaCursos->buscarCodigoDuplicado(codigo);
        Estudiante* estudianteAsigando = listaEstudiantes->buscarCiDuplicado(ci);
        if (aux != nullptr) {
            if (estudianteAsigando != nullptr && estudianteAsigando->getEstado() == true) {
                aux->agregarEstudianteACurso(estudianteAsigando);
            }
        }
    }

    void ActualizarTotales() {
        listaEstudiantes->actualizarPagosEstudiantes();
        listaDocentes->actualizarPagosDocentes();
    }
    
    void masPaga() {
        listaEstudiantes->masPaga();
    }



    void mostrarEstudiantes() {
        listaEstudiantes->mostrar();

    }
    void mostrarDocentes() {
        listaDocentes->mostrar();

    }
    void mostrarCursos() {
        listaCursos->mostrar();

    }


};


int main()
{
    SistemaCursos* sistema = new SistemaCursos(10, 10, 10);
    sistema->agregarEstudiante(new Pregrado("Alan", 1, true));
    sistema->agregarEstudiante(new Pregrado("Jorge", 1, false));
    sistema->agregarEstudiante(new Postgrado("Sebas",2,1500,true));
    sistema->agregarEstudiante(new Postgrado("Jona",3,3500,false));
    //sistema->mostrarEstudiantes();
    sistema->agregarDocente(new TiempoCompleto("Kiko", 3, 4000, 5, true));
    sistema->agregarDocente(new MedioTiempo("Lola",2,3000,4,true));
    sistema->agregarDocente(new MedioTiempo("jasb", 1, 2000, 4, true));
    sistema->agregarDocente(new MedioTiempo("Mish", 3, 3000, 4, false));
    //sistema->mostrarDocentes();
    sistema->agregarCurso(new Curso("Progra II", 1, 5));
    sistema->agregarCurso(new Curso("Calculo", 2, 5));
    sistema->agregarCurso(new Curso("Redes", 1, 5));
    //sistema->mostrarCursos();
    sistema->asignarDocenteACurso(1, 2);
    //sistema->mostrarCursos();
    sistema->asignarEstudianteACurso(1, 2);
    sistema->asignarEstudianteACurso(2, 2);
   // sistema->mostrarCursos();

    sistema->ActualizarTotales();
    //sistema->mostrarEstudiantes();
    //sistema->mostrarDocentes();

    sistema->masPaga();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
