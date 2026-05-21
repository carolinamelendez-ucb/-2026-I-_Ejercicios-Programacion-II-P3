#pragma once
#include "Estudiante.h"
#include "Curso.h"
#include "Inscripcion.h"
#include "Excepciones.h"
#include "LinkedList.h"

class SistemaAcademico {
private:
	string nombreInstitucion;
	LinkedList<Curso>* listaCursos;
	LinkedList<Estudiante>* listaEstudiantes;
	LinkedList<Inscripcion>* listaInscripciones;
public:
	SistemaAcademico(const string& nombreInstitucion)
		: nombreInstitucion(nombreInstitucion), listaCursos(new LinkedList<Curso>()), listaEstudiantes(new LinkedList<Estudiante>()), listaInscripciones(new LinkedList<Inscripcion>())
	{
	}
	void registrarCurso(Curso* nuevoCurso) {
		Curso* cursoDuplicado = listaCursos->buscar(nuevoCurso->getCodigo(), Curso::compararCodigo);
		if (cursoDuplicado != nullptr) { 
			throw CursoDuplicadoException();
		}
		if (nuevoCurso->getCapMaxima() <= 0 || nuevoCurso->getCapMaxima() > 30) { //No se tenia igual a 0 y era mayor a 100 en lugar de a 30
			throw CupoInvalidoException();
		}
		listaCursos->agregar(nuevoCurso);
	}
	void registrarEstudiante(Estudiante* nuevoEstudiante) {
		Estudiante* estudianteDuplicado = listaEstudiantes->buscar(nuevoEstudiante->getCI(), Estudiante::compararCI);
		if (estudianteDuplicado != nullptr) {
			throw EstudianteDuplicadoException();
		}
		listaEstudiantes->agregar(nuevoEstudiante);
	}
	void registrarInscripcion(Inscripcion* nuevaInscripcion, int ci, string modalidad) { //PARA TEST 13: No se tiene la excepcion de limite de inscripciones ni el la clase actual, en la clase estudiante tampoco se cuenta con un atributo que controle la cantidad de cursos actuales inscritos, todo eso se agrego
		Estudiante* estudianteBuscado = listaEstudiantes->buscar(ci, Estudiante::compararCI);
		Curso* cursoBuscado = listaCursos->buscarMayor(modalidad, Curso::compararModalidad, Curso::mayorCupos); //PARA TEST 14: Como se debe asignar el curso con mayor cupo disponible, se tiene que buscar el tipo de curso y a su vez guardar el que tenga mas cupos, por lo que en linked list se agregara ese nuevo metodo
		if (estudianteBuscado == nullptr) { //Se lanza la excepcion cuando el estudiante buscado no haya sido encontrado, osea == nullptr
			throw EstudianteNoEncontradoException();
		}
		if (cursoBuscado == nullptr || cursoBuscado->getCupos() <= 0) { //el cupo debe ser menor o igual a 0, no solo debe ser menor
			throw SinCursosDisponiblesException();
		}
		if (estudianteBuscado->getCantCursos() >= 3) { //PARA TEST 13: se agrego la condicion y la excepcion
			throw LimiteInscripcionesException();
		}
		nuevaInscripcion->asignarCurso(cursoBuscado);
		nuevaInscripcion->asignarEstudiante(estudianteBuscado);
		listaInscripciones->agregar(nuevaInscripcion);
		cursoBuscado->disminuirCupos();
	}
	void cancelarInscripcion(int ci, string codigo) {
		Inscripcion* incripcionBuscada = listaInscripciones->buscarDoble(ci, codigo, Inscripcion::compararInscripcion);
		if (incripcionBuscada == nullptr) {
			throw InscripcionNoEncontradaException();
		}
		if (incripcionBuscada->getEstado() == "CANCELADA") { //La excepcion de lanza cuando el estado de la inscripcion es CANCELADA, no ACTIVA
			throw InscripcionYaCanceladaException();
		}
		incripcionBuscada->cancelada();
	}
	void buscarYmostrar(int ci) {
		Estudiante* estudianteBuscado = listaEstudiantes->buscar(ci, Estudiante::compararCI);
		estudianteBuscado->mostrar();
	}
};
