#pragma once
#include "ArrayGenerico.h"
#include "Sala.h"
#include "Cliente.h"
#include "Pelicula.h"
#include "Funcion.h"

class Sistema
{
private:
	ArrayGenerico<Sala>* listaSalas;
	ArrayGenerico<Pelicula>* listaPeliculas;
	ArrayGenerico<Funcion>* listaFunciones;
public:
	Sistema(int tamanioSalas, int tamanioPeliculas, int tamanioFunciones)
	{
		this->listaSalas = new ArrayGenerico<Sala>(tamanioSalas);
		this->listaPeliculas = new ArrayGenerico<Pelicula>(tamanioPeliculas);
		this->listaFunciones = new ArrayGenerico<Funcion>(tamanioFunciones);
	}
	void registrtarSala(Sala* nuevaSala)
	{
		listaSalas->agregar(nuevaSala);
	}
	void mostrarSalas()
	{
		listaSalas->mostrar();
	}	
	void registrtarPeliculas(Pelicula* nuevaPelicula)
	{
		listaPeliculas->agregar(nuevaPelicula);
	}
	void mostrarPeliculas()
	{
		listaPeliculas->mostrar();
	}
	void registrtarFunciones(Funcion* nuevaFuncion)
	{
		listaFunciones->agregar(nuevaFuncion);
	}
	void mostrarFunciones()
	{
		listaFunciones->mostrar();
	}
};

