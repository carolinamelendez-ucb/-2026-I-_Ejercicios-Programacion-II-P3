#pragma once
#include<iostream>
#include<string>
using namespace std;
class Equipo {
private:
	string piloto;
	string copiloto;
	string nombreequipo;
	string autoo;
public:
	Equipo(string piloto, string copiloto, string nombreequipo, string autoo) {
		this->piloto = piloto;
		this->copiloto = copiloto;
		this->nombreequipo = nombreequipo;
		this->autoo = autoo;
	}
	void mostrarEquipos();
};
