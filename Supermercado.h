#pragma once
#include "ListaProductos.h"

class Supermercado {

private:
    string nombre;
    string ubicacion;
    ListaProductos* lista;

public:

    Supermercado(const string& nombre, const string& ubicacion)
        : nombre(nombre), ubicacion(ubicacion) {
        lista = new ListaProductos(20);
    }

    ~Supermercado() {
        delete lista;
    }

    void agregarProducto(Producto* nuevoProducto) {
        lista->agregar(nuevoProducto);
    }

    void mostrarEnRango(float min, float max) {
        cout << "Supermercado: " << nombre << endl;
        lista->mostrarEnRango(min, max);
    }

    bool tieneMayorPrecioPromedioQue(Supermercado* otro) {
        return lista->promedioPrecios() > otro->lista->promedioPrecios();
    }

    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Ubicacion: " << ubicacion << endl;
        cout << "Precio promedio: " << lista->promedioPrecios() << endl;
    }
};
