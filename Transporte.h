#pragma once
#include <iostream>
#include <string>
using namespace std;

class Transporte {
protected:
	string nombre;
	string tipo;
public:
	Transporte(const string& nombre, const string& tipo)
		: nombre(nombre), tipo(tipo)
	{
	}

	string getNombre() {
		return nombre;
	}

	string getTipo() {
		return tipo;
	}

	virtual double calcularCosto(double distancia) = 0;




};