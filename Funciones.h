#pragma once
#include "Peliculas.h"
#include "ArrayGenerico.h"
#include "Cliente.h"
#include "Sala.h"
class Funciones
{
private:
	Peliculas* peliculaAsignada;
	int horaInicio;
	Sala* salaAsignada;
	ArrayGenerico<Cliente>** listaClientes;
public:
	Funciones(int hora,int tam)
	{
		this->peliculaAsignada = nullptr;
		this->horaInicio = hora;
		this->listaClientes = new ArrayGenerico<Cliente>*[tam];
		this->salaAsignada = nullptr;
	}
};

