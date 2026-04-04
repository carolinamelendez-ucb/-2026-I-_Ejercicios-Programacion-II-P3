#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class TransporteMaritimo: public Transporte
{
public:
	TransporteMaritimo(int placa)
		:Transporte(placa)
	{}

	float calcularCosto(float distancia)override
	{
		float costo = distancia * 1.2;
		if (distancia > 500)
		{
			costo = costo + 50;
		}
		return costo;
	}
	void mostrarInfo()override
	{
		cout << "transporte maritimo" << endl;
		cout << "numero de placa: " << placa << endl;
	
	}
};

