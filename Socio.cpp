#include "Socio.h"

Socio::Socio(int ci, string nombre, string telefono)
{
	this->ci = ci;
	this->nombre = nombre;
	this->telefono = telefono;
}

int Socio::getCi()
{
	return ci;
}

string Socio::getNombre()
{
	return nombre;
}

string Socio::getTelefono()
{
	return telefono;
}

void Socio::mostrar()
{
	cout << "ci:" << ci << endl;
	cout << "nombre:" << nombre << endl;
	cout << "telefono:" << telefono << endl;

}