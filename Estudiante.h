#pragma once
#include <iostream>
#include <string>
using namespace std;

class Estudiante {
protected:
	int ci;
	string nombre;
	string tipo;
	int matricula;
	int cantidadCursos;
	bool pagoMatricula;
public:
	Estudiante(int ci, const string& nombre, int matricula, const string& tipo, bool pago)
		: ci(ci), nombre(nombre), matricula(matricula), cantidadCursos(0), tipo(tipo), pagoMatricula(pago)
	{
	}
	int getCi() { return ci; }
	bool getPagoMatricula() { return matricula; }

	virtual void mostrar() {
		cout << "Ci: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Matricula: " << matricula << endl;
	}
	virtual float costoTotal() {
		return matricula * cantidadCursos;
	}

	void aumentarCantidadCursos() {
		cantidadCursos++;
	}
};