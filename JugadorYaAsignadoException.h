#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <exception>


class JugadorYaAsignadoException : public exception {
private:
	string mensaje;
public:
	JugadorYaAsignadoException() {
		mensaje = "Jugador ya esta asignado";
	}
	char const* what() const
	{
		return mensaje.c_str();
	}

};