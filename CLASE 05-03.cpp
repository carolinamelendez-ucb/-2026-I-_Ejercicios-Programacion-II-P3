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
    cout << "=== LISTA DE SOCIOS ===" << endl;
    misSocios.mostrarSocios();
    equipoVector misEquipos(20);
    Socio* piloto = Pedro;
    Socio* copiloto = Maria;
    if (piloto == copiloto) {
        cout << "Piloto y copiloto no pueden ser el mismo socio" << endl;
    }
    else {
        Equipo* eq1 = new Equipo(piloto, copiloto);
        misEquipos.agregar(eq1);
    }
    cout << endl << "=== EQUIPOS ===" << endl;
    misEquipos.mostrarEquipos();
}
