// Sistema Estacionamiento Inteligente.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "SistemaParqueo.h"

using namespace std;


int main()
{
    SistemaParqueo skyboxParqueo = SistemaParqueo("SkyBox", "Av. Heroinas", 3, 80);

    skyboxParqueo.registrarEspacioEstacionamiento(new Espacio("E1", 1, "Comidas"));
    skyboxParqueo.registrarEspacioEstacionamiento(new Espacio("E2", 2, "Comidas"));
    skyboxParqueo.registrarEspacioEstacionamiento(new Espacio("E2", 3, "Comidas"));
    skyboxParqueo.registrarEspacioEstacionamiento(new Espacio("E3", 3, "Comidas"));
    skyboxParqueo.registrarEspacioEstacionamiento(new Espacio("E4", 4, "Comidas"));

    skyboxParqueo.registrarVehiculo(new Vehiculo("123", "Toyota", "Modelo88", "modelo1"));
    skyboxParqueo.registrarVehiculo(new Vehiculo("465", "Toyota", "Modelo88", "modelo1"));
    skyboxParqueo.registrarVehiculo(new Vehiculo("569", "Toyota", "Modelo88", "modelo1"));
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
