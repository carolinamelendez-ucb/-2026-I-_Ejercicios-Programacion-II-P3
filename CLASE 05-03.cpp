#include <iostream>
#include <string>
#include "socioVector.h"
#include "equipoVector.h"
using namespace std;

int main()
{
    socioVector misSocios(50);
    Socio* Pedro = new Socio(123, "Pedro", 79629000);
    Socio* Maria = new Socio(456, "Maria", 70765442);
    misSocios.agregar(Pedro);
    misSocios.agregar(Maria);
    misSocios.ordenarPorNombre();
    cout << "=== SOCIOS ===" << endl;
    misSocios.mostrarSocios();
    equipoVector misEquipos(20);
    Equipo* eq1 = new Equipo("Rayo", "Toyota", Pedro, Maria);
    misEquipos.agregar(eq1);
    cout << endl << "=== EQUIPOS ===" << endl;
    misEquipos.mostrarEquipos();
    cout << endl << "=== BUSCAR EQUIPOS DE PEDRO ===" << endl;
    misEquipos.buscarEquiposSocio(Pedro);
}
