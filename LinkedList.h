#pragma once
#include "Nodo.h"

template <class T>
class LinkedList {
private:
	Nodo<T>* cabeza;
public:
	LinkedList() {
		cabeza = nullptr;
	}
	void agregar(T* valor) {
		Nodo<T>* nuevo = new Nodo<T>(valor);
		if (cabeza == nullptr) {
			cabeza = nuevo;
			return;
		}
		Nodo<T>* actual = cabeza;
		while (actual->getSiguiente() != nullptr) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
	void mostrar() {
		Nodo<T>* actual = cabeza;
		while (actual != nullptr) {
			actual->getValor()->mostrar();
			actual = actual->getSiguiente();
		}
	}
};