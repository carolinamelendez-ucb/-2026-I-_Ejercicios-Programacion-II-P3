// Ejercicio 3-Practica clase.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include "Sistema.h"

int main()
{
    try
    {
        Sistema sistema(30, 30, 30);

        Sala* sala1 = new Sala(1, 10, 15);
        Sala* sala2 = new Sala(2, 8, 12);

        Pelicula* peli1 = new Pelicula("Avatar", "Pelicula de ciencia ficcion");
        Pelicula* peli2 = new Pelicula("Titanic", "Pelicula romantica");

        Cliente* cliente1 = new Cliente("Carlos", 12345);
        Cliente* cliente2 = new Cliente("Ana", 67890);

        Funcion* funcion1 = new Funcion("18:30", 5);

        funcion1->asiganrPleicula(peli1);
        funcion1->asiganrSala(sala1);
        funcion1->asiganrClientes(cliente1);
        funcion1->asiganrClientes(cliente2);

        sistema.registrtarSala(sala1);
        sistema.registrtarSala(sala2);

        sistema.registrtarPeliculas(peli1);
        sistema.registrtarPeliculas(peli2);

        sistema.registrtarFunciones(funcion1);

        sistema.mostrarSalas();

        sistema.mostrarPeliculas();

        sistema.mostrarFunciones();
    }
    catch (exception& err)
    {
        cout << "Error: " << err.what() << endl;
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
