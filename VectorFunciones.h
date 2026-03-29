#pragma once
#include "Funcion.h"

class VectorFunciones{
	private:
	Funcion** funciones;
	int indice;
	int tamanio;
	public:

	VectorFunciones (int tamanio)
		: indice (0), tamanio (tamanio)
	{
		this->funciones = new Funcion * [tamanio];
	}
	void registrarFuncion (Funcion* nuevaFuncion){
		if(indice < tamanio){
			funciones[indice] = nuevaFuncion;
			indice++;
		}
	}

	void mostrar (){
		for(int i = 0; i < indice; i++){
			funciones[i]->mostrar ();
		}
	}

	Funcion* verificarCodigoDuplicado (int codigo){
		for(int i = 0; i < indice; i++){
			if(funciones[i]->getCodigo () == codigo){
				return funciones[i];
			}
		}
		return nullptr;
	}

	void finalizarFuncion (int codigo){
		for(int i = 0; i < indice; i++){
			if(funciones[i]->getCodigo () == codigo){
				funciones[i]->finalizarFuncion();
			}
		}
	}
};