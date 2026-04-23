#pragma once
#include <string>
#include <iostream>
#include <exception>
using namespace std;
class Libro {
private:
	int codigo;
	string titulo;
	string autor;
	bool estado;
	int vecesPrestado;
public:
	Libro(int codigo, string titulo, string autor, bool estado, int vecesPrestado) {
		this->codigo = codigo;
		this->titulo = titulo;
		this->autor = autor;
		this->estado = estado;
		this->vecesPrestado = vecesPrestado;
	}
	void mostrar() {
		cout << "Titulo del libro: " << titulo<< endl;
		cout << "Autor del libro: " << autor << endl;
	}
	bool getEstado() { return estado; }
	int getCodigo() { return codigo; }
};