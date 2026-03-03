// Clase 03 - 03.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "PasajerosVector.h"

int main() {

    PasajerosVector lista(50);

    Pasajero* juan = new Pasajero("Juan", 123);
    Pasajero* maria = new Pasajero("Maria", 456);
    Pasajero* carlos = new Pasajero("Carlos", 789);

    juan->asignarAsiento(5);
    maria->asignarAsiento(8);
    // pasajero3 se queda sin asiento

    lista.agregar(juan);
    lista.agregar(maria);
    lista.agregar(carlos);

    cout << "Pasajeros sin asiento:\n";
    lista.mostrarSinAsiento();

    cout << "\nPasajeros con asiento impar:\n";
    lista.mostrarAsientoImpar();

    cout << "\nBuscar por nombre (Maria):\n";
    lista.buscarPorNombre("Maria");

    cout << "\nBuscar por CI (789):\n";
    lista.buscarPorCi(789);

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
