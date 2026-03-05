#pragma once
#pragma once
using namespace std;
#include <iostream>
#include <string>
class Socio {
private:
	int CI;
	string nombre;
	int telefono;
public:
	Socio()
	{
		CI = 212121;
	    nombre = "";
		telefono = 22222;
	}
	Socio(int CI, string nombre, int telefono)
	{
		this->CI = CI;
		this->nombre = nombre;
		this->telefono = telefono;
	}
	string getnombre() { return nombre; }
	void mostrar() {
		cout << "CI: " << CI << endl;
		cout << "nombre: " << nombre << endl;
		cout << "telefono" << telefono << endl;
	}

};
