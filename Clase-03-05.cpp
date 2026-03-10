#include <iostream>
#include <string>
#include "Equipo.h"
#include "VectorEquipos.h"
#include "Socio.h"
#include "VectorSocios.h"
#include "Competencia.h"
using namespace std;

int main()
{
    VectorSocio misSocios = VectorSocio(10);

    Socio* s1 = new Socio(1242,"Juan", 75951730);
    Socio* s2 = new Socio(4322,"Pablo", 75848433);
    Socio* s3 = new Socio(1442,"Carlos", 77774546);
    Socio* s4 = new Socio(4566,"Jose", 75844323);


    misSocios.agregar(s1);
    misSocios.agregar(s2);
    misSocios.agregar(s3);
    misSocios.agregar(s4);

    cout << "-------SOCIOS-------" << endl;
    misSocios.ordenarPorNombre();
    misSocios.mostrar();

    VectorEquipo misEquipos = VectorEquipo(10);

    Socio* piloto = s1;
    Socio* copiloto = s2;

    Equipo* e1 = nullptr;
    Equipo* e2 = nullptr;

    if (s1->getNombre() != s2->getNombre())
    {
        e1 = new Equipo(s1, s2, "Red Bull", "Toyota");
        misEquipos.agregar(e1);
    }
    else
    {
        cout << "Error: piloto y copiloto no pueden ser el mismo nombre de socio" << endl;
    }
    if (s3->getNombre() != s4->getNombre())
    {
        e2 = new Equipo(s3, s4, "Mercedes", "Ford");
        misEquipos.agregar(e2);
    }
    else
    {
        cout << "Error: piloto y copiloto no pueden ser el mismo nombre de socio" << endl;
    }

    cout << "-------EQUIPOS-------" << endl;
    misEquipos.mostrar();

    Competencia c1("Rally 2025", 10);

    if (e1 != nullptr) c1.agregarEquipo(e1);
    if (e2 != nullptr) c1.agregarEquipo(e2);

    cout << endl << "------COMPETENCIA------" << endl;
    c1.mostrar();

    cout << endl << "Equipos donde participa Juan:" << endl;
    misEquipos.buscarEquiposDeSocio("Juan");
}

