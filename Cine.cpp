// Cine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SistemCine.h"
#include <string>

using namespace std;

int main()
{
	SistemaCine cine(10, 10);

	//registrar Empleados
	cine.registrarEmpleado("JUAN", "123");
	cine.registrarEmpleado("PEDRO", "456");
	cine.registrarEmpleado("MARIA", "789");
	//intento de duplicado
	cine.registrarEmpleado("LUIS", "123");

	//registrar Funcones

	cine.registrarFuncion("F1", "need for speed", 20);
	cine.registrarFuncion("F2", "The witcher ", 30);


	//empleados ordenados mostrar
	cout << "Empleados..." << endl;
	cine.mostrarEmpleadosOrdenados();


	//finalizar Funcion
	cine.finalizarFuncion("F1");


	cout << "Empleaodos .. Depues del cambioo" << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------------0" << endl;
	cout << endl;
	cine.mostrarEmpleadosOrdenados();


	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
