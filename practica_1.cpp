// practica_1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
#include"Empresa.h"
using namespace std;

int main()
{
	Empresa empresa(5, 5);
	//empleados
	empresa.agregarEmpleado(new EmpleadoTiempoCompleto("Ana", 123, 3000, 500));
	empresa.agregarEmpleado(new EmpleadoTiempoCompleto("Carlos", 234, 3000, 400));
	empresa.agregarEmpleado(new EmpleadoTipoHoras("Ana", 345, 160, 20));
	//proyectos
	empresa.agregarProyecto(new ProyectoInterno(101, "sistemas", 5000));
	empresa.agregarProyecto(new ProyectoExterno(102, "app cliente", 4000, 1500));

	empresa.mostarTodo();
	cout << endl;
	empresa.totalSalarios();
	cout << endl;
	empresa.proyectoMayor();

	
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
