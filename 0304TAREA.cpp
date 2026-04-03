#include <iostream>
#include "Supermercado.h"
#include "ProductoFresco.h"
#include "ProductoEnvasado.h"
#include "ProductoPromocional.h"
#include "ProductoPremium.h"

using namespace std;

int main() {

    Supermercado* super1 = new Supermercado("Super A", "Ciudad X");
    Supermercado* super2 = new Supermercado("Super B", "Ciudad Y");

    cout << "Agregando productos a Super A" << endl << endl;

    super1->agregarProducto(new ProductoFresco("Leche", 50, 2));
    super1->agregarProducto(new ProductoEnvasado("Arroz", 40, 3));
    super1->agregarProducto(new ProductoPromocional("Galletas", 30, 5, 6));
    super1->agregarProducto(new ProductoPremium("Queso", 80, 2));

    cout << "Agregando productos a Super B" << endl << endl;

    super2->agregarProducto(new ProductoFresco("Yogurt", 60, 5));
    super2->agregarProducto(new ProductoPremium("Jamón", 90, 1.5));
    super2->agregarProducto(new ProductoPromocional("Chocolate", 70, 10, 3));

    cout << endl << "Productos en rango 50-100 (Super A)" << endl;
    super1->mostrarEnRango(50, 100);

    cout << endl << "Productos en rango 50-100 (Super B)" << endl;
    super2->mostrarEnRango(50, 100);

    cout << endl;
    cout << "El supermercado con mayor precio promedio es: " << endl;

    if (super1->tieneMayorPrecioPromedioQue(super2)) {
        super1->mostrarDatos();
    }
    else {
        super2->mostrarDatos();
    }
}