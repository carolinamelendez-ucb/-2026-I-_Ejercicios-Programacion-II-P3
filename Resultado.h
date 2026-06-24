#pragma once
#include <iostream>
#include <string>
#include "Examen.h"
using namespace std;

class Resultado {
private:
	string matriculaEstudiante;
	Examen* examen;
	double puntajeObtenido;
	string estado;
	string fechaRendido;

public:
	Resultado(const string& matriculaEstudiante, Examen* examen)
		: matriculaEstudiante(matriculaEstudiante), examen(examen),
		puntajeObtenido(0), estado("EN_CURSO"), fechaRendido("")
	{
	}

	void sumarPuntaje(double puntaje) {
		puntajeObtenido = puntajeObtenido + puntaje;
	}

	void finalizar() {
		double maximo = examen->getPuntajeMaximo();
		if (puntajeObtenido >= maximo * 0.6) {
			estado = "APROBADO";
		}
		else {
			estado = "REPROBADO";
		}
		fechaRendido = "2026-06-10";
	}

	double getPuntajeObtenido() {
		return puntajeObtenido;
	}
	string getEstado() {
		return estado;
	}
	Examen* getExamen() {
		return examen;
	}
	string getMatriculaEstudiante() {
		return matriculaEstudiante;
	}
	string getFechaRendido() {
		return fechaRendido;
	}

	static bool compararExamen(int idExamen, Resultado* resultadoComparado) {
		return idExamen == resultadoComparado->examen->getId();
	}
};