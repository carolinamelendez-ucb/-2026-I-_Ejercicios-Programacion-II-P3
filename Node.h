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
	Node(T* nvoDato) {
		dato = nvoDato;
		ptrSiguiente = nullptr;
	}

	Node<T>* getSiguiente() {
		return ptrSiguiente;
	}

	T* getDato() {
		return dato;
	}

	void agregarSiguiente(T* nvoDato) {
		ptrSiguiente = new Node(nvoDato);
	}

};