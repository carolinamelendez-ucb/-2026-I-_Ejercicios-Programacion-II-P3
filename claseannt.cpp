// claseannt.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Socio.h"
#include "VectorEquipos.h"
#include "VectorSocios.h"
#include "Equipo.h"
#include "Competencias.h"

using namespace std;
int main()
{
    VectorSocios misSocios = VectorSocios(50);
    VectorEquipos misEquipos = VectorEquipos(50);

    cout <<"Socios"<< endl;
    misSocios.agregar(new Socio(123, "Juan", 65322150));        //socio 0
    misSocios.agregar(new Socio(125, "Esteban", 6678150));      //socio 1
    misSocios.agregar(new Socio(126, "Lorenzo", 6532493));      //socio 2
    misSocios.agregar(new Socio(127, "Maria", 66785478));       //socio 3
    misSocios.ordenarNombres();
    misSocios.mostrar();

    cout << endl;
    cout <<"Equipos"<< endl;

    misEquipos.registrarEquipo(*misSocios.getSocio(3), *misSocios.getSocio(2), "Dinamita", "Toyota");
    misEquipos.registrarEquipo(*misSocios.getSocio(1), *misSocios.getSocio(1), "Tamalitos", "Suzuki");
    misEquipos.registrarEquipo(*misSocios.getSocio(2), *misSocios.getSocio(1), "Dinamita", "Ford");
    misEquipos.registrarEquipo(*misSocios.getSocio(1), *misSocios.getSocio(3), "Sol", "Toyota");

    misEquipos.mostrar();
    cout << "COMPETENCIA " << endl;
    Competencia carrera= Competencia("Rally Bolivia", 10);

    carrera.agregarEquipo(new Equipo(*misSocios.getSocio(0), *misSocios.getSocio(1), "Rayo", "Nissan"));
    carrera.agregarEquipo(new Equipo(*misSocios.getSocio(2), *misSocios.getSocio(0), "Turbo", "Ford"));
    carrera.agregarEquipo(new Equipo(*misSocios.getSocio(1), *misSocios.getSocio(3), "Alfa", "Tesla"));

    carrera.mostrar();

    cout << endl;
    cout << "Buscar equipos de un socio" << endl;

    int ci;
    cout << "Ingrese CI del socio: ";
    cin >> ci;

    misEquipos.buscarEquiposDeSocio(ci);


}
