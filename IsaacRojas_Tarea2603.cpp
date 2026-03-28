#include <iostream>
#include <string>
#include "SistemaCine.h"
using namespace std;
int main()
{
    SistemaCine sistema(5, 5);
    sistema.registrarEmpleados("Yulian", 101);
    sistema.registrarEmpleados("Alex", 102);
    sistema.registrarEmpleados("Analucia", 103);
    cout << "EMPLEADOS ORDENADOS CON MAYOR CANTIDAD DE FUNCIONES ATENDIDAS" << endl;
    sistema.mostrarEmpleadosOrdenados();
    sistema.registrarFuncion(1, "SpiderMan", 4);
    sistema.registrarFuncion(2, "Superman", 3);
    cout << "FUNCIONES" << endl;
    sistema.mostrarFunciones();
    sistema.finalizarFuncion(1);
    cout << "EMPLEADOS ACTUALIZADOS" << endl;
    sistema.mostrarEmpleadosOrdenados();
    return 0;
}
