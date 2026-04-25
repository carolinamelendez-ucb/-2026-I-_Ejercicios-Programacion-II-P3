#include <iostream>
#include "SistemaAsignacion.h"

using namespace std;

int main() {
    SistemaAsignacion sistema(5);

    try {
        Vuelo* v = new Vuelo(1, "08:00", "10:00", "10:30", 5);

        v->agregarAsiento(new Asiento("A1"));
        v->agregarAsiento(new Asiento("A2"));

        v->agregarPasajero(new Pasajero(1, "Juan", "Perez"));
        v->agregarPasajero(new Pasajero(2, "Ana", "Lopez"));

        sistema.registrarVuelo(v);

        sistema.asignar(1, 1, "A1");
        sistema.asignar(2, 1, "A2");

        sistema.mostrarVuelo(1);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}