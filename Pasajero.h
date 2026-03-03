#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pasajero{
private:
	string nombre;
	int ci;
	int numeroAsiento;
public:
	Pasajero (string nombre, int ci){
			this -> nombre = nombre;
			this -> ci = ci;
			this -> numeroAsiento = 0;
		}
	void setNumeroAsiento (int numero){
		this-> numeroAsiento = numero;
	}
	int getNumeroAsiento (){
		return numeroAsiento;
	}
	string getNombre (){
		return nombre;
	}
	int getCi (){
		return ci;
	}
	void mostrar (){
		cout << "Nombre :" << nombre << endl;
		cout << "Ci: " << ci << endl;
		cout << "Asiento: " << numeroAsiento << endl;

	}
};