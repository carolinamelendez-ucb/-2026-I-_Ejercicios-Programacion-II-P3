// 0404tarea.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
#include "Transporte.h"
#include "TransporteAreo.h"
#include "TransporteMaritimo.h"
#include "TransporteTerrestre.h"
#include "Operador.h"
#include "VectorOperador.h"
#include "VectorTransporte.h"
#include "Sistema.h"
using namespace std;

int main()
{
	Sistema sistema(10, 10);

	Transporte* auto1 = new TransporteTerrestre(101, 0.5);
	Transporte* moto1 = new TransporteTerrestre(102, 0.5);
	Transporte* avion1 = new TransporteAereo(201, 2.0);
	Transporte* avion2 = new TransporteAereo(202, 2.0);
	Transporte* barco1 = new TransporteMaritimo(301, 1.2);

	sistema.registrarMediosTransporte(auto1);
	sistema.registrarMediosTransporte(moto1);
	sistema.registrarMediosTransporte(avion1);
	sistema.registrarMediosTransporte(avion2);
	sistema.registrarMediosTransporte(barco1);

	sistema.registrarOperadores(new Operador(111, "Juan", 80));
	sistema.registrarOperadores(new Operador(222, "Maria", 150));
	sistema.registrarOperadores(new Operador(333, "Luis", 1200));
	sistema.registrarOperadores(new Operador(444, "Ana", 2000));
	sistema.registrarOperadores(new Operador(555, "Carlos", 700));

	sistema.asignarTransporteOperador(111, auto1);
	sistema.asignarTransporteOperador(222, moto1);
	sistema.asignarTransporteOperador(333, avion1);
	sistema.asignarTransporteOperador(444, avion2);
	sistema.asignarTransporteOperador(555, barco1);

	cout << "Costo por Operador: " << endl;
	cout << endl;
	sistema.calcularCostoOperador(111);
	sistema.calcularCostoOperador(222);
	sistema.calcularCostoOperador(333);
	sistema.calcularCostoOperador(444);
	sistema.calcularCostoOperador(555);

	cout << endl;
	
	sistema.calcularCostoGeneral();

	cout << endl;
	cout << "Operador con menor costo" << endl;

	sistema.mostrarOperadorMenor();

}
