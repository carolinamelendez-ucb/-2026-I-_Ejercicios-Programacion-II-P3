#pragma once
#include "Libro.h"

class VectorLibros{
	private:
	Libro** libros;
	int indice;
	int tamanio;
	public:

	VectorLibros (int tamanio)
		: indice (0), tamanio (tamanio)
	{
		this->libros = new Libro * [tamanio];
	}

	void registrarLibro (Libro* nuevoLibro){
		if(indice < tamanio){
			libros[indice] = nuevoLibro;
			indice++;
		}
	}

	void mostrar (){
		for(int i = 0; i < indice; i++){
			libros[i]->mostrar ();
		}
	}

	Libro* verificarCodigoDuplicado (int codigo){
		for(int i = 0; i < indice; i++){
			if(libros[i]->getCodigo () == codigo){
				return libros[i];
			}
		}
		return nullptr;
	}

	Libro* buscarLibroPorCodigo (int codigo){
		for(int i = 0; i < indice; i++){
			if(libros[i]->getCodigo () == codigo){
				return libros[i];
			}
		}
		return nullptr;
	}
};