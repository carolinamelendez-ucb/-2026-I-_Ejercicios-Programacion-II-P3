#include <iostream>
#include <string>
#include "Pasajero.h"
#include "PasajeroVector.h"
using namespace std;


int main()
{
    PasajeroVector misPasajeros = PasajeroVector(10);

    Pasajero* p1 = new Pasajero("Carlos", 123);
    Pasajero* p2 = new Pasajero("Ana", 638);
    Pasajero* p3 = new Pasajero("Juan", 238);

    p1->asignarAsiento(4);
    p3->asignarAsiento(3);

    misPasajeros.agregar(p1);
    misPasajeros.agregar(p2);
    misPasajeros.agregar(p3);

    misPasajeros.mostrar();
    cout << "----------------" << endl;
    misPasajeros.mostrarPasajerosSinAsiento();
    cout << "----------------" << endl;
    misPasajeros.mostrarPasajerosAsientoImpar();

}

