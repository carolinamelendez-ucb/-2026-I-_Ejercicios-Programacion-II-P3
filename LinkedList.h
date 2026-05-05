#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {
private:
	Node<T>* primerNodo; //head/cabeza
public:
	LinkedList() {
		primerNodo = nullptr;
	}

	void agregar(T nuevoValor) {
		if (primerNodo == nullptr) {
			primerNodo = new Node<T>(nuevoValor);
		}
		else {
			Node<T>* actual = primerNodo;
			while (actual->getSiguiente() != nullptr) {
				actual = actual->getSiguiente();
			}
			actual->setSiguiente(new Node<T>(nuevoValor));
		}
	}

	void mostrar() {
		Node<T>* actual = primerNodo;
		while (actual != nullptr) {
			cout << "Valor: " << actual->getValor() << endl;
			actual = actual->getSiguiente();
		}
	}
};