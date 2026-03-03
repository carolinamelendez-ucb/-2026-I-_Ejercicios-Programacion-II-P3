#pragma once
#include "Pasajero.h"

class PasajerosVector{
private:	
	Pasajero** pasajeros;
	int tamanio;
	int indice;
public:
	PasajerosVector (int tamanio){
	this->pasajeros = new Pasajero * [tamanio];
	this->indice = 0;
	this->tamanio = tamanio;
	}
	void agregar (Pasajero* nuevoPasajero){
		pasajeros[indice] = nuevoPasajero;
		indice++;
	}
	void mostrar (){
		for(int i = 0; i < indice; i++){
			pasajeros[i] ->mostrar();
		}
	}
	void pasajeroSinAsiento (){
		for(int i = 0; i < indice; i++){
			if(pasajeros[i]->getNumeroAsiento() == 0){
				pasajeros[i]->mostrar ();
			}
		}
	}
	void pasajerosImpares (){
		for(int i = 0; i < indice; i++){
			if(pasajeros[i]->getNumeroAsiento () % 2 != 0){
				pasajeros[i] ->mostrar();
			}
		}
	}
	void pasajeroNombre (string nombre){
		for(int i = 0; i < indice; i++){
			if(pasajeros[i]->getNombre () == nombre){
				cout << "Encontrado" << endl;
				pasajeros[i]->mostrar ();
			}
		}
	}
	void pasajeroCi (int ciBuscado){
		for(int i = 0; i < indice; i++){
			if(pasajeros[i]->getCi() == ciBuscado){
				cout << "Encontrado" << endl;
				pasajeros[i]->mostrar ();
			}
		}
	}
};