#pragma once
#include <iostream>
#include <string>
#include "VectorEmpleados.h"
#include "VectorProyectos.h"
using namespace std;

class Empresa
{
private:
    VectorEmpleados* empleados;
    VectorProyectos* proyectos;
public:
    Empresa()
    {
        empleados = new VectorEmpleados(10);
        proyectos = new VectorProyectos(10);
    }

    void agregarEmpleado(Empleado* e)
    {
        empleados->agregar(e);
    }

    void agregarProyecto(Proyecto* p)
    {
        proyectos->agregar(p);
    }

    void mostrarTodo()
    {
        cout << "--- EMPLEADOS ---" << endl;
        empleados->mostrar();

        cout << "--- PROYECTOS ---" << endl;
        proyectos->mostrar();
    }

    void totalSalarios()
    {
        cout << "Total salarios: " << empleados->totalSalarios() << endl;
    }

    void mostrarProyectoMayorCosto()
    {
        proyectos->proyectoMayorCosto();
    }
};
