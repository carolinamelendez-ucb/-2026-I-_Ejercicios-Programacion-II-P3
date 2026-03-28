#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;

    int main() {
        Sistema s(5, 5);
        cout << "--- REGISTRAR EMPLEADOS ---" << endl;
        s.registrarEmpleado("Juan", 123);
        s.registrarEmpleado("Maria", 456);
        s.registrarEmpleado("Luis", 789);
        s.registrarEmpleado("Pedro", 123); 
        cout << endl;
        cout << "--- REGISTRAR FUNCIONES ---" << endl;
        s.registrarFuncion("Pelicula A", 1, 10);
        s.registrarFuncion("Pelicula B", 2, 10);
        s.registrarFuncion("Pelicula C", 3, 10);
        s.registrarFuncion("Pelicula D", 4, 10);
        cout << endl;
        cout << "--- FINALIZAR FUNCIONES ---" << endl;
        s.finalizar(1);
        s.finalizar(2);
        cout << endl;
        cout << "--- NUEVA FUNCION ---" << endl;
        s.registrarFuncion("Pelicula E", 5, 10);
        cout << endl;
        cout << "--- EMPLEADOS ORDENADOS ---" << endl;
        s.mostrarEmpleadosOrdenados();
    }
