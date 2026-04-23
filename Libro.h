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
	Libro(int codigo, const string& titulo, const string& autor, string estado, int vecesPrestado)
		: codigo(codigo), titulo(titulo), autor(autor), estado("Disponible"), vecesPrestado(0)
	{
	}
	int getCodigo() {
		return codigo;
	}
	string getTitulo() {
		return titulo;
	}
	string getEstado() {
		return estado;
	}
	int vecesPrestado() {
		return vecesPrestado;
	}
	void setEstado(string nuevoEstado) {
		estado = nuevoEstado;
	}
	void incrementarEstado() {
		vecesPrestado++;
	}
	void mostrar() {
		cout << "Codigo: " << codigo << endl;
		cout << "Titulo: " << titulo << endl;
		cout << "Autor: " << autor << endl;
		cout << "Estado: " << estado << endl;
		cout << "Veces Prestado: " << vecesPrestado << endl;
	}
};