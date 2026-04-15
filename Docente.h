#pragma once
#include <iostream>
#include <string>
using namespace std;

class Docente {
protected:
	int ci;
	string nombre;
	string tipo;
	int salario;
	float bono;
	int cantidadCursos;
	bool finalizoSeleccion;
public:
	Docente(int ci, const string& nombre, int salario, float bono, const string& tipo,bool finalizoSeleccion)
		: ci(ci), nombre(nombre), salario(salario), bono(bono), cantidadCursos(0), tipo(tipo), finalizoSeleccion(finalizoSeleccion)
	{
	}
	Docente() = default;
	virtual void mostrar() {
		cout << "Ci: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Salario: " << salario << endl;
		cout << "Bono: " << bono << endl;
	}

	void comprobarCantidadCursosMedioTiempo() {
		if (tipo == "Medio Tiempo" && cantidadCursos > 2) {
			this->bono = 0.1;
		}
	}

	float salarioTotal() {
		return salario * cantidadCursos * (1 + bono);
	}
	void aumentarCantidadCursos() {
		cantidadCursos++;
	}

	int getCi() { return ci; }
	bool getFinalizoSeleccion() { return finalizoSeleccion; }
};