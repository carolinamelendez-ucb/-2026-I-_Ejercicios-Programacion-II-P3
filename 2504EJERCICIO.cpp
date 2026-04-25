#include <iostream>
#include <string>
#include "ArrayLlenoException.h"
#include "ArrayGenerico.h"
#include "Cliente.h"
#include "Sala.h"
#include "Pelicula.h"
#include "Funcion.h"
#include "SistemaCine.h"

using namespace std;

int main()
{
    SistemaCine sistema(5, 5, 5, 5);
    sistema.registrarCliente(new Cliente("Alejandro", 123));
    sistema.registrarCliente(new Cliente("Alejandro", 123));
    sistema.registrarCliente(new Cliente("Alejandro", 123));
    sistema.registrarCliente(new Cliente("Alejandro", 123));
    
    sistema.registrarFuncion(new Funcion(10));
    sistema.registrarFuncion(new Funcion(10));
    sistema.registrarFuncion(new Funcion(10));
    sistema.registrarFuncion(new Funcion(10));

    sistema.registrarPelicula(new Pelicula("El Mago de Oz", "a"));
    sistema.registrarPelicula(new Pelicula("El Mago de Oz", "a"));
    sistema.registrarPelicula(new Pelicula("El Mago de Oz", "a"));
    sistema.registrarPelicula(new Pelicula("El Mago de Oz", "a"));

    sistema.registrarSala(new Sala(1, 10, 15));
    sistema.registrarSala(new Sala(1, 10, 15));
    sistema.registrarSala(new Sala(1, 10, 15));
    sistema.registrarSala(new Sala(1, 10, 15));

    sistema.mostrarClientes();
    sistema.mostrarFunciones();
    sistema.mostrarPeliculas();
    sistema.mostrarSalas();
}