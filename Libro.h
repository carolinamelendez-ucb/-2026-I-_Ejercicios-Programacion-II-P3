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
	Libro(int codigo, string titulo, string autor) {
		this->codigo = codigo;
		this->titulo = titulo;
		this->autor = autor;
		this->estado = "Disponible";
		this->vecesPrestado = 0;
	}
	int getCodigo() {
		return codigo;
	}
	void prestar() {
		estado = "Prestado";
		vecesPrestado++;
	}
	void devolver() {
		estado = "Disponible";
	}
	void Estado(string newEstado) {
		estado = newEstado;
	}
	int getVecesPrestado() { 
		return vecesPrestado; 
	}
};
