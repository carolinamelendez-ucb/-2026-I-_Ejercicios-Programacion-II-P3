#pragma once
#include <string>
#include <iostream>
using namespace std;

class Empleado
{
private:
	string nombre;
	string ci;
	int funcionesAtendidas;
	bool estaLibre;

public:
	Empleado(string nombre, string ci)
	{
		this->nombre = nombre;
		this->ci = ci;
		this->estaLibre = true;
		this->funcionesAtendidas = 0;
	}

	void setDisponible(bool n)
	{
		this->estaLibre = n; //false or true
	}

	bool getLibre()
	{
		return estaLibre;
	}

	void incrementarFunciones()
	{
		this->funcionesAtendidas++;
	}
	int getFunciones()
	{
		return funcionesAtendidas;
	}
	
	string getCi()
	{
		return ci;
	}

	void mostrar()
	{
		cout << " Nombre Empleado : " << nombre << endl;
		cout << " Ci Empleado : " << ci << endl;
		cout << " Funciones (pelis)  atendidas " << funcionesAtendidas << endl;
		cout << " Esta Libre : " << (estaLibre ? "Si" : "No") << endl;
	}
};