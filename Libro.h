#pragma once
#include <iostream>
#include <string>
#include <exception>            

using namespace std;


class Libro {
private:
	int codigo;
	string titulo;
	bool estado;
	//prestado = false
	// disponible = true
	int vecesPrestado;
public:
	Libro(int codigo, const string& titulo, bool estado, int vecesPrestado)
		: codigo(codigo), titulo(titulo), estado(estado), vecesPrestado(vecesPrestado)
	{}

	int getCodigo() {
		return codigo;
	}

	bool getEstado() {
		return estado;
	}

	void cambiarEstado() {
		this->estado = false;
	}
	 
	int getVecesPrestado() {
		return vecesPrestado;
	}

	void mostrarLi() {
		cout << "Titulo:"<<titulo << endl;
		cout << "Codigo:"<<codigo << endl;
		cout << "Estado:"<<estado << endl;
		cout << "Veces prestado:"<<vecesPrestado << endl;
		cout << "Titulo:"<<titulo << endl;
	}

};