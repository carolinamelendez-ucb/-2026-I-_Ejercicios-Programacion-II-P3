// practica.5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
using namespace std;
#include"vectorInstructor.h"
#include"instructores.h"
int main()
{
	VectorInstructor lista(5);
	lista.agregar(new Instructor("carlos", 1234, 3, false));
	lista.agregar(new Instructor("lucas", 2345, 1, true));
	lista.agregar(new Instructor("juan", 3456, 0, false));
	lista.agregar(new Instructor("lisa", 4567, 4, true));
	lista.agregar(new Instructor("marcos", 5678, 2, false));
	//lista.mostrar();
	
	///ejercicio1 despues de mostrar
	lista.mostrarOrdenado();
	lista.mostrar();
	
	///ejercicio2 asignar instructor libre

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
