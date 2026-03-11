#include <iostream>
#include <string>
#include "socioVector.h"
#include "equipoVector.h"
#include "competenciaVector.h"
using namespace std;
int main()
{
    socioVector misSocios(20);
    equipoVector misEquipos(10);
    competenciaVector misCompetencias(10);
    Socio* Rafael = new Socio(101, "Rafael", 79213490);
    Socio* Haziel = new Socio(102, "Haziel", 79213490);
    Socio* Esmeralda = new Socio(103, "Esmeralda", 79213490);
    Socio* Kevin = new Socio(104, "Kevin", 79213490);
    Socio* Gilberto = new Socio(105, "Gilberto", 79213490);
    Socio* Rosalina = new Socio(106, "Rosalina", 79213490);
    misSocios.agregar(Rafael);
    misSocios.agregar(Haziel);
    misSocios.agregar(Esmeralda);
    misSocios.agregar(Kevin);
    misSocios.agregar(Gilberto);
    misSocios.agregar(Rosalina);
    Equipo* equipo1 = new Equipo("Los Cocos", "Suzuki", Rafael, Haziel);
    Equipo* equipo2 = new Equipo("Pitufos", "Toyota", Esmeralda, Kevin);
    Equipo* equipo3 = new Equipo("Bad Guys", "Isuzu", Gilberto, Rosalina);
    Equipo* equipo4 = new Equipo("Los Colaos", "Ford", Rafael, Esmeralda);
    misEquipos.agregar(equipo1);
    misEquipos.agregar(equipo2);
    misEquipos.agregar(equipo3);
    misEquipos.agregar(equipo4);
    Competencia* competencia1 = new Competencia(3);
    Competencia* competencia2 = new Competencia(2);
    misCompetencias.agregar(competencia1);
    misCompetencias.agregar(competencia2);
    cout << "SOCIOS ORDENADOS ALFABETICAMENTE" << endl;
    cout << endl;
    misSocios.ordenarPorNombre();
    misSocios.mostrarSociosVec();
    cout << endl;
    cout << "EQUIPOS FORMADOS POR DOS SOCIOS" << endl;
    cout << endl;
    misEquipos.mostrarEquiposVec();
    cout << endl;
    cout << "COMPETENCIAS CREADAS CON CONTROL DE SOCIOS REPETIDOS" << endl;
    cout << "Competencia 1: " << endl;
    cout << "Los Cocos... inscribiendo..." << endl;
    competencia1->agregarEquipo(equipo1);
    cout << "Pitufos... inscribiendo..." << endl;
    competencia1->agregarEquipo(equipo2);
    cout << "Bad Guys... inscribiendo..." << endl;
    competencia1->agregarEquipo(equipo3);
    cout << "Los Colaos... inscribiendo..." << endl;
    competencia1->agregarEquipo(equipo4);
    cout << "Competencia 2: " << endl;
    cout << "Los Cocos... inscribiendo..." << endl;
    competencia2->agregarEquipo(equipo1);
    cout << "Pitufos... inscribiendo..." << endl;
    competencia2->agregarEquipo(equipo2);
    cout << "Bad Guys... inscribiendo..." << endl;
    competencia2->agregarEquipo(equipo3);
    cout << "Competencias Registradas" << endl;
    misCompetencias.mostrarCompetenciaVector();
    cout << "BUSCAR EQUIPOS DE UN SOLO SOCIO" << endl;
    cout << endl;
    cout << "Analizando equipos de RAFAEL: " << endl;
    misEquipos.buscarEquiposSocio(Rafael);
    cout << "Analizando equipos de ESMERALDA: " << endl;
    misEquipos.buscarEquiposSocio(Esmeralda);
    cout << "Analizando equipos de ROSALINA: " << endl;
    misEquipos.buscarEquiposSocio(Rosalina);
    return 0;
}