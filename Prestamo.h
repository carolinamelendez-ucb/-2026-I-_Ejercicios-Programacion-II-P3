#pragma once
#include <iostream>
#include <string>


using namespace std;
class Prestamo {
private:
	int ciEstudent;
	int codigoLibro;
	bool estado;
public:

	Prestamo() = default;

	Prestamo(int ciEstudent, int codigoLibro)
		: ciEstudent(ciEstudent), codigoLibro(codigoLibro)
	{
		this->estado = true;
	}
	void mostrar() {
		cout << "Ci del Estudiante: " << ciEstudent << endl;
		cout << "Codigo del libro: " << codigoLibro << endl;
		if (estado) {
			cout << "Estado del prestamo: Activo" << endl;
		}
		else {
			cout << "Estado del prestamo: Inactivo" << endl;
		}
	}
	void setestado(bool estado) {
		this->estado=estado;
	}
	bool getEstado() {
		return estado;
	}

	int getCiStudent() {
		return ciEstudent;
	}

	int getCodigoLibro() {
		return codigoLibro;
	}
};