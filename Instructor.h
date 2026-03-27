#pragma once
#include <iostream>
#include <string>

using namespace std;

class Instructor {
private:
	string nombre;
	int ci;
	int cantidadCursosRealizados;
	bool estado; //libre u ocupado

public:

	Instructor() = default;

	Instructor(const string& nombre, int ci, int cantidadCursosRealizados)
		: nombre(nombre), ci(ci), cantidadCursosRealizados(cantidadCursosRealizados)
	{
		this->estado = true;
	}
	Instructor(const string& nombre, int ci)
		: nombre(nombre), ci(ci){
		this->cantidadCursosRealizados = 0;
		this->estado = true;
	}
	bool getEstado() {
		return estado;
	}
	void estaLibre() {
		estado = true;
	}
	void EstaOcupado() {
		estado = false;
	}
	void AumentarCantidadCursoR() {
		this->cantidadCursosRealizados++;
	}

	int getCantidadCursosR() {
		return cantidadCursosRealizados;
	}
	void mostrar() {
		cout << "Nombre del instructor es: " << nombre << endl;
		cout << "Ci del Instructor es: " << ci << endl;
		cout << "Cantidad de cursos realizados: " << cantidadCursosRealizados << endl;
		if (estado) {
			cout << "El intructor esta libre" << endl;
		}
		else {
			cout << "El intructor esta ocupado" << endl;
		}
	}
};
