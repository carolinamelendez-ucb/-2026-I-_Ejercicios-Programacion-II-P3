#pragma once
#include <iostream>
#include <string>
using namespace std;

class Instructor {
private:
	string nombre;
	int ci;
	int cantidadCursos;
	bool estado;
public:
	Instructor(const string& nombre, int ci, int cantidadCursos, bool estado)
		: nombre(nombre), ci(ci), cantidadCursos(cantidadCursos), estado(estado)
	{
	}

	int getCantidadCursos() {
		return cantidadCursos;
	}

	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Ci: " << ci << endl;
		cout << "Cantidad de cursos realizados: " << cantidadCursos << endl;
		cout << "Estado: "; 
			if (estado == true) {
				cout << "Libre" << endl;
			}
			else{
				cout << "Ocupado" << endl;
			}
	}

	bool getEstado() {
		return estado;
	}

	void actualizarEstado() {
		if (estado == true) {
			estado = false;
		}
		else {
			estado = true;
			cantidadCursos++;
		}
	}

	string getNombre() {
		return nombre;
	}
};