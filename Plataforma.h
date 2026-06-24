#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Estudiante.h"
#include "Examen.h"
#include "Resultado.h"
#include "Pregunta.h"
#include "Excepciones.h"
using namespace std;

class Plataforma {
private:
	string nombreApp;
	LinkedList<Estudiante>* estudiantes;
	LinkedList<Examen>* examenes;

	Estudiante* obtenerEstudiante(string matricula) {
		Estudiante* aux = estudiantes->buscar(matricula, Estudiante::compararMatricula);
		if (aux == nullptr) {
			throw EstudianteNoEncontradoException(matricula);
		}
		return aux;
	}
	Examen* obtenerExamen(int idExamen) {
		Examen* aux = examenes->buscar(idExamen, Examen::compararId);
		if (aux == nullptr) {
			throw ExamenNoEncontradoException(idExamen);
		}
		return aux;
	}

public:
	Plataforma(const string& nombreApp)
		: nombreApp(nombreApp)
	{
		this->estudiantes = new LinkedList<Estudiante>();
		this->examenes = new LinkedList<Examen>();
	}

	// 1. Registrar un estudiante
	void registrarEstudiante(Estudiante* nuevoEstudiante) {
		if (estudiantes->buscarBool(nuevoEstudiante->getMatricula(), Estudiante::compararMatricula)) {
			throw EstudianteDuplicadoException(nuevoEstudiante->getMatricula());
		}
		estudiantes->agregar(nuevoEstudiante);
	}

	// 2. Registrar un examen
	void registrarExamen(Examen* nuevoExamen) {
		if (examenes->buscarBool(nuevoExamen->getTitulo(), Examen::compararTitulo)) {
			throw ExamenDuplicadoException(nuevoExamen->getTitulo());
		}
		examenes->agregar(nuevoExamen);
	}

	// 3. Agregar una pregunta completa a un examen
	void agregarPregunta(int idExamen, Pregunta* nuevaPregunta) {
		Examen* examen = obtenerExamen(idExamen);
		examen->agregarPregunta(nuevaPregunta);
	}

	// 5. Iniciar un examen (crea el resultado en curso)
	void iniciarExamen(string matricula, int idExamen) {
		Estudiante* estudiante = obtenerEstudiante(matricula);
		Examen* examen = obtenerExamen(idExamen);
		Resultado* resultado = new Resultado(matricula, examen);
		estudiante->agregarResultado(resultado);
	}

	// 4. Responder una pregunta
	void responderPregunta(string matricula, int idExamen, string codigoPregunta, string respuesta) {
		Estudiante* estudiante = obtenerEstudiante(matricula);
		Examen* examen = obtenerExamen(idExamen);
		Pregunta* pregunta = examen->buscarPregunta(codigoPregunta);
		if (pregunta == nullptr) {
			throw PreguntaNoEncontradaException(codigoPregunta);
		}
		Resultado* resultado = estudiante->buscarResultado(idExamen);
		resultado->sumarPuntaje(pregunta->obtenerPuntaje(respuesta));
	}

	// 6. Finalizar un examen
	void finalizarExamen(string matricula, int idExamen) {
		Estudiante* estudiante = obtenerEstudiante(matricula);
		obtenerExamen(idExamen);
		Resultado* resultado = estudiante->buscarResultado(idExamen);
		resultado->finalizar();
	}

	Resultado* obtenerResultado(string matricula, int idExamen) {
		Estudiante* estudiante = obtenerEstudiante(matricula);
		return estudiante->buscarResultado(idExamen);
	}

	// 7. Consultar resultados de un estudiante
	int consultarResultados(string matricula) {
		Estudiante* estudiante = obtenerEstudiante(matricula);
		if (estudiante->contarResultadosFinalizados() == 0) {
			throw SinResultadosException(matricula);
		}
		return estudiante->contarResultadosFinalizados();
	}

	// 8. Porcentaje de estudiantes aprobados en un examen
	double porcentajeAprobados(int idExamen) {
		obtenerExamen(idExamen);
		int finalizaron = estudiantes->contarCriterio(idExamen, Estudiante::finalizoExamen);
		int aprobados = estudiantes->contarCriterio(idExamen, Estudiante::aproboExamen);
		if (finalizaron == 0) {
			return 0.0;
		}
		return ((double)aprobados / (double)finalizaron) * 100.0;
	}

	// 9. Mostrar resultados de un estudiante ordenados descendente por puntaje
	void mostrarResultadosOrdenados(string matricula) {
		Estudiante* estudiante = obtenerEstudiante(matricula);
		LinkedList<Resultado>* lista = estudiante->getResultados();
		int n = lista->contar();

		cout << "Resultados de " << estudiante->getNombre()
			<< " (ordenados por puntaje desc):" << endl;

		bool* visitado = new bool[n];
		for (int i = 0; i < n; i++) visitado[i] = false;

		for (int k = 0; k < n; k++) {
			int indiceMayor = -1;
			double mayorPuntaje = -1;
			for (int i = 0; i < n; i++) {
				if (!visitado[i]) {
					double p = lista->obtenerPorIndice(i)->getPuntajeObtenido();
					if (p > mayorPuntaje) {
						mayorPuntaje = p;
						indiceMayor = i;
					}
				}
			}
			visitado[indiceMayor] = true;
			Resultado* r = lista->obtenerPorIndice(indiceMayor);
			cout << " - Examen: " << r->getExamen()->getTitulo()
				<< " | Puntaje: " << r->getPuntajeObtenido()
				<< " | Estado: " << r->getEstado() << endl;
		}
		delete[] visitado;
	}

	int getCantidadEstudiantes() {
		return estudiantes->contar();
	}
	int getCantidadExamenes() {
		return examenes->contar();
	}
	string getNombreApp() {
		return nombreApp;
	}
};