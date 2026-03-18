#pragma once
#include <iostream>
#include <string>
#include "Sala.h"
#include "Pelicula.h"
using namespace std;
class Funcion {
private:
	int id;
	Pelicula* pelicula;
	Sala* sala;
	int precioEntrada;
	int boletosVendidos;
	int ganacia;
	bool** asientos;

public:

	Funcion() = default;

	Funcion(int id, Pelicula* pelicula, Sala* sala, int precioEntrada)
		: id(id), pelicula(pelicula), sala(sala), precioEntrada(precioEntrada) {
		this->boletosVendidos = 0;
		this->ganacia = 0;

		int filas = sala->getNumeroFilas();
		int columnas = sala->getNumeroPorfila();
		//creamos la matriz con estados
		asientos = new bool* [filas];
		for (int i = 0; i < filas; i++) {
			asientos[i] = new bool[columnas];
		}
		//al incio todos los asientos estan libres  --> libre 0 false y ocupado = true
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				asientos[i][j] = false;
			}
		}
		//mostramos matriz asientos para que elija un lugar 
	}

	void mostrarAsientos() {

		cout << "Asientos: " << endl;

		for (int i = 0; i < sala->getNumeroFilas(); i++) {
			for (int j = 0; j < sala->getNumeroPorfila(); j++) {
				if (asientos[i][j] == false) {
					cout << "[L]";
				}
				else {
					cout << "[X]";
				}
			}
			cout << endl;
		}
	}
	bool venderBoleto(int fila, int columna) {
		if (fila<0 || fila>=sala->getNumeroFilas()) {
			cout << "Fila invalida, no se puede vender boleto" << endl;
			return false;
		}
		if (columna<0 || columna>=sala->getNumeroPorfila()) {
			cout << "Columna invalida, no se puede vender boleto" << endl;
			return false;
		}
		if (asientos[fila][columna] == true) {
			cout << "Asiento ocupado" << endl;
			return false;
		}

		asientos[fila][columna] = true;
		boletosVendidos++;
		ganacia = ganacia + precioEntrada;
		return true;
	}

	void mostrar() {
		cout << "Id de la Funcion: " << id << endl;
		cout << "Pelicula de la Funcion: " << endl;
		pelicula->mostrar();
		cout << "Sala de la Funcion: " << endl;
		sala->mostrar();
		cout << "Precio de la Entrada: " << precioEntrada << endl;
		cout << "Boletos Vendidos: " << boletosVendidos << endl;
		cout << "Ganacia de la Funcion: " << ganacia << endl;
		cout << "Asientos disponibles de la Funcion: "<<endl;
		mostrarAsientos();
	}
	int getId() {
		return id;
	}
	int getGananciaFuncion() {
		return ganacia;
	}
	
	Pelicula* getPelicula() {
		return pelicula;
	}

};
