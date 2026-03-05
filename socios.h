#pragma once
#include<iostream>
#include<string>
using namespace std;
class Socios {
private:
	int ci;
	string nombre;
	int telefono;
public:
	Socios(int ci, string nombre, int telefono) {
		this->ci = ci;
		this->nombre = nombre;
		this->telefono = telefono;
	}
	void mostrarSocios();
};