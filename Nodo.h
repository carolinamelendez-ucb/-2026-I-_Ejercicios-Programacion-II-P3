#pragma once

#include <iostream>
#include <string>
using namespace std;
template <class T>
class Node {
	private:
		T valor;
		Node* ptrSiguiente;
public:
	Node(T nuevoValor) {
		valor = nuevoValor;
		ptrSiguiente = nullptr;
	}

	T getValor() {
		return valor;
	}

	void setSiguiente(Node* nuevo) {
		ptrSiguiente = nuevo;
	}

	Node* getSiguiente() {
		return ptrSiguiente;
	}

};