// tarea-03-03-2026.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "PasajerosVector.h"
using namespace std;

int main()
{
    PasajerosVector misPasajeros = PasajerosVector(50);
    misPasajeros.agregar(new Pasajero("Marcos", 123));
    misPasajeros.agregar(new Pasajero("Ana", 456));
    misPasajeros.agregar(new Pasajero("Luis", 789));
    misPasajeros.agregar(new Pasajero("Sofia", 111));

    misPasajeros.mostrarPasajeroPorNombre("Marcos");

    misPasajeros.mostrarPasajeroPorCi(456);

    Pasajero* p1 = new Pasajero("Cesar", 222);
    p1->asignarAsiento(0);
    misPasajeros.agregar(p1);

    Pasajero* p2 = new Pasajero("Nora", 333);
    p2->asignarAsiento(7);
    misPasajeros.agregar(p2);

    Pasajero* p3 = new Pasajero("Pedro", 444);
    p3->asignarAsiento(10);
    misPasajeros.agregar(p3);

    cout << "1) SIN ASIENTO " << endl;
    misPasajeros.mostrarPasajerosSinAsiento();
    cout << "2) ASIENTO IMPAR" << endl;
    misPasajeros.mostrarPasajerosAsientoImpar();
    cout << "3) BUSCAR POR NOMBRE " << endl;
    misPasajeros.mostrarPasajeroPorNombre("Sofia");
    cout << "4) BUSCAR POR CI " << endl;
    misPasajeros.mostrarPasajeroPorCi(789);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
