#pragma once
#include <iostream>
#include<exception>
#include<string>
using namespace std;
class VectorException :public exception {
private:
	string mensaje;
public:
	VectorException() {
		mensaje = "El vector esta lleno ";

	}
	char const* what() const
	{
		return mensaje.c_str();
	}
};