#pragma once
#include <iostream>
#include <string>
#include "Pelicula.h"
#include "Sala.h"
#include "Cliente.h"
#include "ArrayGenerico.h"

using namespace std;

class Funcion
{
private:
	string horario;
	Pelicula* pelicula;
	Sala* sala;
	ArrayGenerico<Cliente>* listaClientes;
public:
	Funcion(string horario,int tamanio)
	{
		this->horario = horario;
		this->pelicula = nullptr;
		this->sala = nullptr;
		this->listaClientes = new ArrayGenerico<Cliente>(tamanio);
	}
	void asiganrPleicula(Pelicula* nuevaPli)
	{
		pelicula = nuevaPli;
	}
	void asiganrSala(Sala* nuevaSala)
	{
		sala = nuevaSala;
	}
	void asiganrClientes(Cliente* nuevaCliente)
	{
		listaClientes->agregar(nuevaCliente);
		listaClientes->mostrar();
	}
	void mostrar()
	{
		cout << "horario: " << horario << endl;
		cout << "pelicula: " << endl;
		pelicula->mostrar();
		cout << "sala: "  << endl;
		sala->mostrar();
		cout << "Clientes: " << endl;
		listaClientes->mostrar();

	}

};
