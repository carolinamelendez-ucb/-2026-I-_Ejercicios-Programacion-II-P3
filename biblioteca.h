#pragma once
#include <iostream>
#include<string>
#include<exception>
#include"Libro.h"
#include"Estudinate.h"
#include"Excepciones.h"
using namespace std;
class biblioteca {
private:
	string nombre;
	VectorEstudiantes* listaE;
	VectorLibros* listaL;
public:
	biblioteca(int cantidadMaxL, int cantidadMaxEs) {
		this->listaE = new VectorEstudiantes(cantidadMaxEs);
		this->listaL = new VectorLibros(cantidadMaxL);
	}
	void AgregarLibro(libro* libros) {
		this->listaL->agregar(libros);
	}
	void AgregarEstudiantes(Estudiante* Estudiante) {
		this->listaE->agregar(Estudiante);
	}

	void mostrarTodo() {
		cout << "lista de estudiante" << endl;
		listaE->mostrar();
		cout << "lista de libros" << endl;
		listaL->mostrar();
	}
};