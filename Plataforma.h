#pragma once
#include "LinkedList.h"
#include "Estudiante.h"
#include "Examen.h"
#include "Excepciones.h"



class Plataforma {
private:
	string nombreApp;
	LinkedList<Estudiante>* estudiantes;
	LinkedList<Examen>* examenes;
public:
	Plataforma(string nom) {
		this->nombreApp = nom;
		this->estudiantes =new LinkedList<Estudiante>();
		this->examenes =new LinkedList<Examen>();
	}

	//1

	void registrarEstudiante(Estudiante* nvoEstudiante) {
		Estudiante* estu = estudiantes->buscar(nvoEstudiante->getMatricula(), Estudiante::compararMAT);
		if (estu!=nullptr) {
			throw EstudianteDuplicadoException(nvoEstudiante->getMatricula());
		}
		estudiantes->agregar(nvoEstudiante);
	}

	//2

	void registrarExamen(Examen* nvoExamen) {
		Examen* exam = examenes->buscar(nvoExamen->getID(), Examen::compararIdEXAM);
		if (exam != nullptr) {
			throw ExamenDuplicadoException(nvoExamen->getID());
		}
		examenes->agregar(nvoExamen);
	}

	//3

	void agregarNvaPregunta(int idExam, Pregunta* tipoPregunta) {
		Examen* ex = examenes->buscar(idExam, Examen::compararIdEXAM);
		if (ex == nullptr) {
			throw ExamenNoExistenteException(idExam);
		}

		//Pregunta* prg=tipoPregunta

		if () {
		//	throw PreguntaDuplicadaException(tipoPregunta->getCodigo());
		}

		int cantidad = 0;
		if(cantidad<=20){
			ex->agregarPregunta(tipoPregunta);
			cantidad++;
		}

	}

	//5

	void iniciarExamen(int matricula,int idExam) {
		Estudiante* estu = estudiantes->buscar(matricula, Estudiante::compararMAT);
		if (estu==nullptr) {
			throw EstudianteNoExistenteException(matricula);
		}

		Examen* exa = examenes->buscar(idExam, Examen::compararIdEXAM);
		if (exa == nullptr) {
			throw ExamenNoExistenteException(idExam);
		}
	}

	//4

	void responderPregunta(int matricula, int idExam,string codigoPregunta, string respuesta) {
		Estudiante* estu = estudiantes->buscar(matricula, Estudiante::compararMAT);
		if (estu == nullptr) {
			throw EstudianteNoExistenteException(matricula);
		}

		Examen* ex = examenes->buscar(idExam, Examen::compararIdEXAM);
		if (ex == nullptr) {
			throw ExamenNoExistenteException(idExam);
		}

		
		


	}


	//6

	void finalizarExamen(int matricula,int idExam) {
		Estudiante* estu = estudiantes->buscar(matricula, Estudiante::compararMAT);
		if (estu == nullptr) {
			throw EstudianteNoExistenteException(matricula);
		}

		Examen* ex = examenes->buscar(idExam, Examen::compararIdEXAM);
		if (ex==nullptr) {
			throw ExamenNoExistenteException(idExam);
		}


	}

	//7

	void obtenerResultadosDeUnEstudiante(int matricula) {
		Estudiante* estu = estudiantes->buscar(matricula, Estudiante::compararMAT);
		if (estu == nullptr) {
			throw EstudianteNoExistenteException(matricula);
		}




	}

	//8

	void mostrarPorcentajeEstudiantesAprobados(int idExam) {
		Examen* ex = examenes->buscar(idExam, Examen::compararIdEXAM);
		if (ex == nullptr) {
			throw ExamenNoExistenteException(idExam);
		}

	}


	void mostrarEstudiantes() {
		estudiantes->mostrar();
	}

	void mostrarExamenes() {
		examenes->mostrar();
	}

	//9
	void ordenarEstudiantesPorEdad_Mayor_Menor() {
		estudiantes->ordenar(Estudiante::ordenarEdadAsc);
		estudiantes->mostrar();
	}

};