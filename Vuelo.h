#pragma once
#include "ListaPasajeros.h"
#include "ListaAsientos.h"

class Vuelo {
protected:
	int codigoVuelo;
	double horaPartida;
	double horaLlegadaActual;
	double horaLlegadaEsperada;
	VectorAsientos* asientos;
	VectorPasajeros* pasajeros;
public:


	Vuelo(int codigoVuelo,double horaPartida, double horaLlegadaActual, double horaLlegadaEsperada)
		: codigoVuelo(codigoVuelo), horaPartida(horaPartida), horaLlegadaActual(horaLlegadaActual), horaLlegadaEsperada(horaLlegadaEsperada)
	{
	
	}












	void mostrarV() {
		cout << "Codigo del Vuelo:"<<codigoVuelo << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	}

	int getCodigoV() {
		return codigoVuelo;
	}

	~Vuelo() {
		delete asientos;
		delete pasajeros;
	}

};