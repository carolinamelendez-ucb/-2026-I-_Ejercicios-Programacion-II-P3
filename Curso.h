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
		return m == cu->modalidad; //la comparacion previamente se hacia con el codigo, no con la modalidad como se esperaba inicialmente
	}
	static bool mayorCupos(Curso* c1, Curso* c2) { //Se agrega el metodo estatico que compara la cantidad de cupos de los cursos hasta encontrar al mayor
		return c2 == nullptr || c1->cupos > c2->cupos;
	}
	void disminuirCupos() {
		cupos--; //los cupos aumentaban en lugar de disminuir
	}
	int getCupos() {
		return cupos; //se retornaba cupos-1 cuando solo deberia retornarse cupos
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
