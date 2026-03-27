#pragma once
#include <iostream>
#include <string>


using namespace std;
class Estudiante {
private:
	int ci;
	string nombre;
	int cantidadLibrosPrestados;
public:

	Estudiante() = default;

	Estudiante(int ci, const string& nombre)
		: ci(ci), nombre(nombre)
	{
		cantidadLibrosPrestados = 0;
	}
	void mostrar() {
		cout << "Ci del estudiante: " << ci << endl;
		cout << "Nombre del estudiante: " << nombre << endl;
		cout << "Cantidad de libros prestados Activos: " << cantidadLibrosPrestados << endl;
	}

	int getCi() {
		return ci;
	}
	int getCantidadLibrosPrestadosActivos() {

		return cantidadLibrosPrestados;
	}
	void aumentarCantidadLibrosPrestadosActivos() {
		cantidadLibrosPrestados++;
	}
	void reducirCantidadLibrosPrestadosActivos() {
		cantidadLibrosPrestados--;
	}

};