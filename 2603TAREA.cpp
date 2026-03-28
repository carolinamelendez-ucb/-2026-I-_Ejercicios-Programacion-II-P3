#include <iostream>
#include "SistemaCine.h"

using namespace std;

int main() {

    SistemaCine sistema(5, 5);

    sistema.registrarEmpleado("Carlos", 111);
    sistema.registrarEmpleado("Ana", 222);
    sistema.registrarEmpleado("Luis", 333);

    cout << "EMPLEADOS ORDENADOS" << endl;
    sistema.mostrarEmpleadosOrdenados();

    sistema.registrarFuncion(1, "Avengers", 3);
    sistema.registrarFuncion(2, "Batman", 2);

    cout << endl << "FUNCIONES" << endl;
    sistema.mostrarFunciones();

    sistema.finalizarFuncion(1);

    cout << endl << "EMPLEADOS ACTUALIZADOS" << endl;
    sistema.mostrarEmpleadosOrdenados();

    return 0;
}