// tareaPractica_1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
#include"biblioteca.h"
#include<exception>
using namespace std;

int main()
{
    biblioteca lista = biblioteca(4, 4);
    lista.AgregarLibro(new libro(1, "El principito", "manuel", "Disponible", 2));
    lista.AgregarLibro(new libro(2, "Don Quijote ", "miguel", "Prestado", 1));
    lista.AgregarLibro(new libro(3, "El viaje a la luna", "Dorial", "En Reparacion", 3));
    lista.AgregarLibro(new libro(4, "El mostruo", "lunaria", "Disponible", 1));
    lista.AgregarEstudiantes(new Estudiante(1, "lucho", 1));
    lista.AgregarEstudiantes(new Estudiante(2, "Nacho", 2));
    lista.AgregarEstudiantes(new Estudiante(3, "lucas", 3));
    lista.AgregarEstudiantes(new Estudiante(4, "Manuel", 4));
    lista.mostrarTodo();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
