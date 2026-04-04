// tarea2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
using namespace std;

class Producto {
protected:
    string nombre;
    double precioBase;

public:
    Producto(string n, double p) : nombre(n), precioBase(p) {}

    virtual double calcularPrecioFinal() = 0;

    string getNombre() {
        return nombre;
    }

    virtual ~Producto() {}
};

class ProductoFresco : public Producto {
private:
    int diasRestantes;

public:
    ProductoFresco(string n, double p, int dias)
        : Producto(n, p), diasRestantes(dias) {
    }

    double calcularPrecioFinal() override {
        double descuento = 0.05 * (7 - diasRestantes);

        if (descuento < 0) descuento = 0;
        if (descuento > 0.3) descuento = 0.3;

        return precioBase * (1 - descuento);
    }
};

class ProductoEnvasado : public Producto {
protected:
    double pesoKg;

public:
    ProductoEnvasado(string n, double p, double peso)
        : Producto(n, p), pesoKg(peso) {
    }

    double calcularPrecioFinal() override {
        return precioBase * 1.10 + (pesoKg * 2);
    }
};

class ProductoPromocional : public Producto {
private:
    double descuentoPromocional;
    int cantidad;

public:
    ProductoPromocional(string n, double p, double desc, int cant)
        : Producto(n, p), descuentoPromocional(desc), cantidad(cant) {
    }

    double calcularPrecioFinal() override {
        double extra = 0;
        if (cantidad > 5) {
            extra = precioBase * 0.05;
        }
        return precioBase - descuentoPromocional - extra;
    }
};

class ProductoPremium : public ProductoEnvasado {
public:
    ProductoPremium(string n, double p, double peso)
        : ProductoEnvasado(n, p, peso) {
    }

    double calcularPrecioFinal() override {
        double base = ProductoEnvasado::calcularPrecioFinal();
        return base * 1.15;
    }
};

class ListaProductos {
private:
    Producto** arr;
    int n;

public:
    ListaProductos() {
        arr = NULL;
        n = 0;
    }

    void agregarProducto(Producto* p) {
        Producto** nuevo = new Producto * [n + 1];

        for (int i = 0; i < n; i++) {
            nuevo[i] = arr[i];
        }

        nuevo[n] = p;

        delete[] arr;
        arr = nuevo;
        n++;
    }

    void mostrarPorRango(double min, double max) {
        cout << "Productos en rango [" << min << " - " << max << "] ";

        for (int i = 0; i < n; i++) {
            double precio = arr[i]->calcularPrecioFinal();

            if (precio >= min && precio <= max) {
                cout << arr[i]->getNombre()
                    << "  Precio Final: " << precio << endl;
            }
        }
    }

    double promedioPrecios() {
        if (n == 0) return 0;

        double suma = 0;
        for (int i = 0; i < n; i++) {
            suma += arr[i]->calcularPrecioFinal();
        }
        return suma / n;
    }
};

class Supermercado {
private:
    string nombre;
    string ubicacion;
    ListaProductos lista;

public:
    Supermercado(string n, string u) {
        nombre = n;
        ubicacion = u;
    }

    void agregarProducto(Producto* p) {
        lista.agregarProducto(p);
    }

    void mostrarPorRango(double min, double max) {
        lista.mostrarPorRango(min, max);
    }

    double getPromedio() {
        return lista.promedioPrecios();
    }

    bool tieneMayorPrecioPromedioQue(Supermercado* otro) {
        return this->getPromedio() > otro->getPromedio();
    }

    void mostrarDatos() {
        cout << nombre << " (" << ubicacion << ")";
        cout << "  Promedio: " << getPromedio() << endl;
    }
};

int main() {
    Supermercado* supermercado1 = new Supermercado("Super A", "Ciudad X");
    Supermercado* supermercado2 = new Supermercado("Super B", "Ciudad Y");

    supermercado1->agregarProducto(new ProductoFresco("Leche", 50, 3));
    supermercado1->agregarProducto(new ProductoEnvasado("Arroz", 80, 2));
    supermercado1->agregarProducto(new ProductoPromocional("Galletas", 60, 10, 6));
    supermercado1->agregarProducto(new ProductoPremium("Queso", 100, 1.5));

    supermercado2->agregarProducto(new ProductoFresco("Yogurt", 40, 1));
    supermercado2->agregarProducto(new ProductoEnvasado("Fideos", 70, 1));
    supermercado2->agregarProducto(new ProductoPromocional("Chocolate", 90, 15, 3));
    supermercado2->agregarProducto(new ProductoPremium("Jamon", 120, 2));

    
    supermercado1->mostrarPorRango(50, 100);
    supermercado2->mostrarPorRango(50, 100);

    
    cout << "El supermercado con mayor precio promedio es: "<<endl;

    if (supermercado1->tieneMayorPrecioPromedioQue(supermercado2)) {
        supermercado1->mostrarDatos();
    }
    else {
        supermercado2->mostrarDatos();
    }

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
