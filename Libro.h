#pragma once
#include <iostream>
#include <string>
using namespace std;

class Libro
{
private:
	string codigo;
	string titulo;
	bool estaDisponible; // siempre empezara como true

public:
	Libro(string codigo, string titulo)
	{
		this->codigo = codigo;
		this->titulo = titulo;
		this->estaDisponible = true;
	}

	string getCodigo()
	{
		return codigo;
	}
	bool getEstaDispobible()
	{
		return estaDisponible;
	}

	void cambiarEstadoDeDisponible(bool cambio)
	{
		this->estaDisponible = cambio;
	}

	void mostrar()
	{
		cout << " Codigo del libro " << codigo << endl;
		cout << " Titulo del libro " << titulo << endl;
		cout << " Esta Disponible ? .." << (estaDisponible ? "Si" : "No") << endl;
	}

};