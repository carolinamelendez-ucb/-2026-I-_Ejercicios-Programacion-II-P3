#include "Supermercado.h"
#include "ProductoFresco.h"
#include "ProductoEnvasado.h"
#include "ProductoPromocional.h"
#include "ProductoPremium.h"

int main() {

    Supermercado* supermercadoA = new Supermercado("Super A", "Ciudad X");
    Supermercado* supermercadoB = new Supermercado("Super B", "Ciudad Y");


    supermercadoA->agregarProducto(new ProductoFresco("Lechuga", 10, 2));
    supermercadoA->agregarProducto(new ProductoEnvasado("Arroz", 20, 1.5));
    supermercadoA->agregarProducto(new ProductoPromocional("Galletas", 15, 2, 6));

   
    supermercadoB->agregarProducto(new ProductoPremium("Queso Premium", 30, 2));
    supermercadoB->agregarProducto(new ProductoFresco("Tomate", 12, 5));

    cout << "--- SUPERMERCADO A ---";
    supermercadoA->mostrarDatos();

    cout << "--- SUPERMERCADO B ---";
    supermercadoB->mostrarDatos();

    
    cout << "El supermercado con mayor precio promedio es:";

    if (supermercadoA->tieneMayorPrecioPromedioQue(supermercadoB)) {
        supermercadoA->mostrarDatos();
    }
    else {
        supermercadoB->mostrarDatos();
    }

    
    supermercadoA->mostrarProductosEnRango(10, 50);

    return 0;
}