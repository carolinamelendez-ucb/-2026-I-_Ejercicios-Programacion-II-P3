#pragma once
#include "VectSocio.cpp"
class Equipo {
private:
	Socio piloto;
	Socio copiloto;
	string nombreE;
	string nauto;
public:
	Equipo();
	Equipo(Socio piloto, Socio copiloto, string nomE, string Naut) {
		this->piloto = piloto;
		this->copiloto = copiloto;
		this->nombreE = nomE;
		this->nauto = Naut;
	}
	Socio getPiloto() {
		return piloto;
	}
	Socio getCopiloto() {
		return copiloto;
	}
	string getnombreE() {
		return nombreE;
	}
	string getNauto() {
		return nauto;
	}
	void mostrar() {
		cout << "Piloto: " << piloto.getNombre() << endl;
		cout << "Copiloto: " << copiloto.getNombre() << endl;
		cout << "Nombre de Equipo: " << nombreE << endl;
		cout << "Nombre del Auto: " << nauto << endl;
	}
};