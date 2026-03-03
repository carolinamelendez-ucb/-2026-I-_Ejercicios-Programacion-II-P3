// Ejercicio clase 3-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PasajerosVector.h"

int main()
{
	PasajerosVector misPasajeros = PasajerosVector(50);
	Pasajero* pasajero1 = new Pasajero("Alan", 234);
	pasajero1->setNumeroAsiento(1);
	misPasajeros.agregar(pasajero1);
	Pasajero* pasajero2 = new Pasajero ("Fabien", 64);
	misPasajeros.agregar (pasajero2);
	Pasajero* pasajero3 = new Pasajero ("Rosa", 123);
	pasajero3->setNumeroAsiento (2);
	misPasajeros.agregar (pasajero3);
	cout<<"sin asiento "<<endl;
	misPasajeros.pasajeroSinAsiento();
	cout << "impar " << endl;
	misPasajeros.pasajerosImpares();
	cout << "ci " << endl;
	misPasajeros.pasajeroCi(64);
	cout << "nombre " << endl;
	misPasajeros.pasajeroNombre("Rosa");
}
			  
