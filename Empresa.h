#pragma once
#include "VectorEmpleados.h"
#include "VectorProyectos.h"

class Empresa {

private:
    VectorEmpleados* empleados;
    VectorProyectos* proyectos;

public:

    Empresa(int maxEmp, int maxProy) {
        empleados = new VectorEmpleados(maxEmp);
        proyectos = new VectorProyectos(maxProy);
    }

    ~Empresa() {
        delete empleados;
        delete proyectos;
    }

    void agregarEmpleado(Empleado* nuevoEmpleado) {
        empleados->agregar(nuevoEmpleado);
    }

    void agregarProyecto(Proyecto* nuevoProyecto) {
        proyectos->agregar(nuevoProyecto);
    }

    void mostrarTodo() {
        cout << "EMPLEADOS" << endl;
        empleados->mostrar();

        cout << "PROYECTOS" << endl;
        proyectos->mostrar();
    }

    void totalSalarios() {
        cout << "Total salarios: " << empleados->totalSalarios() << endl;
    }

    void mostrarProyectoMayorCosto() {
        Proyecto* p = proyectos->mayorCosto();

        if (p != nullptr) {
            cout << "Proyecto de mayor costo:" << endl;
            p->mostrar();
            cout << "Costo: " << p->calcularCosto() << endl;
        }
    }
};
