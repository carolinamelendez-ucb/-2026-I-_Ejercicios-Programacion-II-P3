// SalaCine.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "SistemaCine.h"
using namespace std;

int main()
{
    SistemaCine sistema(10, 10, 10, 10);
    try{
        sistema.agregarCliente(new Cliente(1, "Benjamin"));
        sistema.agregarCliente(new Cliente(2, "Alejandro"));
        sistema.agregarCliente(new Cliente(3, "Sofia"));

        sistema.agregarSala(new Sala(1, 5, 5));
        sistema.agregarSala(new Sala(2, 5, 5));
        sistema.agregarSala(new Sala(3, 5, 5));
        sistema.agregarSala(new Sala(4, 5, 5));

        sistema.agregarPelicula(new Pelicula("Asasa", 120));
        sistema.agregarPelicula(new Pelicula("ASA", 100));
        sistema.agregarPelicula(new Pelicula("saasa", 80));
        sistema.agregarPelicula(new Pelicula("dasdsa", 180));

        sistema.agregarFuncion(new Funcion(1));
        sistema.agregarFuncion(new Funcion(2));
        sistema.agregarFuncion(new Funcion(3));
        sistema.agregarFuncion(new Funcion(4));
    }
    catch (exception& err) {
        cout << err.what() << endl;
    }

    sistema.mostrarTodo();
}