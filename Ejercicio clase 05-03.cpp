// Ejercicio clase 05-03.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
#include "SociosVector.h"
#include "EquiposVector.h"

using namespace std;

int main()
{
    SociosVector missocios = SociosVector(50);
    EquiposVector misequipos = EquiposVector(50);
    //mostrar todos los socios
    Socio* s1 = new Socio("carlo", 3456, 575675);
    Socio* s2 = new Socio("felipe", 5657,546457);
    Socio* s3 = new Socio("carlo", 7890,8795454);
    missocios.agregar(s1);
    missocios.agregar(s2);
    missocios.agregar(s3);
    missocios.mostrar();

    Equipo* e1 = new Equipo(*s1, *s2, "lobo", "toyota");
    Equipo* e2 = new Equipo(*s3, *s1, "alfa", "nissan");
    misequipos.agregar(e1);
    misequipos.agregar(e2);

    misequipos.mostrar();
   


    


    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
