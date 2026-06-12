#pragma once
#include "Node.h"

template<class T>
class LinkedList {
private:
	Node<T>* primerNodo;
public:
	LinkedList() {
		this->primerNodo = nullptr;
	}

	void agregar(T* nvoDato) {
		if (primerNodo == nullptr) {
			primerNodo = new Node<T>(nvoDato);
		}
		else {
			Node<T>* aux = primerNodo;
			while (aux->getSiguiente() != nullptr) {
				aux = aux->getSiguiente();
			}
			aux->agregarSiguiente(nvoDato);
		}
	}

	template<typename U>
	T* buscar(U valor,bool(*funcion)(U,T*)){
		Node<T>* aux = primerNodo;
		while (aux!=nullptr) {
			if (funcion(valor,aux->getDato())){
				return aux->getDato();
			}
			aux = aux->getSiguiente();
		}
		return nullptr;
	}

	void mostrar() {
		Node<T>* aux = primerNodo;
		while (aux!=nullptr) {
			aux->getDato()->mostrar();
			aux = aux->getSiguiente();
		}
	}

	template<typename U>
	void mostrarCondicion(U valor,bool(*funcion)(U,T*)) {
		Node<T>* aux = primerNodo;
		while (aux!=nullptr) {
			if (funcion(valor, aux->getDato())) {
				aux->getDato()->mostrar();
			}
			aux = aux->getSiguiente();
		}
	}

	int contador() {
		Node<T>* aux = primerNodo;
		int contar = 0;
		while (aux!=nullptr){
			contar++;
			aux = aux->getSiguiente();
		}
		return contar;
	}

	template<typename U>
	int contarCondicion(U valor,bool(*funcion)(U,T*)){
		int contar=0;
		Node<T>* aux = primerNodo;
		while (aux!=nullptr) {
			if (funcion(valor, aux->getDato())) {
				contar++;
			}
			aux=aux->getSiguiente();
		}
		return contar;
	}

	int sumaValores(int(*funcion)(T*)){
		int suma = 0;
		Node<T>* aux = primerNodo;
		while (aux != nullptr) {
			suma = funcion(aux->getDato()) + suma;
			aux = aux->getSiguiente();
		}
		return suma;
	}

	// ORDENAR EL LINKEDLIST

	void ordenar(bool(*funcion)(T*,T*)) {
		if (primerNodo == nullptr || primerNodo->getSiguiente() == nullptr) {
			return;
		}

		bool huboCambios = true;

		while (huboCambios) {
			huboCambios = false;
			Node<T>* aux = primerNodo;
			while (aux->getSiguiente()!= nullptr) {
				T* datoActual = aux->getDato();
				T* datoSiguiente = aux->getSiguiente()->getDato();
				if (funcion(datoActual,datoSiguiente)){
					aux->setDato(datoSiguiente);
					aux->getSiguiente()->setDato(datoActual);
					huboCambios = true;
				}
				aux=aux->getSiguiente();
			}
		}
	}



	~LinkedList() {
	
	}

	

};