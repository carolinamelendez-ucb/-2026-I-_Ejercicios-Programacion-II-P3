#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <exception>


class EquipoNoEncontradoException : public exception {
private:
	string mensaje;
public:
	EquipoNoEncontradoException() {
		mensaje = "NO existe este equipo";
	}
	char const* what() const
	{
		return mensaje.c_str();
	}

};