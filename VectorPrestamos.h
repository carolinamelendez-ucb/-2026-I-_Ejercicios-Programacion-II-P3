#pragma once
#include "Prestamo.h"

class VectorPrestamos{
	private:
	Prestamo** prestamos;
	int indice;
	int tamanio;
	public:

	VectorPrestamos (int tamanio)
		: indice (0), tamanio (tamanio)
	{
		this->prestamos = new Prestamo * [tamanio];
	}

	void registrarPrestamo (Prestamo* nuevoPrestamo){
		if(indice < tamanio){
			prestamos[indice] = nuevoPrestamo;
			indice++;
		}
	}

	void mostrar (){
		for(int i = 0; i < indice; i++){
			prestamos[i]->mostrar ();
		}
	}

	Prestamo* buscarPrestamoActivo (int ciEstudiante, int codigoLibro){
		for(int i = 0; i < indice; i++){
			if(prestamos[i]->getCiEstudiante () == ciEstudiante &&
				prestamos[i]->getCodigoLibro () == codigoLibro &&
				prestamos[i]->getEstado () == true){
				return prestamos[i];
			}
		}
		return nullptr;
	}
};