#pragma once
#include "Espectador.h"

class VectorEspectadores{
private:
	Espectador** espectadores;
	int tamanio;
	int indice;
	public:

	VectorEspectadores ( int tamanio)
		:  tamanio (tamanio), indice (0)
	{
		this-> espectadores = new Espectador* [tamanio];
	}
	void registrarEspectador (Espectador* nuevoEspectador){
		if(indice < tamanio){
			espectadores[indice] = nuevoEspectador;
			indice++;
		 }
	}

	void mostrar (){
		for(int i = 0; i < indice; i++){
			espectadores[i]->mostrar();
		}
	}

};