#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <exception>


class JugadorNoEncontradoException : public exception {
private:
	string mensaje;
public:
	JugadorNoEncontradoException() {
		mensaje = "NO existe este jugador";
	}
	char const* what() const
	{
		return mensaje.c_str();
	}

};