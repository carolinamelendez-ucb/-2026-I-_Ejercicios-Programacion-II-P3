#include <iostream>
#include "Empresa.h"
#include "EmpleadoTiempoCompleto.h"
#include "EmpleadoPorHoras.h"
#include "ProyectoInterno.h"
#include "ProyectoExterno.h"

using namespace std;

int main() {

    Empresa empresa(5, 5);

    cout << "Registrando empleados" << endl;
    cout << endl;

    empresa.agregarEmpleado(new EmpleadoTiempoCompleto("Carlos", "111", 3000, 500));
    empresa.agregarEmpleado(new EmpleadoPorHoras("Ana", "222", 120, 20));
    empresa.agregarEmpleado(new EmpleadoPorHoras("Luis", "333", 100, 15));
    empresa.agregarEmpleado(new EmpleadoPorHoras("Luis", "111", 80, 10)); // duplicado

    cout << endl;
    cout << "Mostrando empleados" << endl;
    cout << endl;

    empresa.mostrarTodo();

    cout << endl;
    cout << "Registrando proyectos" << endl;
    cout << endl;

    empresa.agregarProyecto(new ProyectoInterno("P1", "Sistema", 5000, 1000));
    empresa.agregarProyecto(new ProyectoExterno("P2", "App", 8000, 0.1));
    empresa.agregarProyecto(new ProyectoExterno("P3", "Web", 2000, 0.2));
    empresa.agregarProyecto(new ProyectoInterno("P1", "Duplicado", 1000, 200)); // duplicado

    cout << endl;
    cout << "Mostrando todo (empleados y proyectos)" << endl;
    cout << endl;

    empresa.mostrarTodo();

    cout << endl;
    cout << "Calculando total de salarios" << endl;
    cout << endl;

    empresa.totalSalarios();

    cout << endl;
    cout << "Mostrando proyecto de mayor costo" << endl;
    cout << endl;

    empresa.mostrarProyectoMayorCosto();
}