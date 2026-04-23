#pragma once
#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
	string codigo;
	string titulo;
	string autor;
	bool estado;
	int vecesPrestado;
public:

	Libro(const string& codigo, const string& titulo, const string& autor)
		: codigo(codigo), titulo(titulo), autor(autor)
	{
		this->estado = true;
		this->vecesPrestado = 0;
	}
	string getCodigo() {
		return codigo;
	}

};