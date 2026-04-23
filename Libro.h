#pragma once
#include <iostream>
#include <string>

using namespace std;

class Libro {
private:
	int codigo;
	string titulo;
	string autor;
	bool estado;
	int vecesPrestado;
public:
	Libro(int codigo, const string& titulo, const string& autor, bool estado)
		: codigo(codigo), titulo(titulo), autor(autor), estado(estado), vecesPrestado(0)
	{
	}

	int getCodigo() { return codigo; }

	void aumentarPrestamo() { vecesPrestado++; }

	int getPrestamos() { return vecesPrestado; }

	void mostrar() {
		cout << "Codigo: " << codigo << endl;
		cout << "Titulo: " << titulo << endl;
		cout << "Autor: " << autor << endl;
		cout << "Veces prestado: " << vecesPrestado << endl;
	}
};