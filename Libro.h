#pragma once
#include <iostream>
#include<string>
#include<exception>
#include"Excepciones.h"
using namespace std;
class libro {
private:
	int codigo;
	string titulo;
	string autor;
	string estado;
	int vecesPrestado;
public:
	libro(int codigo, const string& titulo, const string& autor, const string& estado, int vecesPrestado)
		: codigo(codigo), titulo(titulo), autor(autor), estado(estado), vecesPrestado(vecesPrestado)
	{
	}
	void mostrar() {
		cout << "El codigo" << codigo << endl;
		cout << "El titulo" << titulo << endl;
		cout << "El Autor" << autor << endl;
		cout << "El Estado" << estado << endl;
		cout << "veces Prestado" << vecesPrestado << endl;
	}
};
class VectorLibros {
private:
	int tamanio;
	int cantidad;
	libro** lista;
public:
	VectorLibros(int tamanio) {
		this->cantidad = 0;
		this->tamanio = tamanio;
		this->lista = new libro * [tamanio];
	}
	void agregar(libro* nuevolibro) {
		if (cantidad < tamanio) {
			lista[cantidad] = nuevolibro;
			cantidad++;
		}
		else {
			throw VectorException();
		}
	}
	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			cout << "El libro" << i << "Es: " << endl;
			lista[i]->mostrar();
		}
	}
};