#include <iostream>
#include <string>
#include "SuperMercado.h"
#include "ProductoFresco.h"
#include "ProductoPremium.h"
#include "ProductoEnvasado.h"
#include "ProductoPromocional.h"
using namespace std;
int main()
{
	SuperMercado* supermercadoA = new SuperMercado("Supermercado A", "Ciudad A");
	SuperMercado* supermercadoB = new SuperMercado("Supermercado B", "Ciudad Y");
	supermercadoA->agregarProducto(new ProductoFresco("Tomate", 8, 6));
	supermercadoA->agregarProducto(new ProductoEnvasado("Atun", 30, 2));
	supermercadoA->agregarProducto(new ProductoPromocional("Galletas", 12, 3, 5));

	supermercadoB->agregarProducto(new ProductoPremium("Cerveza Premium", 40, 3));
	supermercadoB->agregarProducto(new ProductoFresco("Hierbas", 4.5, 4));

	cout << "SUPERMERCADO 'A'" << endl;
	supermercadoA->mostrarDatos();
	cout << "SUPERMERCADO 'B'" << endl;
	supermercadoB->mostrarDatos();
	cout << "El supermercado con mayor precio promedio es: ";
	if (supermercadoA->tienePrecioPromedioMayor(supermercadoB)) {
		supermercadoA->mostrarDatos();
	}
	else {
		supermercadoB->mostrarDatos();
	}
	supermercadoA->mostrarProductosPorRango(10, 50);
	return 0;
}
