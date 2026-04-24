#pragma once
#pragma once
#include "VectorPasajeros.h"
#include "VectorAsientosh.h"

class Vuelo {
private:
	string codigoVuelo;
	int horaPartida;
	int horaLlegadaEsperada;
	int horaLlegadaActual;
	int filas;
	int columnas;
	VectorAsientos* listaAsientos;
	VectorPasajeros* listaPasajeros;
public:
	Vuelo(string codigoVuelo, int horaPartida, int horaLlegadaEsperada, int horaLlegadaActual,int filas, int columanas, int maxAsientos, int maxPasajeros) {
		this->codigoVuelo = codigoVuelo;
		this->horaPartida = horaPartida;
		this->horaLlegadaEsperada = horaLlegadaEsperada;
		this->horaLlegadaActual = horaLlegadaActual;
		this->columnas = columanas;
		this->filas = filas;
		this->listaAsientos = new VectorAsientos(maxAsientos);
		this->listaPasajeros = new VectorPasajeros(maxPasajeros);
	}
	string getCodigo() {
		return codigoVuelo;
	}
	int capacidadMax() {
		return filas * columnas;
	}
	VectorAsientos* getAsientos() {
		return listaAsientos;
	}
	VectorPasajeros* getPasajeros() {
		return listaPasajeros;
	}
};

