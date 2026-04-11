#include <iostream>
#include <string>
#include "Sistema.h"
#include "VehiculoEconomico.h"
#include "VehiculoDeLujo.h"
#include "ClienteBasico.h"
#include "ClienteCorporativo.h"
using namespace std;
int main()
{
	Sistema miSistema(50, 50, 50);
	Cliente* cliente1 = new ClienteBasico(1234, "Rosalia Gomez", 10);
	Cliente* cliente2 = new ClienteCorporativo(5678, "Augusto De Versalles", 20);
	Cliente* cliente3 = new ClienteBasico(9454, "Fatima Candy", 10);
	miSistema.agregarCliente(cliente1);
	miSistema.agregarCliente(cliente2);
	miSistema.agregarCliente(cliente3);

	Vehiculo* vehiculo1 = new VehiculoEconomico("816-JFE");
	Vehiculo* vehiculo2 = new VehiculoEconomico("5426-OEO");
	Vehiculo* vehiculo3 = new VehiculoDeLujo("2356-GBA");
	miSistema.agregarVehiculo(vehiculo1);
	miSistema.agregarVehiculo(vehiculo2);
	miSistema.agregarVehiculo(vehiculo3);

	miSistema.asignar(1234, "816-JFE", 3);
	miSistema.asignar(5678, "5426-OEO", 2);
	miSistema.asignar(9454, "2356-GBA", 4);
	
	miSistema.asignar(1234, "5426-OEO", 5);

	miSistema.mostrar();
	cout << "Despues de cambios...." << endl;
	cout << endl;
	miSistema.desasignar(1234, "816-JFE");
	miSistema.mostrar();

	return 0;
}