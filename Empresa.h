#pragma once
#include "VectorEmpleados.h"
#include "VectorProyectos.h"

class Empresa {
private:
    VectorEmpleados* empleados;
    VectorProyectos* proyectos;

public:
    Empresa(int tamEmpleados, int tamProyector) {
        empleados = new VectorEmpleados(tamEmpleados);
        proyectos = new VectorProyectos(tamProyector);
    }

    void agregarEmpleado(Empleado* nuevoEmpleado) {
        if (!empleados->agregar(nuevoEmpleado))
            cout << "CI duplicado";
    }

    void agregarProyecto(Proyecto* nuevoProyecto) {
        if (!proyectos->agregar(nuevoProyecto))
            cout << "Codigo duplicado";
    }

    void mostrarTodo() {
        cout << "EMPLEADOS:";
        cout << endl;
        empleados->mostrar();

        cout << "PROYECTOS:";
        cout << endl;
        proyectos->mostrar();
    }

    void mostrarTotalSalarios() {
        cout << "Total salarios: "
            << empleados->totalSalarios() << endl;
    }

    void mostrarProyectoMayorCosto() {
        Proyecto* proyecto = proyectos->mayorCosto();
        if (proyecto != nullptr) {
            cout << "Proyecto de mayor costo:";
            proyecto->mostrarInformacion();
        }
    }
};