#pragma once
#include <iostream>
#include <string>
using namespace std;

class Asiento {
private:
	string codigoAsiento;
	bool estado;
public:
	Asiento(string codigoAsiento) {
		this->codigoAsiento = codigoAsiento;
		this->estado = true;
	}
	void ocupado(){
		estado = false;
	}
	bool getDiponibilidad() {
		return estado;
	}
	string getCodigo() {
		return codigoAsiento;
	}

};
