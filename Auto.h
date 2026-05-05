#pragma once
#include <string>
#include <iostream>

using namespace std;

class Auto {
private:
	string marca;
	string modelo;
	int anio;

public:
	Auto() {
		this->marca = "";
		this->modelo = "";
		this->anio = 0;
	}

	Auto(string marca, string modelo, int anio) {
		this->marca = marca;
		this->modelo = modelo;
		this->anio = anio;
	}
	void mostrarInformacion() {
		cout << "Marca: " << this->marca << endl;
		cout << "Modelo: " << this->modelo << endl;
		cout << "Año: " << this->anio << endl;
	}
};