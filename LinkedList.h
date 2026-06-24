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

	void agregar(T* nuevoValor) {
		if (cabeza == nullptr) {
			cabeza = new Node<T>(nuevoValor);
		}
		else {
			Node<T>* aux = cabeza;
			while (aux->getPtrSiguiente() != nullptr) {
				aux = aux->getPtrSiguiente();
			}
			aux->agregar(nuevoValor);
		}
	}

	template<typename K>
	T* buscar(K valorBuscado, bool (*funcion)(K, T*)) {
		Node<T>* aux = cabeza;
		while (aux != nullptr) {
			if (funcion(valorBuscado, aux->getValor())) {
				return aux->getValor();
			}
			aux = aux->getPtrSiguiente();
		}
		return nullptr;
	}

	template<typename K>
	bool buscarBool(K valorBuscado, bool (*funcion)(K, T*)) {
		Node<T>* aux = cabeza;
		while (aux != nullptr) {
			if (funcion(valorBuscado, aux->getValor())) {
				return true;
			}
			aux = aux->getPtrSiguiente();
		}
		return false;
	}

	int contar() {
		Node<T>* aux = cabeza;
		int contar = 0;
		while (aux != nullptr) {
			contar++;
			aux = aux->getPtrSiguiente();
		}
		return contar;
	}

	template<typename K>
	int contarCriterio(K valorBuscado, bool (*funcion)(K, T*)) {
		Node<T>* aux = cabeza;
		int contar = 0;
		while (aux != nullptr) {
			if (funcion(valorBuscado, aux->getValor())) {
				contar++;
			}
			aux = aux->getPtrSiguiente();
		}
		return contar;
	}

	T* obtenerPorIndice(int indice) {
		Node<T>* aux = cabeza;
		int i = 0;
		while (aux != nullptr) {
			if (i == indice) {
				return aux->getValor();
			}
			i++;
			aux = aux->getPtrSiguiente();
		}
		return nullptr;
	}

	template<typename K>
	void mostrarCriterio(K valorBuscado, bool (*funcion)(K, T*)) {
		Node<T>* aux = cabeza;
		while (aux != nullptr) {
			if (funcion(valorBuscado, aux->getValor())) {
				aux->getValor()->mostrar();
			}
			aux = aux->getPtrSiguiente();
		}
	}

	T* buscarMayor(bool (*funcion)(T*, T*)) {
		if (cabeza == nullptr) {
			return nullptr;
		}
		else {
			Node<T>* aux = cabeza;
			T* Mayor = aux->getValor();
			while (aux != nullptr) {
				if (funcion(Mayor, aux->getValor())) {
					Mayor = aux->getValor();
				}
				aux = aux->getPtrSiguiente();
			}
			return Mayor;
		}
	}

	void ordenar(bool (*funcion)(T*, T*)) {
		Node<T>* aux = cabeza;
		while (aux != nullptr) {
			Node<T>* aux2 = aux->getPtrSiguiente();
			while (aux2 != nullptr) {
				if (funcion(aux2->getValor(), aux->getValor())) {
					T* temp = aux->getValor();
					aux->setValor(aux2->getValor());
					aux2->setValor(temp);
				}
				aux2 = aux2->getPtrSiguiente();
			}
			aux = aux->getPtrSiguiente();
		}
	}

};