#pragma once
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Nodo {
private: 
	T valor;
	Nodo<T>* siguiente;

public:
	Nodo(T nuevoValor) {
		this->valor = nuevoValor;
		this->siguiente = nullptr;
	}

	void setValor(T nuevoValor) {
		this->valor = nuevoValor;
	}

	T getValor() {
		return this->valor;
	}

	void setSiguiente(Nodo<T>* nuevoSiguiente) {
		this->siguiente = nuevoSiguiente;
	}

	Nodo<T>* getSiguiente() {
		return this->siguiente;
	}

	void agregarSiguiente(T nuevoValor) {
		this->siguiente = new Nodo<T>(nuevoValor);
	}

	void mostrarValor() {
		cout << this->valor << endl;
	}

};