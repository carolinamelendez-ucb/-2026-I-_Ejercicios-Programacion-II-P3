// practica_3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
#include"Operador.h"
#include"Transporte.h"
#include"VectorTransporte.h"
#include"VectorOperadores.h"
#include"Sistema.h"
using namespace std;

int main() {

    Sistema sistema(5, 5);

    // Transportes
    sistema.registrarTransporte(new Terrestre("ABC-1"));
    sistema.registrarTransporte(new Aereo("XYZ-2"));
    sistema.registrarTransporte(new Maritimo("MAR-3"));

    // Operadores
    sistema.registrarOperador(new Operador("Juan", 1));
    sistema.registrarOperador(new Operador("Ana", 2));
    sistema.registrarOperador(new Operador("carlos", 3));
    // Asignaciones
    sistema.asignar(1, "ABC-1", 150);  
    sistema.asignar(2, "XYZ-2", 1200);  
    sistema.asignar(3, "MAR-3", 600);  
    sistema.mostrarTodo();

    sistema.totalDelSistema();

    sistema.menorCosto();

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
