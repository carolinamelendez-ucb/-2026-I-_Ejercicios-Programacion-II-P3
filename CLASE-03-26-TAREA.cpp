// CLASE-03-26-TAREA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "VectorEmpleados.h"
#include "VectorFunciones.h"
#include <iostream>

class SistemaAdministracion{
private:
    VectorEmpleados* listaEmpleados;
    VectorFunciones* listaFunciones;
public:
    SistemaAdministracion (int tamanioEmpleados, int tamanioFunciones){
        this->listaEmpleados = new VectorEmpleados (tamanioEmpleados);
        this->listaFunciones = new VectorFunciones (tamanioFunciones);

    }
    void registrarEmpleado (Empleado* nuevoEmpleado){
       Empleado* aux = listaEmpleados->verificarCiDuplicado(nuevoEmpleado->getCi());
       if(aux == nullptr){
           listaEmpleados->registrarEmpleado (nuevoEmpleado);

       }
    }

    void ordenarEmpleados (){
        listaEmpleados->ordenarPorFunciones();
    }

    void registrarFuncion (Funcion* nuevaFuncion){
         Empleado* empleadoAsignado = listaEmpleados->verificarDisponibilidad();
         if(empleadoAsignado != nullptr){
             Funcion* aux = listaFunciones->verificarCodigoDuplicado (nuevaFuncion->getCodigo ());
             if(aux == nullptr){
                nuevaFuncion->asignarEmpleadoAFuncion(empleadoAsignado);
                listaFunciones->registrarFuncion(nuevaFuncion);
             }
         }
    }

    void finalizarFuncion (int codigo){
         listaFunciones->finalizarFuncion(codigo);
    }

    void mostrarEmpleados () {
        listaEmpleados->mostrar ();
    }

    void mostrarFunciones () {
        listaFunciones->mostrar ();
    }
};

int main()
{
    SistemaAdministracion sistema (5, 5);
    //1
    sistema.registrarEmpleado (new Empleado ("Alan", 123));
    sistema.registrarEmpleado (new Empleado ("Juan", 456));
    sistema.registrarEmpleado (new Empleado ("Maria", 789));
    sistema.registrarEmpleado (new Empleado ("Pedro", 123));

    cout << "\n--- EMPLEADOS REGISTRADOS ---\n";
    sistema.mostrarEmpleados ();

    //2
    sistema.ordenarEmpleados ();

    cout << "\n--- EMPLEADOS ORDENADOS ---\n";
    sistema.mostrarEmpleados ();

    //3
    sistema.registrarFuncion (new Funcion ("Avengers", 1, 50));
    sistema.registrarFuncion (new Funcion ("Batman", 2, 40));
    sistema.registrarFuncion (new Funcion ("Spiderman", 3, 30));

    sistema.registrarFuncion (new Funcion ("Superman", 1, 60));

    cout << "\n--- FUNCIONES REGISTRADAS ---\n";
    sistema.mostrarFunciones ();

    //4
    sistema.finalizarFuncion (1); 

    cout << "\n--- EMPLEADOS ACTUALIZADOS ---\n";
    sistema.mostrarEmpleados ();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
