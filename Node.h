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
	Node(T* nvoDato){
		this->dato = nvoDato;
		this->ptrSiguiente = nullptr;
	}

	void agregarSiguiente(T* nvoDato){
		ptrSiguiente = new Node(nvoDato);
	}

	T* getDato() {
		return dato;
	}

	Node<T>* getSiguiente(){
		return ptrSiguiente;
	}

	void setDato(T* nvoDato){
		this->dato = nvoDato;
	}

};