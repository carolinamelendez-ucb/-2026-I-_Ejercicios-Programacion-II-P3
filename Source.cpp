#include <iostream>
#include "Pasajeros.h"

using namespace std;

int main() {

    Pasajeros sistema;

    Pasajero p1("Juan", 123);
    Pasajero p2("Maria", 456);
    Pasajero p3("Luis", 789);

    p1.asignarAsiento(5);
    p2.asignarAsiento(2);

    sistema.agregar(p1);
    sistema.agregar(p2);
    sistema.agregar(p3);

    cout << "Sin asiento:\n";
    sistema.mostrarSinAsiento();

    cout << "\nAsientos impares:\n";
    sistema.mostrarImpares();

    cout << "\nBuscar por nombre:\n";
    sistema.buscarNombre("Juan");

    cout << "\nBuscar por CI:\n";
    sistema.buscarCI(456);

    return 0;
}