#include "CLiente.h"

Cliente::Cliente(string nombre, string ci)
{
	this->nombre = nombre;
	this->ci = ci;
}

void Cliente::mostrar()
{
	cout << "cliente" << nombre << "con ci " << ci << endl;

}
