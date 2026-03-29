#pragma once
#include <iostream>
#include <string>
using namespace std;

class Estudiante{
	private:
	int ci;
	string nombre;
	int cantidadPrestamosActivos;
	public:

	Estudiante (int ci, const string& nombre)
		: ci (ci), nombre (nombre), cantidadPrestamosActivos (0)
	{
	}

	void mostrar (){
		cout << "CI: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Cantidad de prestamos activos: " << cantidadPrestamosActivos << endl;
	}

	int getCi (){
		return ci;
	}

	string getNombre (){
		return nombre;
	}

	int getCantidadPrestamosActivos (){
		return cantidadPrestamosActivos;
	}

	bool verificarLimitePrestamos (){
		if(cantidadPrestamosActivos < 5){
			return true;
		}
		return false;
	}

	void incrementarPrestamos (){
		cantidadPrestamosActivos++;
	}

	void disminuirPrestamos (){
		if(cantidadPrestamosActivos > 0){
			cantidadPrestamosActivos--;
		}
	}
};