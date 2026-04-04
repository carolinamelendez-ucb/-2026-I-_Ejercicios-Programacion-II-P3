// practica_2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
#include"Supermecado.h"
using namespace std;

int main() {

    Supermecado* s1 = new Supermecado("Super A", "Ciudad X");
    Supermecado* s2 = new Supermecado("Super B", "Ciudad Y");

    // Super A
    s1->agregarProducto(new ProductoFresco("Lechuga", 50, 2));
    s1->agregarProducto(new ProductoEnvasado("Arroz", 80, 2));
    s1->agregarProducto(new ProductoPromocional("Galletas", 60, 10, 6));

    // Super B
    s2->agregarProducto(new ProductoPremiun("Queso Premium", 100, 1,2));
    s2->agregarProducto(new ProductoFresco("Tomate", 40, 5));

    // Mostrar rango
    s1->mostrarRango(50, 100);

    cout << "\nSupermercado con mayor precio promedio:\n";

    if (s1->tieneMayorPrecioPromedioQue(s2)) {
        s1->mostrarDatos();
    }
    else {
        s2->mostrarDatos();
    }

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
