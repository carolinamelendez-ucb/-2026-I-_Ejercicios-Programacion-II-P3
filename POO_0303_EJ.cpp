#include <iostream>
#include <string>
#include "Pasajero.h"
#include "PasajerosVector.h"

using namespace std;

int main()
{
    PasajerosVector misPasajeros = PasajerosVector(30);
    misPasajeros.Agregar(new Pasajero("Carlos", 1234,3));


    misPasajeros.pasajeroBuscadoNombre("carlos");

}
