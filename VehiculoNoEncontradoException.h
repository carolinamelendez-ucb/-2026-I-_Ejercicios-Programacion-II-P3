#pragma once
#include <ostream>
#include <string>
#include <exception>

using namespace std;

class VehiculoNoEncontradoException : public exception {
private:
	string mensaje;
public:
	VehiculoNoEncontradoException() {
		this->mensaje = "Vehiculo No Encontrado ";
	}
	char const* what() const {
		return mensaje.c_str();
	}
};
