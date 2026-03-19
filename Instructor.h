#pragma once
#include <iostream>

using namespace std;

class Instructor {
private:
	string nombre;
	int ci;
	int cursosRealizados;
	bool estado; //true=libre, false=ocupado
public:

	Instructor() = default;

	Instructor(const string& nombre, int ci, int cursosRealizados, bool estado)
		: nombre(nombre), ci(ci), cursosRealizados(cursosRealizados), estado(estado)
	{
	}

	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "CI: " << ci << endl;
		cout << "Cantidad de cursos realizados: " << cursosRealizados << endl;
		cout << "Esta disponible: " << (estado ? "Si" : "No") << endl;
	}

	int getCursosRealizados() { return cursosRealizados; }
	bool getEstado() { return estado; }
	string getNombre() { return nombre; }

	void cambiarEstadoOcupado() { estado = false; }

	// Punto 4: liberar instructor al finalizar un curso
	void liberarInstructor() {
		estado = true;
		cursosRealizados++;
	}
};