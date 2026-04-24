#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "VectorPasajero.h"
#include "VectorVuelos.h"
using namespace std;
class SistemaAsignacion {
private:
	string nombreAerolinea;
	VectorPasajero* listaPasajeros;
	VectorVuelo* listaVuelos;
public:
	SistemaAsignacion(const string& nombreAerolinea, int maxPasajeros, int maxVuelos)
		: nombreAerolinea(nombreAerolinea)
	{
		this->listaPasajeros = new VectorPasajero(maxPasajeros);
		this->listaVuelos = new VectorVuelo(maxVuelos);
	}
	void registrarVuelo(string codigo, int horaPartida, int horaLlegadaEsperada, int horaLlegadaReal, int filas, int columnas) {
		listaVuelos->agregarVuelos(new Vuelo(codigo, horaPartida, horaLlegadaEsperada, horaLlegadaReal, filas, columnas, filas * columnas, 100));
	}
	void registrarAsiento(string codigoVuelo, string codigoAsiento) {
		Vuelo* v = listaVuelos->buscar(codigoVuelo);
		if (v != nullptr) {
			v->getListaAsientos()->agregarAsiento(new Asiento(codigoAsiento));
		}
		else {
			cout << "Vuelo no encontrado..." << endl;
		}
	}
	void registrarPasajero(string codigoVuelo, int ci, string nombre, string apellido) {
		Vuelo* v = listaVuelos->buscar(codigoVuelo);
		if (v != nullptr) {
			v->getListaPasajeros()->agregarPasajero(new Pasajero(ci, nombre, apellido));
		}
		else {
			cout << "Vuelo no encontrado..." << endl;
		}
	}
	void asignarAsiento(string codigoVuelo, int ci, string codigoAsiento) {
		Vuelo* v = listaVuelos->buscar(codigoVuelo);
		if (v == nullptr) {
			throw exception();
		}
		Pasajero* p = v->getListaPasajeros()->buscar(ci);
		if (p == nullptr) {
			throw exception();
		}
		Asiento* a = v->getListaAsientos()->buscar(codigoAsiento);
		if (a == nullptr) {
			throw exception();
		}
		if (!a->getDisponible()) {
			throw exception();
		}
		p->asignarAsiento(a);
		a->ocupado();
	}
	void mostrarPasajeros(string codigoVuelo) {
		Vuelo* v = listaVuelos->buscar(codigoVuelo);
		if (v != nullptr) {
			v->getListaPasajeros()->mostrar();
		}
	}
	void estadoAsientos(string codigoVuelo) {
		Vuelo* v = listaVuelos->buscar(codigoVuelo);
		if (v != nullptr) {
			v->getListaAsientos()->mostrar();
		}
	}
};
