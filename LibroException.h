#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Libro :public exception
{
private:
	string codigo;
	string titulo;
	string autor;
	string estado;
	int vecesPrestado;
public:

	Libro(const string& codigo, const string& titulo, const string& autor, const string& estado, int vecesPrestado)
		: codigo(codigo), titulo(titulo), autor(autor), estado(estado), vecesPrestado(vecesPrestado)
	{}

	string getCodigo()
	{
		return codigo;
	}
};
