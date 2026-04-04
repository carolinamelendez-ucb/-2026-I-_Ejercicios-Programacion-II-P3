#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class TransporteTerrestre:public Transporte
{
public:
	TransporteTerrestre(int placa)
		:Transporte(placa)
	{}

	float calcularCosto(float distancia) override
	{
		float costo = distancia * 0.5;
		if (distancia > 100)
		{
			costo = costo * 1.10;
		}
		return costo;
	}
	void mostrarInfo()override
	{
		cout << "transporte terrestre" << endl;
		cout << "numero de placa: " << placa <<endl;
	
	}
};

