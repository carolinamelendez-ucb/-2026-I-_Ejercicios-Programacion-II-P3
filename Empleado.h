#pragma once
#include <iostream>
#include <string>

using namespace std;

class Empleado {
private:
	string nombre;
	int ci;
	int cantidadFuncionesAtendidas;
	bool estado;
public:

	Empleado() = default;

	Empleado(const string& nombre, int ci)
		: nombre(nombre), ci(ci)
	{
		this->cantidadFuncionesAtendidas = 0;
		this->estado = true;
	}
	void mostrar() {
		cout << "Nombre del empleado: "<<nombre << endl;
		cout << "Ci del empleado: " <<ci<< endl;
		cout << "Cantidad de Funciones Atendidas: " <<cantidadFuncionesAtendidas<< endl;
		if (estado) {
			cout << "Estado del Empleado: Libre" <<endl;
		}
		else {
			cout << "Estado del empleado: Ocupado" << endl;
		}
	}

	int getCi() {
		return ci;
	}

	int getCantidadFuncionesAtendidas() {
		return cantidadFuncionesAtendidas;
	}
	void aumenarCantidadFuncionesAtendidas() {
		cantidadFuncionesAtendidas++;
	}
	bool getEstado() {
		return estado;
	}
	void setEstado(bool estado) {
		this->estado = estado;
	}
};