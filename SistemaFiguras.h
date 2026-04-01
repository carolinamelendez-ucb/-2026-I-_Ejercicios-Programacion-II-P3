#pragma once
#include <iostream>
#include <string>
#include "VectorFiguras.h"
#include "Circulo.h"
#include "Rectangulo.h"

class SistemaFiguras
{
private:
	VectorFigura* listaFiguras;
public:
	SistemaFiguras(int tamanioFiguras)
	{
		this->listaFiguras = new VectorFigura(tamanioFiguras);
	}

	void registrarFigura(Figura* nuevaFigura)
	{
		listaFiguras->agregar(nuevaFigura);
	}

	~SistemaFiguras()
	{
		delete listaFiguras;
	}

	void mostrarAreas()
	{
		listaFiguras->calcularTodasLasAreas();
	}


};
