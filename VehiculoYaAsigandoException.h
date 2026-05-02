#pragma once
#include <ostream>
#include <string>
#include <exception>

using namespace std;

class VehiculoYaAsigandoException : public exception {
private:
	string mensaje;
public:
	VehiculoYaAsigandoException() {
		this->mensaje = "Vehiculo Ya Asigando a un espacio";
	}
	char const* what() const {
		return mensaje.c_str();
	}
};


