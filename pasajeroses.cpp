using namespace std;
#include <iostream>
#include <string>
#include "pasajero.h"
#include "pasajerosvec.h"
int main()
{
    Pasajeros pasajeros = Pasajeros(50);
    pasajeros.agregar(new Pasajero("messi", 12212122));
    pasajeros.pasajerosinasiento();
}

