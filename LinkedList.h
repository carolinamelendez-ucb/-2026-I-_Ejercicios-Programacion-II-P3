#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template<typename U>
class LinkedList {
private:
	Node<U>* primerNodo;
public:
	LinkedList() {
		primerNodo = nullptr;
	}

	void agregar(U nuevoValor) {
		if (primerNodo == nullptr) {
			primerNodo = new Node<U>(nuevoValor);
		}
		else {
			Node<U>* temp = primerNodo;
			while (temp->getSiguiente() != nullptr) {
				temp = temp->getSiguiente();
			}
			temp->agregarSiguiente(nuevoValor);
		}
	}

	void mostrar() {
		Node<U>* temp = primerNodo;
		while (temp != nullptr) {
			cout << "Valor: " << temp->getValor() << endl;
			temp = temp->getSiguiente();
		}
	}
};