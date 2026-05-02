#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <exception>


class JugadorDuplicadoException : public exception {
private:
	string mensaje;
public:
	JugadorDuplicadoException() {
		mensaje = "Ci ya existe en otro equipo";
	}
	char const* what() const
	{
		return mensaje.c_str();
	}

};