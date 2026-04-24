#pragma once
#include "Asiento.h"
using namespace std;


class Pasajero {
protected:
	int ci;
	string nombre,apellido;
	Asiento* asientoAsig;
public:
	Pasajero(int ci, const string& nombre,string apellido, Asiento* asientoAsig)
		: ci(ci), nombre(nombre),apellido(apellido)
	{
		this->asientoAsig = nullptr;
	}

	void mostrar(){
		cout << "CI:"<<ci << endl;
		cout << "Nombre:"<<nombre << endl;
		cout << "Apellido:"<<apellido << endl;
		if (asientoAsig) {
			cout << "Asiento Asignado:" << asientoAsig->getCodigo() << endl;
		}
		else {
			cout << "Asiento Asingado: Ninguno" << endl;
		}
	}

	int getCI() {
		return ci;
	}

	Asiento* getAsiento() {
		return asientoAsig;
	}


	~Pasajero() {
		asientoAsig;
	}

};