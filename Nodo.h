#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Nodo {
private:
	T* valor;
	Nodo<T>* ptrSiguiente;
public:
	Nodo(T* newValor) {
		valor = newValor;
		ptrSiguiente = nullptr;
	}
	void setValor(T* newValor) {
		valor = newValor;
	}
	T* getValor() {
		return valor;
	}
	Nodo<T>* getSiguiente() {
		return ptrSiguiente;
	}
	void setSiguiente(Nodo<T>* newSiguiente) {
		ptrSiguiente = newSiguiente;
	}
};
