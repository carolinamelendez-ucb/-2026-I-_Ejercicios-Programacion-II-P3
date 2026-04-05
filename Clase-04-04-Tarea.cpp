#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;

int main()
{
    Sistema s;

    s.agregarTransporte(new Terrestre("T1"));
    s.agregarTransporte(new Aereo("A1"));
    s.agregarTransporte(new Maritimo("M1"));

    s.agregarOperador(new Operador("Pablo", 1, 150));
    s.agregarOperador(new Operador("Carla", 2, 1200));
    s.agregarOperador(new Operador("Luis", 3, 600));

    s.asociar(0, 0);
    s.asociar(1, 1);
    s.asociar(2, 2);

    cout << "Costo total: " << s.costoTotal() << endl;

    s.menorCosto();

    return 0;
}
