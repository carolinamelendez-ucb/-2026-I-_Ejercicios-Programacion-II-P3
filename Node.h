#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	string valor;   // dato
	Node* ptrSiguiente;

public:
	Node(string nvoValor) {
		valor = nvoValor;
		Node* ptrSiguiente;
		ptrSiguiente = nullptr;		// por defecto;
	}

	//setter y getter de VALOR:

	void setValor(string nvoValorsig) {
		valor = nvoValorsig;
	}

	string getValor() {
		return valor;
	}

	//setter y getter de Siguiente:

	void setSiguiente(Node* nvoSiguiente) {
		ptrSiguiente = nvoSiguiente;
	}

	Node* getSiguiente() {
		return ptrSiguiente;
	}

	//Añadir siguiente:

	void agregarSiguiente(string nvoValor2) {
		this->ptrSiguiente = new Node(nvoValor2);
	}



};