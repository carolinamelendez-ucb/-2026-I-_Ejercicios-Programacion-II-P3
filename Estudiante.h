#pragma once
#include <iostream>
#include <string>

using namespace std;

class Estudiante {
private:
	string nombre;
	string gmail;
public:

	Estudiante() = default;

	Estudiante(const string& nombre, const string& gmail)
		: nombre(nombre), gmail(gmail)
	{
	}
	void mostrar() {
		cout << "Nombre del Estudiante: " <<nombre<< endl;
		cout << "Correo del estudiante: " << gmail<<endl;
	}
};
