#pragma once
#include <iostream>
#include <string>
#include "Examen.h"
using namespace std;

class Resultado {
private:
	int matriculaEstudiante;
	Examen* examen;
	double puntajeObtenido;
	string estado;
	string fechaRendido;
public:
	Resultado(int matriculaEstudiante, Examen* examen, double puntajeObtenido, const string& estado, const string& fechaRendido)
		: matriculaEstudiante(matriculaEstudiante), examen(examen), puntajeObtenido(puntajeObtenido), estado(estado), fechaRendido(fechaRendido)
	{
	}

	int getMatriculaEstudiante() {
		return matriculaEstudiante;
	}

	double getPuntajeObtenido() {
		return puntajeObtenido;
	}

	static bool puntajeEstudiante(int matricula,Resultado* r) {
		return matricula==r->matriculaEstudiante;
	}


	static bool compararPuntajeAsc(Resultado* a, Resultado* b) {
		return a->puntajeObtenido > b->puntajeObtenido;
	}


	static bool compararPuntajeDes(Resultado* a,Resultado* b) {
		return a->puntajeObtenido < b->puntajeObtenido;
	}

	void mostrar() {
		cout << "Fecha:" << fechaRendido << endl;
		cout << "Matricula:" << matriculaEstudiante << endl;
		cout << "Puntaje Obtenido:" << puntajeObtenido << endl;
	}

	~Resultado() {
		delete examen;
	}

};