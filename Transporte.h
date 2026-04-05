#pragma once
#include <iostream>
#include<string>
using namespace std;
class Transporte {
protected:
	string placa;
public:
	Transporte(const string& placa)
		: placa(placa)
	{
	}
	string getplaca() {
		return placa;
	}
	virtual float calcularCosto(float distacia) = 0;
	virtual void mostrar() = 0;
	virtual ~Transporte(){}
};
class Terrestre : public Transporte {
public:
	Terrestre(string p):Transporte(p){}
	float calcularCosto(float d) {
		float costo = d * 0.5;
		if (d > 100) costo = costo * 1.10;
		return costo;

	}

	void mostrar() {
		cout << "Placa|terreste: " << placa << endl;
	}
};
class Aereo : public Transporte {
public:
	Aereo(string p) :Transporte(p) {}
	float calcularCosto(float d) {
		float costo = d * 2.0;
		if (d > 1000) costo = costo * 0.85;
		return costo;
		
		

	}
	void mostrar() {
		cout << "Placa|terreste: " << placa << endl;
	}
};
class Maritimo : public Transporte {
public:
	Maritimo(string p):Transporte(p){}
	float calcularCosto(float d) {
		float costo = d * 1.2;
		if (d > 500)costo = costo+50;
		return costo;
		

	}
	void mostrar() {
		cout << "Placa|terreste: " << placa << endl;
	}
};
