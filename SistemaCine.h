#pragma once
#include <iostream>
#include <string>
#include "ArrayLlenoException.h"
#include "ArrayGenerico.h"
#include "Cliente.h"
#include "Sala.h"
#include "Pelicula.h"
#include "Funcion.h"

using namespace std;

class SistemaCine {
private:
	ArrayGenerico<Cliente>* clientes;
	ArrayGenerico<Sala>* salas;
	ArrayGenerico<Pelicula>* peliculas;
	ArrayGenerico<Funcion>* funciones;
public:
	SistemaCine(int tamClientes, int tamSalas, int tamPeliculas, int tamFunciones) {
		clientes = new ArrayGenerico<Cliente>(tamClientes);
		salas = new ArrayGenerico<Sala>(tamSalas);
		peliculas = new ArrayGenerico<Pelicula>(tamPeliculas);
		funciones = new ArrayGenerico<Funcion>(tamFunciones);
	}

	void registrarCliente(Cliente* cliente) {
		try {
			clientes->agregar(cliente);
		}
		catch (exception& err) {
			cout << err.what() << endl;
		}
	}

	void registrarSala(Sala* sala) {
		try {
			salas->agregar(sala);
		}
		catch (exception& err) {
			cout << err.what() << endl;
		}
	}

	void registrarPelicula(Pelicula* pelicula) {
		try {
			peliculas->agregar(pelicula);
		}
		catch (exception& err) {
			cout << err.what() << endl;
		}
	}

	void registrarFuncion(Funcion* funcion) {
		try {
			funciones->agregar(funcion);
		}
		catch (exception& err) {
			cout << err.what() << endl;
		}
	}

	void mostrarClientes() {
		clientes->mostrar();
	}

	void mostrarFunciones() {
		funciones->mostrar();
	}

	void mostrarPeliculas() {
		peliculas->mostrar();
	}

	void mostrarSalas() {
		salas->mostrar();
	}
};
