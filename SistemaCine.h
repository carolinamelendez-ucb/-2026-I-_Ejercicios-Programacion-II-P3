#pragma once
#include "VectorEmpleados.h"
#include "VectorFunciones.h"

class SistemaCine {

private:
    VectorEmpleados* empleados;
    VectorFunciones* funciones;

public:

    SistemaCine(int maxEmpleados, int maxFunciones) {
        empleados = new VectorEmpleados(maxEmpleados);
        funciones = new VectorFunciones(maxFunciones);
    }

    ~SistemaCine() {
        delete empleados;
        delete funciones;
    }

    void registrarEmpleado(const string& nombre, int ci) {
        empleados->agregar(new Empleado(nombre, ci));
    }

    void mostrarEmpleadosOrdenados() {
        empleados->ordenarPorFunciones();
        empleados->mostrar();
    }

    void registrarFuncion(int codigo, const string& nombrePelicula, int maxEspectadores) {

        if (funciones->buscar(codigo) != nullptr) {
            cout << "Codigo de funcion duplicado" << endl;
            return;
        }

        Empleado* empleadoDisponible = empleados->buscarLibreConMenosFunciones();

        if (empleadoDisponible == nullptr) {
            cout << "No hay empleados libres" << endl;
            return;
        }

        funciones->agregar(new Funcion(codigo, nombrePelicula, maxEspectadores, empleadoDisponible));
    }

    void finalizarFuncion(int codigo) {
        Funcion* funcion = funciones->buscar(codigo);

        if (funcion != nullptr && funcion->estaActiva()) {
            funcion->finalizar();
            cout << "Funcion finalizada correctamente" << endl;
        }
    }

    void mostrarFunciones() {
        funciones->mostrar();
    }
};