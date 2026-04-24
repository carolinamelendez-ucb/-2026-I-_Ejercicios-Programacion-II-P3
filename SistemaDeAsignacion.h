#pragma once
#include "ListaVuelos.h"
#include "ListaPasajeros.h"


class SistemaDeAsignacion {
private:
	VectorPasajeros* losPasajeros;
	VectorVuelos* losVuelos;
public:
	SistemaDeAsignacion(int maxVuelos,int maxPasajeros){
		this->losVuelos = new VectorVuelos(maxVuelos);
		this->losPasajeros = new VectorPasajeros(maxPasajeros);

	}

	

};

