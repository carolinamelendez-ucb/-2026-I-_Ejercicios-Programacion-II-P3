#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
	string valor;
	Node* ptrSiguiente;
public:
	Node(string nuevoValor)
	{
		this->valor = nuevoValor;
		this->ptrSiguiente = nullptr;
	}
	void setValor(string nuevoValor)
	{
		valor = nuevoValor;
	}
	string getValor()
	{
		return valor;
	}
	void setSiguiente(Node* nuevoSiguiente)
	{
		ptrSiguiente = nuevoSiguiente;
	}
	Node* getSiguiente()
	{
		return ptrSiguiente;
	}

	void agregarSiguiente(string nuevoValor)
	{
		
		this->ptrSiguiente = new Node(nuevoValor);
	}
};

