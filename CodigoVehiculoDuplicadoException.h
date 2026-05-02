#pragma once
#include <ostream>
#include <string>
#include <exception>

using namespace std;

class CodigoVehiculoDuplicadoException : public exception {
private:
	string mensaje;
public:
	CodigoVehiculoDuplicadoException() {
		this->mensaje = "Codigo Vehiculo Duplicado";
	}
	char const* what() const {
		return mensaje.c_str();
	}
};