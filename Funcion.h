#pragma once
#include <iostream>
#include <string>
#include "Sala.h"
#include "Pelicula.h"
using namespace std;

class Funcion {
private:
	Sala* sala;
	Pelicula* pelicula;
	int precio;
	int boletosVendidos;
public:
	Funcion(Sala* sala, Pelicula* pelicula, int precio) {
		this->sala = sala;
		this->pelicula = pelicula;
		this->precio = precio;
		boletosVendidos = 0;
	}
	void venderBoleto() {
		boletosVendidos++;
	}
	int ganancia() {
		return precio * boletosVendidos;
	}
	Pelicula* getPelicula() {
		return pelicula;
	}
	void mostrar() {
		cout << "Pelicula: " << pelicula->getTitulo() << endl;
		cout << "Precio boleto: " << precio << endl;
		cout << "Boletos vendidos: " << boletosVendidos << endl;
		cout << "Ganancia: " << ganancia() << endl;
	}
};
