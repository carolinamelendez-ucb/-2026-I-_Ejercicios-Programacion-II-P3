#pragma once
#include <iostream>
#include <string>
#include "VectorEmpleados.h"
#include "VectorProyectos.h"

using namespace std;

class Empresa {
private:
    VectorEmpleados* listaEmpleados;
    VectorProyectos* listaProyectos;

public:
    Empresa(int tamanioEmpleados, int tamanioProyectos) {
        listaEmpleados = new VectorEmpleados(tamanioEmpleados);
        listaProyectos = new VectorProyectos(tamanioProyectos);
    }

    void agregarEmpleado(Empleado* nuevoEmpleado) {
        Empleado* empleadoExistente = listaEmpleados->buscarPorCi(nuevoEmpleado->getCi());

        if (empleadoExistente == nullptr) {
            listaEmpleados->agregar(nuevoEmpleado);
            cout << "Empleado agregado exitosamente" << endl;
        }
        else {
            cout << "Error: Ya existe un empleado con CI " << nuevoEmpleado->getCi() << endl;
            delete nuevoEmpleado;
        }
    }

    void agregarProyecto(Proyecto* nuevoProyecto) {
        Proyecto* proyectoExistente = listaProyectos->buscarPorCodigo(nuevoProyecto->getCodigo());

        if (proyectoExistente == nullptr) {
            listaProyectos->agregar(nuevoProyecto);
            cout << "Proyecto agregado exitosamente" << endl;
        }
        else {
            cout << "Error: Ya existe un proyecto con codigo " << nuevoProyecto->getCodigo() << endl;
            delete nuevoProyecto;
        }
    }

    void mostrarEmpleados() {
        cout << "\n=== LISTA DE EMPLEADOS ===" << endl;
        if (listaEmpleados->getCantidad() == 0) {
            cout << "No hay empleados registrados" << endl;
        }
        else {
            listaEmpleados->mostrarTodos();
        }
    }

    void mostrarProyectos() {
        cout << "\n=== LISTA DE PROYECTOS ===" << endl;
        if (listaProyectos->getCantidad() == 0) {
            cout << "No hay proyectos registrados" << endl;
        }
        else {
            listaProyectos->mostrarTodos();
        }
    }

    void calcularTotalSalarios() {
        cout << "\n=== TOTAL DE SALARIOS ===" << endl;
        float total = listaEmpleados->calcularTotalSalarios();
        cout << "Total de salarios de todos los empleados: " << total << " Bs." << endl;
    }

    void mostrarProyectoMayorCosto() {
        cout << "\n=== PROYECTO CON MAYOR COSTO ===" << endl;
        Proyecto* mayor = listaProyectos->getProyectoMayorCosto();
        if (mayor != nullptr) {
            mayor->mostrarInformacion();
        }
        else {
            cout << "No hay proyectos registrados" << endl;
        }
    }

    void liberarMemoria() {
        listaEmpleados->liberarMemoria();
        listaProyectos->liberarMemoria();
        delete listaEmpleados;
        delete listaProyectos;
    }
};

