// tarea.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "SistemaAsiganacion.h"

int main() {
    SistemaAsignacion sistema;

    try {
        cout << "Registrar vuelo" << endl;
        sistema.registrarVuelo("V1", 2, 2);

        cout << "Registrar asientos" << endl;
        sistema.registrarAsiento("V1", "A1");
        sistema.registrarAsiento("V1", "A2");

        cout << "Registrar pasajeros" << endl;
        sistema.registrarPasajero("V1", new Pasajero("123", "Ana", "Lopez"));
        sistema.registrarPasajero("V1", new Pasajero("124", "Luis", "Lujan"));

        
        sistema.asignar("V1", "123", "A1");
        
        sistema.asignar("V1", "124", "A1");

    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

   
}