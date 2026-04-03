#include <iostream>
#include <string>
#include "Empresa.h"
using namespace std;

int main()
{
    Empresa emp;

    emp.agregarEmpleado(new EmpleadoTiempoCompleto("Juan", 1, 3000));
    emp.agregarEmpleado(new EmpleadoPorHoras("Ana", 2, 100, 20));

    emp.agregarProyecto(new ProyectoInterno(101, "Sistema", 5000));
    emp.agregarProyecto(new ProyectoExterno(102, "App", 7000, 1000));

    emp.mostrarTodo();
    emp.totalSalarios();
    emp.mostrarProyectoMayorCosto();

    return 0;
}

