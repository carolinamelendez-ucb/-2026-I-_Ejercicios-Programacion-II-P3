#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Organizador
{
private:
	string nombre;
	int id;
	bool estado;
	int eventosRealizados;
public:
	Organizador(string nombre,int eventosRealizados)
	{
		this->nombre = nombre;
		this->id = generarID();
		this->estado = true;
		this->eventosRealizados =eventosRealizados ;
	}
	Organizador(string nombre)
	{
		this->nombre = nombre;
		this->id = generarID();
		this->estado = true;
		this->eventosRealizados = 0;
	}
	int generarID() {
		return rand() % 9000 + 1000; // número entre 1000 y 9999
	}
	bool disponible()
	{
		return estado;
	}
	int getEventos()
	{
		return eventosRealizados;
	}
	void mostrar()
	{
		cout << "id:" << id << endl;
		cout << "nombre:" << nombre << endl;
		cout << "estado:" << estado << endl;
		cout << "Eventos Realizados:" << eventosRealizados << endl;

	}
	void cambiarRank()
	{
		eventosRealizados = eventosRealizados + 1;
	}
};

