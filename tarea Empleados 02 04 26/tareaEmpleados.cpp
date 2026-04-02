#include <iostream>
#include <string>

#include "Empresa.h"
#include "EmpleadoTiempoCompleto.h"
#include "EmpleadoPorHoras.h"
#include "ProyectoInterno.h"
#include "ProyectoExterno.h"

using namespace std;

int main()
{
    Empresa miEmpresa = Empresa(10, 10);

    cout << "=== REGISTRO DE EMPLEADOS ===" << endl;
    miEmpresa.agregarEmpleado(new EmpleadoTiempoCompleto(1, "Marcelo", 200, 8, 500));
    miEmpresa.agregarEmpleado(new EmpleadoPorHoras(2, "Mauricio", 50, 6));
    miEmpresa.agregarEmpleado(new EmpleadoTiempoCompleto(3, "Carlos", 180, 7, 300));
    miEmpresa.agregarEmpleado(new EmpleadoPorHoras(4, "Laura", 45, 8));
    miEmpresa.agregarEmpleado(new EmpleadoTiempoCompleto(1, "Pedro", 150, 6, 200));

    cout << "\n=== REGISTRO DE PROYECTOS ===" << endl;
    miEmpresa.agregarProyecto(new ProyectoInterno(101, "Sistema Contable", 6, 5000, 8000));
    miEmpresa.agregarProyecto(new ProyectoExterno(102, "Construccion Puente", 4, 10000, 3000, 1500));
    miEmpresa.agregarProyecto(new ProyectoInterno(103, "App Movil", 8, 7000, 12000));
    miEmpresa.agregarProyecto(new ProyectoExterno(101, "Otro Proyecto", 3, 2000, 1000, 500));

    miEmpresa.mostrarEmpleados();
    miEmpresa.mostrarProyectos();
    miEmpresa.calcularTotalSalarios();
    miEmpresa.mostrarProyectoMayorCosto();

    miEmpresa.liberarMemoria();

    return 0;
}