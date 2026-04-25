#pragma once
#include <iostream>
#include <string>
using namespace std;

class ArrayLlenoException : public exception {
private:
	string mensaje;
public:
	ArrayLlenoException() {
		mensaje = "Array lleno, no se puede agregar mas elementos";
	}
	virtual char const* what() const {
		return mensaje.c_str();
	}
};






