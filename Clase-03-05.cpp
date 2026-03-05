#include <iostream>
#include <string>
#include "Equipo.h"
#include "VectorEquipos.h"
#include "Socio.h"
#include "VectorSocios.h"
using namespace std;

int main()
{
    VectorSocio misSocios = VectorSocio(10);

    Socio* s1 = new Socio(1242,"Carlos", 75951730);
    Socio* s2 = new Socio(4322,"Juan", 75848433);
    Socio* s3 = new Socio(1442,"Pablo", 77774546);

    misSocios.agregar(s1);
    misSocios.agregar(s2);
    misSocios.agregar(s3);

    cout << "-------SOCIOS-------" << endl;
    misSocios.mostrar();


    VectorEquipo misEquipos=VectorEquipo(10);

    Socio* piloto = misSocios.buscarPorNombre("Carlos");
    Socio* copiloto = misSocios.buscarPorNombre("Ana");

    if (piloto != NULL && copiloto != NULL && piloto->getNombre() != copiloto->getNombre())
    {
        Equipo* e1 = new Equipo(piloto, copiloto, "AMS", "Toyota");
        misEquipos.agregar(e1);
        Equipo* e2 = new Equipo(piloto, copiloto, "RBD", "Mercedes");
        misEquipos.agregar(e2);
    }

    cout << "-------EQUIPOS-------" << endl;
    misEquipos.mostrar();
}

