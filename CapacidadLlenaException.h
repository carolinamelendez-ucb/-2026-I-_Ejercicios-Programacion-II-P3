#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <exception>


class CapacidadLlenaException : public exception {
private:
	string mensaje;
public:
	CapacidadLlenaException() {
		mensaje = "Se lleno el array";
	}
	char const* what() const
	{
		return mensaje.c_str();
	}

};