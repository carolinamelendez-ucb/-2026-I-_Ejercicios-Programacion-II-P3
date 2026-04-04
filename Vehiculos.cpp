// Vehiculos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <string>
#include "SistemaTransporte.h"
#include "TransporteAereo.h"
#include "TransporteMaritimo.h"
#include "TransporteTerrestre.h"

using namespace std;

int main()
{
	SistemaTransporte sistema1 = SistemaTransporte(20, 20);
	cout << "-----------traportes-----------" << endl;
	cout << endl;
	sistema1.registrarTransporte(new TransporteTerrestre(123));
	sistema1.registrarTransporte(new TransporteAereo(456));
	sistema1.registrarTransporte(new TransporteMaritimo(789));
	sistema1.registrarTransporte(new TransporteTerrestre(126));
	sistema1.mostrarTransportes();
	cout << "----------Operadores-------------" << endl;
	cout << endl;
	sistema1.registrarOperadores(new Operador("jose", 333, 200));
	sistema1.registrarOperadores(new Operador("Ana", 2222, 1500));
	sistema1.registrarOperadores(new Operador("julio", 555, 300));
	sistema1.registrarOperadores(new Operador("Anabel", 444, 450));
	sistema1.mostrarOperadores();
		
	sistema1.asociarOperadorContransporte(333, 123);
	sistema1.asociarOperadorContransporte(2222, 456);
	sistema1.asociarOperadorContransporte(555, 789);
	sistema1.asociarOperadorContransporte(444, 126);

	
	cout << endl;
	cout << "----------COSTO POR OPERADOR-------------" << endl;

	sistema1.calcularCostoGenerado(333);
	sistema1.calcularCostoGenerado(2222);
	sistema1.calcularCostoGenerado(555);
	sistema1.calcularCostoGenerado(444);

	cout << endl;
	

	cout << "Costo total del sistema: " << sistema1.calcularCostoGeneral() << endl;

	cout << endl;
	cout << "----------MENOR COSTO-------------" << endl;

	sistema1.mostrarMenorCosto();
}