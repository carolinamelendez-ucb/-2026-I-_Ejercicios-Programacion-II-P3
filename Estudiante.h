#pragma once
#include <iostream>
#include <string>
using namespace std;

class Estudiante
{
private:
	string ci;
	string nombre;
	int prestamosActivos; // empezaran en 0

public:

	Estudiante(string ci , string nombre)
	{
		this->ci = ci;
		this->nombre = nombre;
		this->prestamosActivos = 0;

	}
	int getPrestamosActivos()
	{
		return prestamosActivos;
	}

	string getCi()
	{
		return ci;
	}

	string getNombre()
	{
		return nombre;
	}

	void incrementarPrestamos()
	{
		this->prestamosActivos++; //+1
	}

	void decrementarPrestamos()
	{
		this->prestamosActivos--; //-1
	}

	void mostrar()
	{
		cout << " Nombre Estudiante " << nombre << endl;
		cout << " Ci Estudiante " << ci << endl;
	}


};
