#pragma once
#include <ostream>
#include <string>
#include <exception>

using namespace std;

class CapacidadMaximaException : public exception {
private:
	string mensaje;
public:
	CapacidadMaximaException() {
		this->mensaje = "Limite de registros alcanzado";
	}
	char const* what() const {
		return mensaje.c_str();
	}
};