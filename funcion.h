#pragma once
#include <iostream>
#include <string>
#include "vecCliente.h"
#include "vecFilas.h"
using namespace std;
class Funcion {
private:
	int numMax;
	VecClientes* cliente;
	VecSala* sala;
public:
	Funcion(int numMax) {
		this->numMax = numMax;
		this->cliente = new VecClientes(numMax);
		this->sala = new VecSala(numMax);
	}
	void mostrar() {
		cout << "El numero de salas es: "<< sala->mostrar() << endl;
		cout << "El numero de clientes es: "<<cliente->mostrar()<< endl;
	}
};