#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;


class Postgrado : public Estudiante {
public:
	Postgrado(string nombre, int ci)
		:Estudiante(nombre, ci, 1200, true) {
	}

	double calcularmat() override {
		return costoMat*1.20;
	}

	void mostrar()override {
		cout << "Cliente:" << nombre << endl;
		cout << "CI:" << ci << endl;
		cout << "Calculo total:" << calcularmat() << endl;
	}
};