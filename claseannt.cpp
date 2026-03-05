// claseannt.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Socio.h"
#include "VectorEquipos.h"
#include "VectorSocios.h"
#include "Equipo.h"

using namespace std;
int main()
{
    VectorSocios misSocios = VectorSocios(50);
    misSocios.agregar(new Socio(123, "Juan", 65322150));
    misSocios.agregar(new Socio(125, "Esteban", 6678150));
    Socio* Ana(new Socio(124, "Ana", 5467890));
    misSocios.agregar(Ana);
    misSocios.mostrar();



}
