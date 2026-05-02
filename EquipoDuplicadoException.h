#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <exception>


class EquipoDuplicadoException : public exception {
private:
	string mensaje;
public:
	EquipoDuplicadoException() {
		mensaje = "Codigo ya existe en otro equipo";
	}
	char const* what() const
	{
		return mensaje.c_str();
	}

};