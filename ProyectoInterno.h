#pragma once
#include <iostream>
#include <string>
#include "Proyecto.h"

using namespace std;

class ProyectoInterno: public Proyecto
{
private:
	float costoManoObra;
	float costoMateriales;
	float otrosGastos;
public:
	ProyectoInterno(string nombre, int presupuesto, int codigo, float costoManoObra, float costoMateriales)
		:Proyecto(nombre, presupuesto, codigo)
	{
		this->costoManoObra = costoManoObra;
		this->costoMateriales = costoMateriales;
		this->otrosGastos = 1.05;//otros gastos sera el 5% mas
	}
	
	float calcularCosto()override
	{
		
		return presupuesto + (costoManoObra + costoMateriales) * otrosGastos;
	}
	void mostrarInfo()
	{
		cout << "nombre: " << nombre << endl;
		cout << "presupuesto: " << presupuesto << endl;
		cout << "codigo: " << codigo << endl;
		cout << "costo de la ManoObra: " << costoManoObra << endl;
		cout << "costo de materiales: " << costoMateriales << endl;
		cout << "Costo final del protecto: " <<calcularCosto() << endl;
	}


};

