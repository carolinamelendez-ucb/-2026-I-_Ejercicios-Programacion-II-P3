#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Node {
private:
	T valor;
	Node<T>* ptrSiguiente;
public:
	Node(T nuevoValor) {
		valor = nuevoValor;
		ptrSiguiente = nullptr;
	}
	//setters y getters para valor
	void setValor(T nuevoValor) {
		valor = nuevoValor;
	}
	T getValor() {
		return valor;
	}
	//setters y getters para ptrSiguiente
	void setPtrSiguiente(Node* nuevoPtrSiguiente) {
		ptrSiguiente = nuevoPtrSiguiente;
	}
	Node* getPtrSiguiente() {
		return ptrSiguiente;
	}
};