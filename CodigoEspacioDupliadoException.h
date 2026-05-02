#pragma once
#include <ostream>
#include <string>
#include <exception>

using namespace std;

class CodigoEspacioDuplicadoException: public exception {
private:
	string mensaje;
public:
	CodigoEspacioDuplicadoException() {
		this->mensaje = "Codigo Espacio Duplicado";
	}
	char const* what() const {
		return mensaje.c_str();
	}
};