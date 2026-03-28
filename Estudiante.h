#pragma once

#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
	string nombre;
	string email;

public:

	Estudiante(const string& nombre, const string& email)
		: nombre(nombre), email(email)
	{
	}

	void mostrar(){
		cout << "Nombre: " << nombre << endl;
		cout << "Email: " << email << endl;
	}
};