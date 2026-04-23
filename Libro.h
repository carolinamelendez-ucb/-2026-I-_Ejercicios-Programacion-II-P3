#pragma once
#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
	int codigo;
	string titulo;
	string autor;
	string estado;
	int vecesPrestado;
public:
	Libro(int codigo, const string& titulo, const string& autor, const string& estado, int vecesPrestado)
		: codigo(codigo), titulo(titulo), autor(autor), estado(estado), vecesPrestado(0)
	{
	}
};
