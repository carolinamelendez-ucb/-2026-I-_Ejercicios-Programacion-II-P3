#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pregunta {
protected:
	string codigo;
	string enunciado;
	int puntaje;
	string nivelDificultad;
public:
	Pregunta(string codigo, const string& enunciado, int puntaje, const string& nivelDificultad)
		: codigo(codigo), enunciado(enunciado), puntaje(puntaje), nivelDificultad(nivelDificultad)
	{}

	string getCodigo() {
		return codigo;
	}

	int getPuntaje() {
		return puntaje;
	}


	virtual void mostrar()= 0;

	virtual double corregir(string respuesta) = 0;



	static bool compararCOD(string cod, Pregunta* p) {
		return cod == p->codigo;
	}

	~Pregunta(){}
};