#pragma once
#include <iostream>
#include <string>
#include "Node.h"


using namespace std;

class Linkedlist
{
private:
	Node* primerNodo;
public:
	Linkedlist()
	{
		this->primerNodo = nullptr;
	}
	void agregar(string nuevoValor)
	{
		if (primerNodo == nullptr)
		{
			primerNodo = new Node(nuevoValor);
		}
		else
		{
			Node* actual = primerNodo;
			while (actual->getSiguiente() != nullptr)
			{
				actual = actual->getSiguiente();
			}
		}
		
	}
	void mostrar()
	{
		Node* actual = primerNodo;
		while (actual != nullptr)
		{
			cout << "valor: " << primerNodo->getValor();
			actual = actual->getSiguiente();
		}
		
	}
};