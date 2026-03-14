#pragma once
#include <iostream>
#include <string>
#include <random>
using namespace std;

class Organizador
{
private:
	string nombre;
	int id;
	int rank;
	bool disponibilidad;

public:
	Organizador() {}
	Organizador(string nombre)
	{
		this->nombre = nombre;
		this->id = rand();
		this->rank = 0;
		this->disponibilidad = true;
	}

	~Organizador()
	{

	}

	void mostrar()
	{
		cout << "nombre: " << nombre << endl;
		cout << "Id: " << id << endl;
		cout << "Rank: " << rank << endl;
		cout << "Disponible: " << disponibilidad << endl;
	}

	int getRank()
	{
		return rank;
	}

	bool getDisponibilidad()
	{
		return disponibilidad;
	}

	void marcarComoOcupado() {
		this->disponibilidad = false;
	}

	void finalizarServicio()
	{
		this->rank++; // Aumenta su rank
		this->disponibilidad = true; // tiene nuevamente disponibilidad
	} 
};
