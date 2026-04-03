#include <iostream>
#include <string>

#include "Supermercado.h"
#include "ProductoFresco.h"
#include "ProductoEnvasado.h"
#include "ProductoPromocional.h"
#include "ProductoPremium.h"

using namespace std;

int main()
{
    Supermercado* supermercado1 = new Supermercado("Ic Norte", "Cochabamba", 20);
    Supermercado* supermercado2 = new Supermercado("Hipermaxi", "La Paz", 20);

    supermercado1->agregarProducto(new ProductoFresco(1, "Manzana", 2.50, 3));
    supermercado1->agregarProducto(new ProductoEnvasado(2, "Leche", 3.00, 1.0));
    supermercado1->agregarProducto(new ProductoPromocional(3, "Cereal", 5.00, 1.00, 6));
    supermercado1->agregarProducto(new ProductoPremium(4, "Cafe Premium", 15.00, 0.5));

    supermercado2->agregarProducto(new ProductoFresco(5, "Pera", 3.00, 5));
    supermercado2->agregarProducto(new ProductoEnvasado(6, "Jugo", 4.00, 1.5));
    supermercado2->agregarProducto(new ProductoPromocional(7, "Galletas", 2.50, 0.50, 3));
    supermercado2->agregarProducto(new ProductoPremium(8, "Chocolate Premium", 8.00, 0.3));

    cout << "=== Productos en rango 50-100 ===" << endl;
    supermercado1->mostrarProductosEnRango(50, 100);
    supermercado2->mostrarProductosEnRango(50, 100);

    cout << "El supermercado con mayor precio promedio es: ";
    if (supermercado1->tieneMayorPrecioPromedioQue(supermercado2)) {
        supermercado1->mostrarDatos();
    }
    else {
        supermercado2->mostrarDatos();
    }

    delete supermercado1;
    delete supermercado2;

    return 0;
}