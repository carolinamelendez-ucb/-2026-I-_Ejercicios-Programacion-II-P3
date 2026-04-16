#pragma once
#include <iostream>
#include <string>
#include "Curso.h"
using namespace std;

class ListaCurso {
private:
	int tamanio;
	int cantidad;
	Curso** ListaCursos;
public:
	ListaCurso(int tam) {
		this->cantidad = 0;
		this->tamanio = tam;
		this->ListaCursos = new Curso * [tam];
	}

	void agregarCurso(Curso* nvoEstu) {
		if (cantidad < tamanio) {
			ListaCursos[cantidad] = nvoEstu;
			cantidad++;
		}
		else {
			cout << "No se puede agregar mas Cursos" << endl;
		}
	}

	Curso* buscarCi(int CodigoBus) {
		for (int i = 0;i < cantidad;i++) {
			if (ListaCursos[i]->getCodigo() == CodigoBus) {
				return ListaCursos[i];
			}
		}
		return nullptr;
	}


	void verificarDuplicados() {
		for (int i = 0;i < cantidad;i++) {
			for (int j = i - 1;j < cantidad;j++) {
				if (ListaCursos[i]->getCodigo() == ListaCursos[j]->getCodigo()) {
					cout << "Hay carnets iguales" << ListaCursos[i]->getCodigo() << endl;
				}
			}
		}
	}


	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			ListaCursos[i]->mostrar();
			cout << "------------------------" << endl;
		}
	}


	~ListaCurso() {
		for (int i = 0;i < cantidad;i++) {
			delete ListaCursos[i];
		}
		delete[] ListaCursos;
	}


};