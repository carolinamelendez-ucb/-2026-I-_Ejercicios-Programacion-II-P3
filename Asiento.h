#pragma once
#include <iostream>
#include <string>
using namespace std;


class Asiento {
protected:
	int codigoAsiento;
	bool estado;
public:
	Asiento(int codigoAsiento, bool estado)
		: codigoAsiento(codigoAsiento), estado(estado)
	{}

	int getCodigo() {
		return codigoAsiento;
	}

	bool getEstado(){
		return estado;
	}

	void liberar(){
		this->estado = true;
	}

	void ocupar() {
		this->estado = false;
	}

	void mostrar() {
		cout << "Codigo:"<<codigoAsiento << endl;
		if (estado) {
			cout << "Asiento: Disponible" << endl;
		}
		else{
			cout << "Asiento: Ocupado" << endl;
		}
	}

	~Asiento(){}

};