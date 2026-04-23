#pragma once
#include <iostream>
#include<string>
#include<exception>
#include"Excepciones.h"
using namespace std;
class Estudiante {
private:
	int ci;
	string nombre;
	int libroAsignado;

public:
	Estudiante(int ci, const string& nombre, int libroAsignado)
		: ci(ci), nombre(nombre), libroAsignado(libroAsignado)
	{
	}
	void mostrar() {
		cout << "El ci: " << ci << endl;
		cout << "El nombre: " << nombre << endl;
		cout << "El libro: " << libroAsignado << endl;
	}
};
class VectorEstudiantes {
private:
	int tamanio;
	int cantidad;
	Estudiante** lista;
public:
	VectorEstudiantes(int tamanio) {
		this->cantidad = 0;
		this->tamanio = tamanio;
		this->lista = new Estudiante * [tamanio];
	}
	void agregar(Estudiante* Estudiantenuevo) {
		if (cantidad < tamanio) {
			lista[cantidad] = Estudiantenuevo;
			cantidad++;
		}
		else {
			throw VectorException();
		}
	}
	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			cout << "El Estudiante" <<i <<"Es: "<<endl;
			lista[i]->mostrar();
		}
	}
};