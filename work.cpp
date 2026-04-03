#include <iostream>
#include <string>
#include "Administrador.h"
using namespace std;

int main()
{
    Empresa work;

    work.agregarEmpleado(new EmpleadoTiempoCompleto("Jose", 5, 6000));
    work.agregarEmpleado(new EmpleadoPorHoras("pedro", 4, 10, 15));

    work.agregarProyecto(new ProyectoInterno(101, "Administracion", 4000));
    work.agregarProyecto(new ProyectoExterno(102, "Aplicacion", 5000, 2000));

    work.mostrarTodo();
    work.totalSalarios();
    work.mostrarProyectoMayorCosto();

}