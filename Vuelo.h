#pragma once
#include <iostream>
#include <string>
#include "VectorPasajero.h"
#include "VectorAsiento.h"
using namespace std;
class Vuelo {
private:
	string codigoVuelo;
	int horaPartida;
	int horaLlegadaEsperada;
	int horaLlegadaReal;
	int filas;
	int columnas;
	VectorPasajero* listaPasajeros;
	VectorAsiento* listaAsientos;
public:
	Vuelo(const string& codigoVuelo, int horaPartida, int horaLlegadaEsperada, int horaLlegadaReal, int filas, int columnas, int maxPasajeros, int maxAsientos)
		: codigoVuelo(codigoVuelo), horaPartida(horaPartida), horaLlegadaEsperada(horaLlegadaEsperada), horaLlegadaReal(horaLlegadaReal), filas(filas), columnas(columnas)
	{
		this->listaPasajeros = new VectorPasajero(maxPasajeros);
		this->listaAsientos = new VectorAsiento(maxAsientos);
	}
	string getCodigo() {
		return codigoVuelo;
	}
	int capacidadMax() {
		return filas * columnas;
	}
	VectorAsiento* getListaAsientos() {
		return listaAsientos;
	}
	VectorPasajero* getListaPasajeros() {
		return listaPasajeros;
	}
};
