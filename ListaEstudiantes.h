#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;


class ListaEstu {
private:
	int tamanio;
	int cantidad;
	Estudiante** listaEstudiantes;
public:
	ListaEstu(int tam) {
		this->cantidad = 0;
		this->tamanio = tam;
		this->listaEstudiantes = new Estudiante * [tam];
	}

	void agregarEs(Estudiante* nvoEstu) {
		if (cantidad < tamanio) {
			listaEstudiantes[cantidad] = nvoEstu;
			cantidad++;
		}
		else {
			cout << "No se puede agregar mas estudiantes" << endl;
		}
	}

	Estudiante* buscarCi(int ciBuscado) {
		for (int i = 0;i < cantidad;i++) {
			if (listaEstudiantes[i]->getCi() == ciBuscado) {
				return listaEstudiantes[i];
			}
		}
		return nullptr;
	}

	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			listaEstudiantes[i]->mostrar();
		}
	}

	bool hizoPago(int ciEstu) {
		for (int i = 0;i < cantidad;i++) {
			if (listaEstudiantes[i]->getCi()==ciEstu) {
				return listaEstudiantes[i]->getHizoPagoMat();
			}
		}
		cout << "No se encontro un estudiante con el ci: " << ciEstu << endl;
		return false;
	}

	void verificarDuplicados() {
		for (int i = 0;i < cantidad;i++) {
			for (int j = i - 1;j < cantidad;j++) {
				if (listaEstudiantes[i]->getCi() == listaEstudiantes[j]->getCi()) {
					cout << "Hay carnets iguales"<<listaEstudiantes[i]->getCi()<< endl;
				}
			}
		}
	}


	~ListaEstu() {
		for (int i = 0;i < cantidad;i++) {
			delete listaEstudiantes[i];
		}
		delete[] listaEstudiantes;
	}


};