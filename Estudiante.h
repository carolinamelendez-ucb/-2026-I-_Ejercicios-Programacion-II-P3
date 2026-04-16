#pragma once
#include <iostream>
#include <string>
using namespace std;


class Estudiante {
protected:
	string nombre;
	int ci;
	int costoMat;
	bool hizoPg	;
public:
	Estudiante(const string& nombre, int ci, int costoMat, bool pg)
		: nombre(nombre), ci(ci), costoMat(costoMat), hizoPg(pg)
	{}

	virtual double calcularmat() = 0;
	virtual void mostrar() = 0;

	bool getHizoPagoMat() {
		return hizoPg;
	}

	void cambiarNorealizoPago() {
		this->hizoPg = false;
	}

	int getcostoMat() {
		return costoMat;
	}

	int getCi() {
		return ci;
	}

	~Estudiante(){}

};