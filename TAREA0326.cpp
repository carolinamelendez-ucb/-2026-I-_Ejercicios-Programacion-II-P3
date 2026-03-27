// TAREA0326.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "SistemaCine.h"

using namespace std;
int main()
{
    SistemaCine miSistemaCine(5, 5);
    cout << "Registrando Empleados..." << endl;
    miSistemaCine.registrarEmpleados("Juan", 1);
    miSistemaCine.registrarEmpleados("Luciana", 2);
    miSistemaCine.registrarEmpleados("Marcela", 3);
    cout << "Mostrar Empleados: " << endl;
    miSistemaCine.mostrarEmpelados();

    cout << "Registrar Funciones..." << endl;
    miSistemaCine.RegistrarFunciones("La bella y la bestica", 11, 5);
    miSistemaCine.RegistrarFunciones("Rapidos y furiosos", 22, 5);
    miSistemaCine.RegistrarFunciones("Barbie", 11, 5);
    miSistemaCine.RegistrarFunciones("El libro de la vida", 33, 5);
    miSistemaCine.RegistrarFunciones("Ella", 44, 5);
    cout << "Mostrar funciones:" << endl;
    miSistemaCine.mostrarFunciones();
 
    cout << "Finalizar funcion..." << endl;

    miSistemaCine.finalizarFuncion(11);
    miSistemaCine.finalizarFuncion(22);
    miSistemaCine.finalizarFuncion(33);
    miSistemaCine.finalizarFuncion(44);

    cout << "Mostrar funciones:" << endl;
    miSistemaCine.mostrarFunciones();
  

}

