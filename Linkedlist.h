#pragma once
#include "Node.h"

class LinkedList {
private:
	Node* primerNodo;	// (head) cabeza
public:
	LinkedList() {
		primerNodo = nullptr;		// esta vacio;
	}

	void agregar(string nvoValor) {
		primerNodo = new Node(nvoValor);
	}

	void mostrar() {
		cout << "Valor: "<<primerNodo->getValor() << endl;
	}


	// como? hago un sig...

	void aniadirMas(string unoMas) {
		//primerNodo->setSiguiente();
		primerNodo->agregarSiguiente(unoMas);

	}


};

