#pragma once
#include<iostream>
#include<string>
#include"Empleado.h"
using namespace std;
class EmpleadoPorHoras: public Empleado {
private:
	int cantidadHoras;
	float pagoHora;
public:
	EmpleadoPorHoras(string nombre, int ci, float pagoHora, int cantidadHoras)
		: Empleado(nombre,ci){ 
		this->cantidadHoras = cantidadHoras;
		this->pagoHora = pagoHora;
	}

	float calcularSalario() {
		if (cantidadHoras > 8) { //si empleado trabajo mas de 8 horas 
								 // recibe un bono de 20 bs;
		return (pagoHora * cantidadHoras)+20;
		
		}
		else {
			return (pagoHora * cantidadHoras);
			
		}
		
	}

	void mostrarInformacion(){

		cout << "Nombre del Empleado por horas: " << nombre << endl;
		cout << "Ci del Empleado por horas: " << ci << endl;
		cout << "Salario: " << calcularSalario() << endl;
	}
};