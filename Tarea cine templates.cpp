#include <iostream>
using namespace std;
#include "SistemaCine.h"

int main () {
    SistemaCine* sistema = new SistemaCine (50);

    // Registrar clientes
    sistema->registrarCliente (new Cliente ("Juan Perez", 12345678));
    sistema->registrarCliente (new Cliente ("Maria Lopez", 87654321));
    sistema->registrarCliente (new Cliente ("Carlos Romero", 11223344));

    // Registrar salas
    sistema->registrarSala (new Sala (1, 10, 15));
    sistema->registrarSala (new Sala (2, 8, 12));

    // Registrar peliculas
    sistema->registrarPelicula (new Pelicula ("Avengers", "Accion"));
    sistema->registrarPelicula (new Pelicula ("Titanic", "Romance"));
    sistema->registrarPelicula (new Pelicula ("Matrix", "Ciencia Ficcion"));

    // Registrar funciones (nroFuncion, capacidad)
    sistema->registrarFuncion (new Funcion (1, 10));
    sistema->registrarFuncion (new Funcion (2, 10));

    // 5. Asignar pelicula a funcion
    sistema->asignarPeliculaAFuncion (0, 0); // Funcion 1 <- Avengers
    sistema->asignarPeliculaAFuncion (1, 1); // Funcion 2 <- Titanic

    // 6. Asignar funcion a sala
    sistema->asignarFuncionASala (0, 0); // Sala 1 <- Funcion 1
    sistema->asignarFuncionASala (1, 1); // Sala 2 <- Funcion 2

    // 7. Asignar cliente a funcion
    sistema->asignarClienteAFuncion (0, 0); // Juan   -> Funcion 1
    sistema->asignarClienteAFuncion (1, 0); // Maria  -> Funcion 1
    sistema->asignarClienteAFuncion (2, 1); // Carlos -> Funcion 2

    // Mostrar todo
    cout << "\n";
    sistema->mostrarClientes ();
    cout << "\n";
    sistema->mostrarSalas ();
    cout << "\n";
    sistema->mostrarPeliculas ();
    cout << "\n";
    sistema->mostrarFunciones ();

    delete sistema;
    return 0;
}