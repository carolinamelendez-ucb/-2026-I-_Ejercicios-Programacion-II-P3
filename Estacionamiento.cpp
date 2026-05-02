// Estacionamiento.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "SistemaParqueo.h"

int main()
{
	SistemaParqueo miParqueo = SistemaParqueo("Aliados", "Heroinas", 10);

	miParqueo.registrarEspacio(new Espacio ("A1", 1, "Comidas"));
	miParqueo.registrarEspacio(new Espacio("A2", 1, "Comidas"));
	miParqueo.registrarEspacio(new Espacio("A1", 1, "Comidas"));
	miParqueo.registrarEspacio(new Espacio("A3", 1, "Comidas"));

	miParqueo.registrarVehiculo(new Vehiculo ("123", "toyota", "2013", "Caro"));
	miParqueo.registrarVehiculo(new Vehiculo("456", "toyota", "2013", "Barato"));
	miParqueo.registrarVehiculo(new Vehiculo("123", "zuzuqui", "2013", "Barato"));
	//miParqueo.registrarVehiculo(new Vehiculo("789", "mercedez", "2013", "Caro"));
	
	miParqueo.asignarEspacioAVehiculo("123");
	//miParqueo.asignarEspacioAVehiculo("123");
	miParqueo.asignarEspacioAVehiculo("456");
	//miParqueo.asignarEspacioAVehiculo("789");

	miParqueo.buscarVehiculo("123");
	cout << endl;
	miParqueo.ordenarPorMarca();
	miParqueo.mostrarVehiculos();
	cout << endl;
	miParqueo.mostrarEspaciosDisponibles();
	cout << endl;
	miParqueo.mostrarVehiculosEstacionados();

}

