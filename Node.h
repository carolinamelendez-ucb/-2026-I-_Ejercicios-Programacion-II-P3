#pragma once
#include <iostream>

using namespace std;

template<typename U>
class Node {
private:
	U valor;
	Node<U>* ptrSiguiente;
public:
	Node(U valor) {
		this->valor = valor;
		ptrSiguiente = nullptr;
	}

	U getValor() { return valor; }
	void setValor(U valor) { this->valor = valor; }
	Node<U>* getSiguiente() { return ptrSiguiente; }
	void setSiguiente(Node<U>* nuevoSiguiente) { ptrSiguiente = nuevoSiguiente; }

	void agregarSiguiente(U nuevoValor) {
		this->ptrSiguiente = new Node<U>(nuevoValor);
	}
};