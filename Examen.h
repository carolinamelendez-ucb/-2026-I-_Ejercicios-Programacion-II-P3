#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Pregunta.h"
#include "Excepciones.h"
using namespace std;

class Examen {
private:
	int id;
	string titulo;
	string docente;
	int duracionMinutos;
	LinkedList<Pregunta>* preguntas;

public:
	Examen(int id, const string& titulo, const string& docente, int duracionMinutos)
		: id(id), titulo(titulo), docente(docente), duracionMinutos(duracionMinutos)
	{
		this->preguntas = new LinkedList<Pregunta>();
	}

	void agregarPregunta(Pregunta* nuevaPregunta) {
		if (preguntas->buscarBool(nuevaPregunta->getEnunciado(), Pregunta::compararEnunciado)) {
			throw PreguntaDuplicadaException(nuevaPregunta->getEnunciado());
		}
		if (preguntas->contar() >= 20) {
			throw LimitePreguntasException(id);
		}
		preguntas->agregar(nuevaPregunta);
	}

	Pregunta* buscarPregunta(string codigo) {
		return preguntas->buscar(codigo, Pregunta::compararCodigo);
	}

	double getPuntajeMaximo() {
		double total = 0;
		int cantidad = preguntas->contar();
		for (int i = 0; i < cantidad; i++) {
			total = total + preguntas->obtenerPorIndice(i)->getPuntaje();
		}
		return total;
	}

	int getId() {
		return id;
	}
	string getTitulo() {
		return titulo;
	}
	string getDocente() {
		return docente;
	}
	int getDuracionMinutos() {
		return duracionMinutos;
	}
	int getCantidadPreguntas() {
		return preguntas->contar();
	}

	static bool compararId(int id, Examen* examenComparado) {
		return id == examenComparado->id;
	}
	static bool compararTitulo(string titulo, Examen* examenComparado) {
		return titulo == examenComparado->titulo;
	}
};