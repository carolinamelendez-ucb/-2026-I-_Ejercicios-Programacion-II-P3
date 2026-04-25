#pragma once
#include "ArrayGenerico.h"
#include "Cliente.h"
#include "Sala.h"
#include "Pelicula.h"
#include "Funcion.h"

class SistemaCine {
private:
	ArrayGenerico<Cliente>* clientes;
	ArrayGenerico<Sala>* salas;
	ArrayGenerico<Pelicula>* peliculas;
	ArrayGenerico<Funcion>* funciones;
public:
	SistemaCine(int tamC, int tamS, int tamP, int tamF) {
		clientes = new ArrayGenerico<Cliente>(tamC);
		salas = new ArrayGenerico<Sala>(tamC);
		peliculas = new ArrayGenerico<Pelicula>(tamC);
		funciones = new ArrayGenerico<Funcion>(tamC);
	}

	void agregarCliente(Cliente* cliente) {
		clientes->agregar(cliente);
	}

	void agregarSala(Sala* sala) {
		salas->agregar(sala);
	}

	void agregarPelicula(Pelicula* pelicula) {
		peliculas->agregar(pelicula);
	}

	void agregarFuncion(Funcion* funcion) {
		funciones->agregar(funcion);
	}

	void mostrarTodo() {
		cout << endl << "Clientes: " << endl;
		clientes->mostrar();
		cout << endl << "Salas: " << endl;
		salas->mostrar();
		cout << endl << "Peliculas: " << endl;
		peliculas->mostrar();
		cout << endl << "Funciones: " << endl;
		funciones->mostrar();
	}
};