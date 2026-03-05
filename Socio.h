#pragma once
#include<iostream>
#include<string>
using namespace std;

class Socio{
private:
	int ci;
	string nombre;
	int telefono;
public:
	Socio(int ci, string nombre, int telefono){
		this->ci=ci;
		this->nombre = nombre;
		this->telefono = telefono;
	}
	
	void mostrar() {
		cout << "El ci del socio es: " << ci << endl;
		cout << "El nombre de socio es: " << nombre << endl;
		cout << "El telefono del socio es: " << telefono << endl;
	}
};