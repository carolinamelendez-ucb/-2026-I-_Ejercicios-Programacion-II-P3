#pragma once
#include <ostream>
#include <string>
#include <exception>

using namespace std;

class NoHayEspacioDisponibleException : public exception {
private:
	string mensaje;
public:
	NoHayEspacioDisponibleException() {
		this->mensaje = "No Hay Espacio Disponible  ";
	}
	char const* what() const {
		return mensaje.c_str();
	}
};

