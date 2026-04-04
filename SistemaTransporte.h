#pragma once
#include <iostream>
#include <string>
#include "VectorTransportes.h"
#include "VectorConductores.h"

using namespace std;

class SistemaTransporte
{
private:
	VectorTransportes* listaTransportes;
	VectorConductores* listaConductores;
public:
	SistemaTransporte(int tamanioTransporte, int tamanioConductores)
	{
		this->listaTransportes = new VectorTransportes(tamanioTransporte);
		this->listaConductores = new VectorConductores(tamanioConductores);
	}
	void registrarTransporte(Transporte* nuevoTransporte)
	{
		Transporte* auxtransp = listaTransportes->buscar(nuevoTransporte->getPlaca());
		if (auxtransp == nullptr)
		{
			listaTransportes->agregar(nuevoTransporte);
		}
		else
		{
			cout << "no hay transpote con numero distinto de placa" << endl;
		}
	}
	void mostrarTransportes()
	{
		listaTransportes->mostrar();
	}
	void registrarOperadores(Operador* nuevoOperador)
	{
		Operador* ciEncontrado = listaConductores->buscarCi(nuevoOperador->getCi());
		if (ciEncontrado == nullptr)
		{
			listaConductores->agregar(nuevoOperador);
		}
	}
	void mostrarOperadores()
	{
		listaConductores->mostrar();
	}

	void asociarOperadorContransporte(int ciBuscado, int placaBuscada)
	{
		Operador* operadorEncontrado = listaConductores->buscarCi(ciBuscado);
		Transporte* transporteEncontrado = listaTransportes->buscar(placaBuscada);
		if (operadorEncontrado != nullptr && transporteEncontrado != nullptr)
		{
			operadorEncontrado->asignarTranposrte(transporteEncontrado);
		}
	}

	void calcularCostoGenerado(int ciBuscado)
	{
		Operador* operadorEncontrado = listaConductores->buscarCi(ciBuscado);
			if (operadorEncontrado != nullptr)
			{
				cout << "el operador" << endl;
				operadorEncontrado->mostrarInfo();
				cout << "costo generado: " << operadorEncontrado->calcularCostoGenerado();
			}
	}
	float calcularCostoGeneral()
	{
		return listaConductores->costoTotal();
	}
	void mostrarMenorCosto()
	{
		listaConductores->mostrarMenorCosto();
	}
	~SistemaTransporte()
	{
		delete listaTransportes;
		delete listaConductores;
	}
};

