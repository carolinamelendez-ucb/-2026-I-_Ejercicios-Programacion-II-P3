#pragma once
#include <iostream>
#include <string>
using namespace std;
class Asiento {
private:
	string codigoAsiento;
	bool estado;
public:
	Asiento(string codigoAsiento)
		: codigoAsiento(codigoAsiento), estado(true)
	{
	}
	void ocupado() {
		estado = false;
	}
	bool getDisponible() {
		return estado;
	}
	string getCodigo() {
		return codigoAsiento;
	}
};
