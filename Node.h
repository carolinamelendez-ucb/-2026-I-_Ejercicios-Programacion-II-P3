#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T>
class Node {
private:
	T* dato;
	Node<T>* ptrSiguiente;
public:
	Node(T* nuevoDato) {
		this->dato = nuevoDato;
		this->ptrSiguiente = nullptr;
	}
	void agregarSiguiente(T* nuevoDato) {
		this->ptrSiguiente = new Node<T>(nuevoDato);
	}
	T* getDato() {
		return dato;
	}
	Node<T>* getSiguiente() {
		return ptrSiguiente;
	}
};