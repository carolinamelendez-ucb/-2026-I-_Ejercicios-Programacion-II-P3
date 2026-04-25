#pragma once
#include "ArrayGenerico.h";
#include "Funciones.h"
#include "Sala.h"
#include "Pelicula.h"
#include "Cliente.h"

class SistemaCine {
private:
	ArrayGenerico<Cliente>* listaClientes;
	ArrayGenerico<Sala>* listaSalas;
	ArrayGenerico<Pelicula>* listaPeliculas;
	ArrayGenerico<Funcion>* listaFunciones;
public:
	SistemaCine(int tamanioCliente, int tamanioSala, int tamanioPelis, int tamanioFunciones) {
		this->listaClientes = new ArrayGenerico<Cliente>(tamanioCliente);
		this->listaSalas = new ArrayGenerico<Sala>(tamanioSala);
		this->listaPeliculas = new ArrayGenerico<Pelicula>(tamanioPelis);
		this->listaFunciones = new ArrayGenerico<Funcion>(tamanioFunciones);
	}
	//clientes
	void registrarClientes(Cliente * nuevoCliente) {
		listaClientes->agregar(nuevoCliente);
	}

	void mostrarClientes() {
		listaClientes->mostrar();
	}
	//salas
	void registrarSalas(Sala* nuevoSala) {
		listaSalas->agregar(nuevoSala);
	}

	void mostrarSalas() {
		listaSalas->mostrar();
	}
	//pelicylas
	void registrarPeliculas(Pelicula* nuevoPelicula) {
		listaPeliculas->agregar(nuevoPelicula);
	}

	void mostrarPeliculas() {
	listaPeliculas->mostrar();
	}
	//funciones
	void registrarFunciones(Funcion* nuevoFuncion) {
		listaFunciones->agregar(nuevoFuncion);
	}

	void mostrarFunciones() {
		listaFunciones->mostrar();
	}
	

};