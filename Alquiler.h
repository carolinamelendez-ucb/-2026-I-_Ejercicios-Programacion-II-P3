#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Vehiculo.h"
using namespace std;
class Alquiler {
private:
	Cliente* cliente;
	Vehiculo* vehiculo;
	int dias;
	double total;
public:
	Alquiler(Cliente* cliente, Vehiculo* vehiculo, int dias)
		: cliente(cliente), vehiculo(vehiculo), dias(dias)
	{
		this->total = calcularTotal();
	}
	double calcularTotal() {
		double costo = vehiculo->calcularCosto(dias);
		double descuento = cliente->calcularDescuento();
		return costo - (costo * descuento);
	}
	void mostrar() {
		cout << "CI del Cliente: " << cliente->getCi() << endl;
		cout << "Nombre del Cliente: " << cliente->getNombre() << endl;
		cout << "Vehiculo Placa: " << vehiculo->getPlaca() << endl;
		cout << "Dias: " << dias << endl;
		cout << "Costo base por dia: " << vehiculo->getCostoBase() << endl;
		cout << "Descuento aplicado: " << (cliente->calcularDescuento() * 100) << "%" << endl;
		cout << "Total: " << calcularTotal() << endl;
	}
};