#pragma once
#include "Node.h"

template<class T>
class LinkedList {
private:
	Node<T>* cabeza;
public:
	LinkedList() {
		this->cabeza = nullptr;
	}
	void agregar(T* nuevoDato) {
		if (cabeza == nullptr) {
			cabeza = new Node<T>(nuevoDato);
		}
		else {
			Node<T>* aux = cabeza;
			while (aux->getSiguiente() != nullptr) {
				aux = aux->getSiguiente();
			}
			aux->agregarSiguiente(nuevoDato);
		}
	}
	template<typename U>
	T* buscar(U valorBuscado, bool(*comparar)(U, T*)) {
		Node<T>* aux = cabeza;
		while (aux != nullptr) {
			if (comparar(valorBuscado, aux->getDato())) {
				return aux->getDato();
			}
			aux = aux->getSiguiente();
		}
		return nullptr;
	}
	template<typename U> //PARA TEST 14: se agrega el metodo buscarMayor para devolver el que tenga la mayor cantidad de un valor buscado
	T* buscarMayor(U valorBuscado, bool(*comparar)(U, T*), bool(*mayor)(T*, T*)) {
		Node<T>* aux = cabeza;
		T* claseMayor = nullptr;
		while (aux != nullptr) {
			T* claseActual = aux->getDato();
			if (comparar(valorBuscado, aux->getDato())) {
				if (mayor(claseActual, claseMayor)) {
					claseMayor = claseActual;
				}
			}
			aux = aux->getSiguiente();
		}
		return claseMayor;
	}
	template<typename U, typename V>
	T* buscarDoble(U valorBuscado1, V valorBuscado2, bool(*comparar)(U, V, T*)) {
		Node<T>* aux = cabeza;
		while (aux != nullptr) {
			if (comparar(valorBuscado1, valorBuscado2, aux->getDato())) {
				return aux->getDato();
			}
			aux = aux->getSiguiente();
		}
		return nullptr;
	}
	template<typename U>
	void mostrarCondicion(U valor, bool(*comparar)(U, T*)) {
		Node<T>* aux = cabeza;
		while (aux != nullptr) {
			if (comparar(valor, aux->getDato())) {
				aux->getDato()->mostrar();
			}
			aux = aux->getSiguiente();
		}
	}
	void mostrar() {
		Node<T>* aux = cabeza;
		while (aux != nullptr) {
			aux->getDato()->mostrar();
		}
		aux = aux->getSiguiente();
	}
};
