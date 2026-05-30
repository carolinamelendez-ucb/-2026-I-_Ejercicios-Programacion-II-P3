#pragma once
#include "Node.h"

template<class T>
class LinkedList {
private:
	Node<T>* primerNodo;
public:
	LinkedList() {
		primerNodo = nullptr;
	}

	void agregar(T* nvoDato) {
		if (primerNodo==nullptr) {
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
	T* buscar(U valor, bool(*funcion)(U, T*)) {
		Node<T>* aux = primerNodo;
		while (aux!=nullptr) {
			if (funcion(valor,aux->getDato())) {
				return aux->getDato();
			}
			aux = aux->getSiguiente();
		}
		return nullptr;
	}

	// op. 1			esto fue una opcion q teniamos, pero no la estoy utilizando

	template<typename U>
	void mostrarCondicion(U valor, bool(*funcion)(U, T*)) {
		Node<T>* aux = primerNodo;
		while (aux != nullptr) {
			if (funcion(valor, aux->getDato())) {
				return aux->getDato()->mostrar();
			}
			aux = aux->getSiguiente();
		}
	}

	// op. 2			en cambio esta si la utlizo, y queria ver si esta forma esta bien


	void mostrarCondicion2(bool(*funcion)(T*)) {
		Node<T>* aux = primerNodo;
		while (aux != nullptr) {
			if (funcion(aux->getDato())) {
				return aux->getDato()->mostrar();
			}
			aux = aux->getSiguiente();
		}
	}


	// op. 1				 aqui pasa lo mismo, es la forma en la q hicimos

	template<typename U>
	int contarCondicion(U valor,bool(*funcion)(U, T*)) {
		int contar = 0;
		Node<T>* aux = primerNodo;
		while (aux != nullptr) {
			if (funcion(valor, aux->getDato())) {
				contar++;
			}
			aux = aux->getSiguiente();
		}
		return contar;
	}

	// op. 2							aqui lo cambie solo unas cosas pequeñas 

	int contarCondicion2(bool(*funcion)(T*)) {
		int contar = 0;
		Node<T>* aux = primerNodo;
		while (aux != nullptr) {
			if (funcion(aux->getDato())) {
				contar++;
			}
			aux = aux->getSiguiente();
		}
		return contar;
	}

	void mostrar() {
		Node<T>* aux = primerNodo;
		while (aux != nullptr) {
			aux->getDato()->mostrar();
			aux = aux->getSiguiente();
			cout << endl;
		}
	}

	int contador() {
		int contar = 0;
		Node<T>* aux = primerNodo;
		while (aux!=nullptr) {
			contar++;
			aux = aux->getSiguiente();
		}
		return contar;
	}



};