#include <iostream>
#include <string>
#include "Pasajero.h"
#include "PasajerosVectores.h"

using namespace std;

int main()
{
    PasajerosVectores misPasajeros = PasajerosVectores(50);

    misPasajeros.agregar(new Pasajero("Omar", 112));
    misPasajeros.agregar(new Pasajero("Benjamin", 122));
    misPasajeros.agregar(new Pasajero("Ale", 132));
    misPasajeros.agregar(new Pasajero("Ismael", 142));
    misPasajeros.agregar(new Pasajero("Sebas", 152));
    misPasajeros.agregar(new Pasajero("Gabo", 162));
    misPasajeros.errorSistema();

    misPasajeros.mostrarSinAsientos();
    misPasajeros.mostrarAsientosImpares();
    misPasajeros.mostrarConNombre("Sebas");
    misPasajeros.mostrarConCi(162);
}
