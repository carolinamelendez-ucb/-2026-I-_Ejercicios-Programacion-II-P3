#pragma once
#include <iostream>
#include <string>
#include "VectorEmpleados.h"
#include "VectorProyecto.h"
using namespace std;

class Empresa
{
private:
    VectorEmpleados* empleados;
    VectorProyectos* proyectos;
public:
    Empresa()
    {
        empleados = new VectorEmpleados(50);
        proyectos = new VectorProyectos(50);
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
        cout << "EMPLEADOS:" << endl;
        empleados->mostrar();

        cout << "PROYECTOS:" << endl;
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