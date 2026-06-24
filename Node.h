#pragma once
#include <iostream>
#include<string>
using namespace std;

template<class T>
class Node {
private:
	T* valor;
	Node<T>* ptrSgte;
public:
	Node(T* nuevoDato) : valor(nuevoDato), ptrSgte(nullptr) {

	}

	T* getValor() {
		return valor;
	}
	Node<T>* getPtrSiguiente() {
		return ptrSgte;
	}

	void agregar(T* nuevoValor)
	{
		ptrSgte = new Node <T>(nuevoValor);
	}

	void setValor(T* nuevoDato) {
		valor = nuevoDato;
	}
};