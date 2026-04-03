#pragma once
#include <iostream>
#include<string>
using namespace std;
class Empleado {
protected:
	string nombre;
	int ci;
public:
	Empleado(const string& nombre, int ci)
		: nombre(nombre), ci(ci)
	{
	}
	int getCi() {
		return ci;

	}
	virtual float calcularSalario() = 0;
	virtual void mostrarInformacion() = 0;
	virtual ~Empleado(){}
};
class EmpleadoTiempoCompleto : public Empleado {
private:
	float SalarioBase;
	float bono;
public:
	EmpleadoTiempoCompleto(string n, int ci,float SalarioBase, float bono)
		:Empleado(n,ci),SalarioBase(SalarioBase),bono(bono)
	{
	}
	float calcularSalario() {
		return SalarioBase + bono;
	}
	void mostrarInformacion() {
		cout << "|tiempo completo	   |" << endl;
		cout << "|nombre del empleado: |" << nombre << endl;
		cout << "|ci:				   |" << ci << endl;
		cout << "|Salario:			   |" << calcularSalario() << endl;
	}
};
class EmpleadoTipoHoras : public Empleado {
private:
	int horas;
	float pagoPorHoras;
public:
	EmpleadoTipoHoras(string n,int ci,int horas, float pagoPorHoras)
		:Empleado(n,ci), horas(horas), pagoPorHoras(pagoPorHoras)
	{
	}
	float calcularSalario() {
		return horas * pagoPorHoras;
	}
	void mostrarInformacion() {
		cout << "|tiempo por Horas	   |" << endl;
		cout << "|nombre del empleado: |" << nombre << endl;
		cout << "|ci:				   |" << ci << endl;
		cout << "|Salario:			   |" << calcularSalario() << endl;
	}
};