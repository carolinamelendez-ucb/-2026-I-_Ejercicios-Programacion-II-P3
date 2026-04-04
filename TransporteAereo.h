#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class TransporteAereo: public Transporte
{
public:
	TransporteAereo(int placa) :
		Transporte(placa)
	{
	}
	float calcularCosto(float distancia)override
	{
		float costo = distancia * 2.0;
		if (distancia > 1000)
		{
			costo = costo * 0.85;
		}
		return costo;
	}
	void mostrarInfo()override
	{
		cout << "transporte aereo" << endl;
		cout << "numero de placa: " << placa << endl;
	
	}

};
