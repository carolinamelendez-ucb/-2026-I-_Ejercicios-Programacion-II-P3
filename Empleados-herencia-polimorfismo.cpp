// Empleados-herencia-polimorfismo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <string>
#include "Empresa.h"
#include "EpleadoPorHoras.h"
#include "EmpleadoTiempoCompleto.h"
#include "ProyectoExterno.h"
#include "ProyectoInterno.h"
using namespace std;

int main()
{
    Empresa empresa1 = Empresa(20, 20);

    empresa1.registrarEmpelado(new EmpleadoTiempoCompleto("arita", 3433, 2000, 350));
    empresa1.registrarEmpelado(new EmpleadoTiempoCompleto("alvaro", 2233, 2000, 450));
    empresa1.registrarEmpelado(new EmpleadoPorHoras("mario", 4554,2000,8));
    empresa1.registrarEmpelado(new EmpleadoPorHoras("nadia", 6776,2000,12));
    empresa1.registrarProyecto(new ProyectoExterno("ampliacion fibra optica oruro-cocha", 3000, 333, 1000, 1500,2120));
    empresa1.registrarProyecto(new ProyectoExterno("ampliacion fibra optica La paz-cocha", 5000, 222, 1000, 1500,2300));
    empresa1.registrarProyecto(new ProyectoInterno("reogarnizacion comteco", 1500, 555, 1200, 1000));
    empresa1.registrarProyecto(new ProyectoInterno("reogarnizacion entel", 1500, 335, 1330, 2000));
    empresa1.mostrarEmpleado();
    empresa1.mostrarProyecto();
    cout << "---------------------------" << endl;
    empresa1.calcularTotalSalarios();
    cout << "---------------------------" << endl;
    empresa1.proyectoMayorCosto();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
