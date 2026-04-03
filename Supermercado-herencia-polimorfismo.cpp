// Supermercado-herencia-polimorfismo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <string>
#include "Supermercado.h"
#include "ProductoFresco.h"
#include "ProductoEnvasado.h"
#include "ProductoPremium.h"
#include "ProductoPromocional.h"
using namespace std;

int main()
{
	Supermercado* super1 = new Supermercado("hipermaxi", "juan de la rosa", 10);
	Supermercado* super2 = new Supermercado("ic norte", "america", 10);

	super1->registrarProducto(new ProductoFresco("lechuga", 20, 2));
	super1->registrarProducto(new ProductoEnvasado("Arroz", 60, 3));
	super1->registrarProducto(new ProductoPromocional("Galletas", 80, 10, 6));
	super1->registrarProducto(new ProductoPremium("Cafe Premium", 100, 2));

	super2->registrarProducto(new ProductoFresco("Tomate", 25, 1));
	super2->registrarProducto(new ProductoEnvasado("Azucar", 50, 4));
	super2->registrarProducto(new ProductoPromocional("Chocolate", 120, 15, 3));
	super2->registrarProducto(new ProductoPremium("Queso Importado", 150, 1.5));


	cout<<"---------super 1------------"<<endl;
	super1->mostrarProductosEnRango(50, 100);

	cout<<"---------super 2------------"<<endl;
	super2->mostrarProductosEnRango(50, 100);

	cout << "El supermercado con mayor precio promedio es: " << endl;

	if (super1->mayorPrecioPromedio(super2))
	{
		super1->mostrarDatos();
	}
	else
	{
		super2->mostrarDatos();
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
