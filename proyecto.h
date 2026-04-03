#pragma once
#include <iostream>
#include<string>
using namespace std;
class Proyecto {
protected:
	int codigo;
	string nombre;
public:
	Proyecto(int codigo, const string& nombre)
		: codigo(codigo), nombre(nombre)
	{
	}
	int getcodigo() {
		return codigo;
	}
	virtual float CalcularCosto() = 0;
	virtual void mostrar() = 0;
	virtual ~Proyecto(){}
};
class ProyectoInterno : public Proyecto {
private:
	float presupuesto;
public:
	ProyectoInterno(int codigo,string n ,float presupuesto)
		:Proyecto(codigo,n), presupuesto(presupuesto)
	{
	}
	float CalcularCosto() {
		return presupuesto;
	}
	void mostrar(){
		cout << "|Proyecto Interno:|" << nombre;
		cout << "|presupuesto	  :|" << CalcularCosto() << endl;
	}
};
class ProyectoExterno : public Proyecto {
private:
	float presupuesto;
	float ganancia;
public:
	ProyectoExterno(int codigo, string n, float presupuesto,float ganancia)
		:Proyecto(codigo, n), presupuesto(presupuesto),ganancia(ganancia)
	{
	}

	float CalcularCosto() {
		return presupuesto + ganancia;
	}
	void mostrar() {
		cout << "|Proyecto Externo:|" << nombre;
		cout << "|presupuesto	  :|" << CalcularCosto() << endl;
	}
};