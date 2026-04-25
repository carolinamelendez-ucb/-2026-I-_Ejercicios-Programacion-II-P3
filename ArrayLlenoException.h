#pragma once
#include <iostream>
#include <string>

using namespace std;

class ArrayLlenoException : public exception {
private:
	string mensaje;
public:
	ArrayLlenoException() {
		mensaje = "Lleno, no se pueden agregar mas";
	}

	virtual char const* what() const {
		return mensaje.c_str();
	}
};