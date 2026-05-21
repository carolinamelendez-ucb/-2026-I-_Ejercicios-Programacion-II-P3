#pragma once
#include <iostream>
#include <string>
using namespace std;

class Curso {
private:
	string codigo;
	string nombreCurso;
	string modalidad;
	int capMaxima;
	int cantInscritos;
	int cupos;
public:
	Curso(const string& codigo, const string& nombreCurso, const string& modalidad, int capMaxima)
		: codigo(codigo), nombreCurso(nombreCurso), modalidad(modalidad), capMaxima(capMaxima), cantInscritos(0), cupos(capMaxima)
	{
	}
	string getCodigo() {
		return codigo;
	}
	static bool compararCodigo(string co, Curso* cu) {
		return co == cu->codigo;
	}
	string getModalidad() {
		return modalidad;
	}
	static bool compararModalidad(string m, Curso* cu) {
		return m == cu->modalidad; // deberia ser modalidad
	}

	static bool compararMayorCupo(Curso * a, Curso* b) {
		return a->getCupos() > 0 && (b == nullptr || a->getCupos() > b->getCupos());
	}
	void disminuirCupos() {
		cupos--;   // debeeria ser --
	}
	int getCupos() {
		return cupos; //no deberia hbaer -1
	}
	int getCapMaxima() {
		return capMaxima;
	}
	void mostrar() {
		cout << "Codigo: " << codigo << endl;
		cout << "Nombre Curso: " << nombreCurso << endl;
		cout << "Modalidad: " << modalidad << endl;
		cout << "Capacidad Maxima: " << capMaxima << endl;
	}
}; 
