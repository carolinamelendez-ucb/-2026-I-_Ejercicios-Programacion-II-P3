#pragma once
#include <iostream>
#include <string>
using namespace std;

class Jugador {
private:
	int ci;
	string nombre;
	string posicion;
	int numeroCamiseta;
	bool estado; // false =libre
	string equipo;
public:
	Jugador(int ci, const string& nombre, const string& posicion, int numeroCamiseta)
		: ci(ci), nombre(nombre), posicion(posicion), numeroCamiseta(numeroCamiseta),estado(false),equipo("")
	{
	}

	void mostrar() {
		cout<<"Ci: "<<  ci<<endl;
		cout <<"Nombre: " << nombre << endl;
		cout<<"Posicion: " << posicion <<endl;
		cout<< "Numero Camiseta: " << numeroCamiseta << endl;
	}
	int getCi() {
		return ci;
	}
	bool getEstado() {
		return estado;
	}

	void agregarEquipo(string equipo) {
		this->equipo = equipo;
	}
	void actualizarEstado() {
		estado = true;
	}

	string getEquipo() {
		return equipo;
	}

	static bool comparar(Jugador* jugadorComparado, int ci) {
		return jugadorComparado->ci == ci;
	}

	static bool ordenar(Jugador* jugadorA, Jugador* jugadorB) {
		return jugadorA->nombre > jugadorB->nombre;
	}
};