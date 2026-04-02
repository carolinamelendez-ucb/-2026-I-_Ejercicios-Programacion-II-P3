#pragma once
#include <iostream>
#include <string>
#include "Proyecto.h"

using namespace std;

class ProyectoExterno : public Proyecto
{
private:
	float costoManoObra;
	float costoMateriales;
	float costoSeguroAccidentes;
	float otrosGastos;
public:
	ProyectoExterno(string nombre, int presupuesto, int codigo, float costoManoObra, float costoMateriales, float costoSeguroAccidentes)
		: Proyecto(nombre, presupuesto, codigo)
	{
		this->costoManoObra = costoManoObra;
		this->costoMateriales = costoMateriales;
		this->costoSeguroAccidentes = costoSeguroAccidentes;
		this->otrosGastos = 1.25;// este sera el 25% por ser proyecto externo
	}

	float calcularCosto() override
	{
		return presupuesto + (costoManoObra + costoMateriales) * otrosGastos + costoSeguroAccidentes;
	}
	void mostrarInfo()
	{
		cout << "nombre: " << nombre << endl;
		cout << "presupuesto: " << presupuesto << endl;
		cout << "codigo: " << codigo << endl;
		cout << "costo de la ManoObra: " << costoManoObra << endl;
		cout << "costo de materiales: " << costoMateriales << endl;
		cout << "costo del Seguro de Accidentes: " << costoSeguroAccidentes << endl;
		cout << "Costo final del protecto: " << calcularCosto() << endl;
	}

};

