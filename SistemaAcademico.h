#pragma once
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
		Curso* cursoDuplicado = listaCursos->buscar(nuevoCurso->getCodigo(), Curso::compararCodigo); // deberia ser getCodigo() no getModalidad()
		if (cursoDuplicado != nullptr) {
			throw CursoDuplicadoException();
		}
		if (nuevoCurso->getCapMaxima() <= 0 || nuevoCurso->getCapMaxima() > 30) {   // validaciones mala
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
	void registrarInscripcion(Inscripcion* nuevaInscripcion, int ci, string modalidad) {
		Estudiante* estudianteBuscado = listaEstudiantes->buscar(ci, Estudiante::compararCI);
		Curso* cursoBuscado = listaCursos->buscarMayor(modalidad, Curso::compararModalidad, Curso::compararMayorCupo);
		if (estudianteBuscado == nullptr) {
			throw EstudianteNoEncontradoException();
		}
		if (cursoBuscado == nullptr || cursoBuscado->getCupos() <= 0) {
			throw SinCursosDisponiblesException();
		}
		if (estudianteBuscado->getContInscripciones() >=3) {
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
		if (incripcionBuscada->getEstado() == "CANCELADA") { // no deberia decir activa
			throw InscripcionYaCanceladaException();
		}
		incripcionBuscada->cancelada();
		
	}
	void buscarYmostrar(int ci) {
		Estudiante* estudianteBuscado = listaEstudiantes->buscar(ci, Estudiante::compararCI);
		estudianteBuscado->mostrar();
	}
};