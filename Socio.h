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
	Socio() {  //contructor por defecto
		this->ci = 0;
		this->nombre = "";
		this->telefono = 0;
	}
	int getCi() {
		return ci;
	}
	string getNombre() {
		return nombre;
	}
	void mostrar() {
		cout << "El ci del socio es: " << ci << endl;
		cout << "El nombre de socio es: " << nombre << endl;
		cout << "El telefono del socio es: " << telefono << endl;
	}
};