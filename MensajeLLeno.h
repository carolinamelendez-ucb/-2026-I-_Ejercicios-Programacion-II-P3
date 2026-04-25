#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vectorlleno :public exception {
private:
	string mensaje;
public:
	Vectorlleno() {
		mensaje = "No se puede agregar mas elementos";
	}

	virtual char const* what() const {
		return mensaje.c_str();
	}

};