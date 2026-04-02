// 0204ejercicio.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Empresa.h"
#include "EmpleadoPorHoras.h"
#include "EmpleadoTiempoCompleto.h"
#include "ProyectoExterno.h"
#include "ProyectoInterno.h"

int main()
{
    Empresa miEmpresa(5, 5);
    miEmpresa.agregarEmpleado(new EmpleadoPorHoras("Dania", 1, 20, 6));
    miEmpresa.agregarEmpleado(new EmpleadoTiempoCompleto("Valeria", 2, 25, 8));
    miEmpresa.agregarEmpleado(new EmpleadoTiempoCompleto("Lucia", 2, 25, 8));

    miEmpresa.mostrarEmpleados();
    cout << endl;

    miEmpresa.agregarProyecto(new ProyectoExterno(11, "Carretera", 4000, 30));
    miEmpresa.agregarProyecto(new ProyectoInterno(22, "Escuela", 500, 50));
    miEmpresa.agregarProyecto(new ProyectoInterno(11, "Parque", 100, 25));

    miEmpresa.mostrarProyectos();

    cout << endl;
    miEmpresa.totalSalariosEmpleados();

    cout << endl;
    miEmpresa.proyectoConMasCosto();

}

