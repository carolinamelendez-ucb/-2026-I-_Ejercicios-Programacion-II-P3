#include <iostream>
#include "Socio.h"
#include "VectorSocios.h"
#include "Equipo.h"
#include "VectorEquipos.h"

using namespace std;

int main()
{
    VectorSocios misSocios = VectorSocios(50);

    misSocios.agregar(new Socio(1, "Omar", 123));
    misSocios.agregar(new Socio(2, "Benjamin", 456));
    misSocios.agregar(new Socio(3, "Gabriel", 789));
    misSocios.agregar(new Socio(4, "Alejandro", 101));
    misSocios.agregar(new Socio(5, "Sebastian", 112));
    misSocios.agregar(new Socio(6, "Ismael", 134));

    misSocios.mostrar();

    VectorEquipos misEquipos = VectorEquipos(50);

    //misEquipos.agregar(new Equipo(misSocios[0], misSocios[0], "Equipo 1", "Mustang"));
}
