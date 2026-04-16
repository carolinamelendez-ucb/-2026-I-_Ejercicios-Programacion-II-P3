#pragma once
#include <iostream>
#include <string>
#include "Docente.h"
using namespace std;

class ListaDoc {
private:
	int tamanio;
	int cantidad;
	Docente** ListaDocentes;
public:
	ListaDoc(int tam) {
		this->cantidad = 0;
		this->tamanio = tam;
		this->ListaDocentes = new Docente * [tam];
	}

	void agregarDocente(Docente* nvoEstu) {
		if (cantidad < tamanio) {
			ListaDocentes[cantidad] = nvoEstu;
			cantidad++;
		}
		else {
			cout << "No se puede agregar mas Docentes" << endl;
		}
	}

	Docente* buscarCi(int ciBuscado) {
		for (int i = 0;i < cantidad;i++) {
			if (ListaDocentes[i]->getCiD() == ciBuscado) {
				return ListaDocentes[i];
			}
		}
		return nullptr;
	}

	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			ListaDocentes[i]->mostrard();
		}
	}
	void verificarDuplicados() {
		for (int i = 0;i < cantidad;i++) {
			for (int j = i - 1;j < cantidad;j++) {
				if (ListaDocentes[i]->getCiD() == ListaDocentes[j]->getCiD()) {
					cout << "Hay carnets iguales" << ListaDocentes[i]->getCiD() << endl;
				}
			}
		}
	}
	
	~ListaDoc() {
		for (int i = 0;i < cantidad;i++) {
			delete ListaDocentes[i];
		}
		delete[] ListaDocentes;
	}


};