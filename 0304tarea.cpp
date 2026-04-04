// 0304tarea.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
#include "ProductoFresco.h"
#include "ProductoEnvasado.h"
#include "ProductoPromocional.h"
#include "ProductoPremium.h"
#include "Supermercado.h"

using namespace std;

int main()
{
    SuperMercado hiper("Hipermaxi", "Cochabamba", 10);
    SuperMercado fidal("Fidalga", "Santa Cruz", 10);

    cout << "Agregando Productos Hipermaxi...." << endl;
    
    hiper.agregarProductos(new ProductoFresco("Pan", 30, 2));
    hiper.agregarProductos(new ProductoFresco("Lechuga", 25, 1));
    hiper.agregarProductos(new ProductoEnvasado("Cereal", 120, 1.5));
    hiper.agregarProductos(new ProductoPromocional("Galletas", 80, 10, 6));
    hiper.agregarProductos(new ProductoPremium("Vino Reserva", 300, 1.3));

    cout << endl;
    cout << "Agregando Productos Fidalga...." << endl;
    fidal.agregarProductos(new ProductoFresco("Manzana", 35, 4));
    fidal.agregarProductos(new ProductoEnvasado("Arroz", 100, 2));
    fidal.agregarProductos(new ProductoEnvasado("Fideos", 90, 1.2));
    fidal.agregarProductos(new ProductoPromocional("Chocolate", 120, 15, 3));
    fidal.agregarProductos(new ProductoPremium("Helado Artesanal", 150, 0.8));
    
    cout << endl;
    cout << "Productos en rango (50-150) de Hipermaxi: "<<endl;
    hiper.getLista()->mostrarPrecioRango(50, 150);

    // Mostrar el supermercado con precio promedio más alto
    cout << endl;
    cout << "Supermercado con mayor promedio: " << endl;

    if (hiper.promedio() > fidal.promedio()) {
        hiper.mostrar();
    }
    else {
        fidal.mostrar();
    }

    return 0;
}
