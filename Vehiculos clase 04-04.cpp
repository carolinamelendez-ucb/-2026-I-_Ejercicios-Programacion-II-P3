// Vehiculos clase 04-04.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "VectorTransportes.h"
#include "VectorOperadores.h"

using namespace std;

int main() {

    VectorTransportes vectorTransportes;
    VectorOperadores vectorOperadores;

    Transporte* t1 = new TransporteTerrestre("AAA111");
    Transporte* t2 = new TransporteAereo("BBB222");
    Transporte* t3 = new TransporteMaritimo("CCC333");

    vectorTransportes.agregar(t1);
    vectorTransportes.agregar(t2);
    vectorTransportes.agregar(t3);

    vectorOperadores.agregar(new Operador("Juan", "123", 150, t1));
    vectorOperadores.agregar(new Operador("Fabian", "456", 1200, t2));
    vectorOperadores.agregar(new Operador("Alan", "789", 600, t3));

    vectorOperadores.mostrar();

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
