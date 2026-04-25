#pragma once
#include <iostream>
#include <string>

using namespace std;

class ArrayLLenoException: public exception
{
private:
	string mensaje;
public:
	ArrayLLenoException()
	{
		mensaje = "El array esta lleno, no se puede agregar mas elememntos";
	}
	virtual char const* what() const
	{
		return mensaje.c_str();
	}
};

