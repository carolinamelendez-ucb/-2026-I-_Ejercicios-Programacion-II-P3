#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pasajero
{
private:
	string nombre;
	int ci;
	int numeroAsiento;
public:
	Pasajero(string nombre, int ci)
	{
		this->nombre = nombre;
		this->ci = ci;
		this->numeroAsiento = 0;
	}
	void asignarAsiento(int numero)
	{
		this->numeroAsiento = numero;
	}
	string getNombre()
	{
		return nombre;
	}
	int getCi()
	{
		return ci;
	}
	int getNumeroAsiento()
	{
		return numeroAsiento;
	}
	void mostrar()
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Ci: " << ci << endl;
		cout << "Numero de Asiento: " << numeroAsiento << endl;
	}
};