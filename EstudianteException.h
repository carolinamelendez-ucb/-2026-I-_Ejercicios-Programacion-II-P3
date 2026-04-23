#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "LibroException.h"

using namespace std;

class Estudiante :public exception
{
private:
	string ci;
	string nombre;
	Libro* libroAsignado;
public:
	Estudiante(string ci, string nombre)
	{
		this->libroAsignado = nullptr;
		this->ci = ci;
		this->nombre = nombre;
	}
	void asignarLibro(Libro* nuevoLibro)
	{
		libroAsignado = nuevoLibro;
	}
	string getCi()
	{
		return ci;
	}
};

