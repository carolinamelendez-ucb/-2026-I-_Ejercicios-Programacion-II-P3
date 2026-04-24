#include <iostream>
#include <string>
#include "SistemaAsignacion.h"
using namespace std;
int main()
{
	try {
		SistemaAsignacion sistema("Avianca", 100, 10);
		sistema.registrarVuelo("A45", 10, 12, 12, 2, 2);
		sistema.registrarAsiento("A45", "A1");
		sistema.registrarAsiento("A45", "A2");
		sistema.registrarAsiento("A45", "B1");
		sistema.registrarAsiento("A45", "B2");
		sistema.registrarPasajero("A45", 1, "Julio", "Gonzalez");
		sistema.registrarPasajero("A45", 2, "Stella", "Ramirez");
		sistema.asignarAsiento("A45", 1, "A1");
		sistema.asignarAsiento("A45", 2, "B1");
		cout << endl;
		cout << "PASAJEROS: " << endl;
		sistema.mostrarPasajeros("A45");
		cout << "ESTADO DE ASIENTOS: " << endl;
		sistema.estadoAsientos("A45");
	}
	catch (exception&) {
		cout << "Error en la asignacion" << endl;
	}
}
