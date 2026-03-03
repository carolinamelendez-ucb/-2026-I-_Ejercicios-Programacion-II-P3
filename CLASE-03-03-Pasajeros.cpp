#include <iostream>
#include <string>
#include "pasajerosVector.h"
using namespace std;

int main()
{
    pasajerosVector misPasajeros = pasajerosVector(50);
    misPasajeros.agregar(new Pasajero("Ana", 123));
    Pasajero* Luis = new Pasajero("Luis", 456);
    misPasajeros.agregar(Luis);
    Luis->asignarAsiento(5);
    cout << "=== Pasajeros sin Asiento ===" << endl;
    misPasajeros.mostrarSinAsiento();
}
