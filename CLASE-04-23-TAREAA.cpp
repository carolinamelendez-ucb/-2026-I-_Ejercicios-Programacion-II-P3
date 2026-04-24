#include <iostream>
#include <string>
#include "SistemaAsignacion.h"
using namespace std;



int main()
{
    try {
        SistemaAsignacion sistema("BoA", 100, 10);
        sistema.registrarVuelo("V1", 10, 12, 12, 2, 2);
        sistema.registrarAsiento("V1", "A1");
        sistema.registrarAsiento("V1", "A2");
        sistema.registrarAsiento("V1", "B1");
        sistema.registrarAsiento("V1", "B2");
        sistema.registrarPasajero("V1", 1, "Ana", "Perez");
        sistema.registrarPasajero("V1", 2, "Luis", "Gomez");
        sistema.asignarAsiento("V1", 1, "A1");
        sistema.asignarAsiento("V1", 2, "B1");
        cout << "PASAJEROS:" << endl;
        sistema.mostrarPasajeros("V1");
        cout << endl << "ESTADO DE ASIENTOS:" << endl;
        sistema.estadoAsientos("V1");
    }
    catch (exception&) {
        cout << "Error en la asignacion" << endl;
    }
}