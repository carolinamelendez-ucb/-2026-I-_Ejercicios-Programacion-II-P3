#pragma once
#include <iostream>
#include <string>

using namespace std;


class Docente
{
protected:
	string nombre;
	int ci;
	float salarioBase;
	bool aproboEntrevista;
public:
	Docente(const string& nombre, int ci, float salarioBase, bool aproboEntrevista)
		: nombre(nombre), ci(ci), salarioBase(salarioBase),aproboEntrevista(aproboEntrevista)
	{}
	virtual float calculaSalario() = 0;
	virtual void mostrar()
	{
		cout << "nombre: " << nombre << endl;
		cout << "ci: " << ci << endl;
		cout << "Salario Base: " << salarioBase << endl;
	}
	int getCi()
	{
		return ci;
	}
	bool getAproboEntrevista()
	{
		return aproboEntrevista;
	}
};