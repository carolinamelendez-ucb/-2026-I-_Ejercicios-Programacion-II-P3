#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
template <typename T>
class LinkedList { 
private:
	Node<T>* primerNodo;
public:
	LinkedList() {
		primerNodo = nullptr;
	}
	void agregar (T nuevoValor) {
		Node<T>* nuevoNodo = new Node<T>(nuevoValor);
		if (primerNodo == nullptr) {
			primerNodo = nuevoNodo;
			return;
		}
		else {
			Node<T>* nodoActual = primerNodo;
			while (nodoActual->getPtrSiguiente() != nullptr) {
				nodoActual = nodoActual->getPtrSiguiente();
			}
			nodoActual->setPtrSiguiente(nuevoNodo);
		}
	}
	void mostrar() {
		Node<T>* nodoActual = primerNodo;
		while (nodoActual != nullptr) {
			cout << "Valor: " << nodoActual->getValor() << endl;
			nodoActual = nodoActual->getPtrSiguiente();
		}
	}
};
