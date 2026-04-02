#include <iostream>
#include <string>
using namespace std;

class Producto {
protected:
    string nombre;
    float precioBase;

public:
    Producto(string nombre, float precioBase) {
        this->nombre = nombre;
        this->precioBase = precioBase;
    }

    string getNombre() { 
        return nombre; 
    }

    virtual float calcularPrecioFinal() = 0;
};

class ProductoFresco : public Producto {
private:
    int diasRestantes;

public:
    ProductoFresco(string nombre, float precioBase, int diasRestantes)
        : Producto(nombre, precioBase) {
        this->diasRestantes = diasRestantes;
    }

    float calcularPrecioFinal() override {
        float descuento = 0.05 * (7 - diasRestantes);
        if (descuento < 0) {
            descuento = 0;
        }
        else {
            if (descuento > 0.3) descuento = 0.3;
            return precioBase * (1 - descuento);
        }
    }
};

class ProductoEnvasado : public Producto {
protected:
    float pesoKg;

public:
    ProductoEnvasado(string nombre, float precioBase, float pesoKg)
        : Producto(nombre, precioBase) {
        this->pesoKg = pesoKg;
    }

    float calcularPrecioFinal() override {
        return precioBase * 1.10 + (pesoKg * 2);
    }
};

class ProductoPromocional : public Producto {
private:
    float descuentoPromocional;
    int cantidad;

public:
    ProductoPromocional(string nombre, float precioBase, float descuentoPromocional, int cantidad)
        : Producto(nombre, precioBase) {
        this->descuentoPromocional = descuentoPromocional;
        this->cantidad = cantidad;
    }

    float calcularPrecioFinal() override {
        float extra = 0;
        if (cantidad > 5) {
            extra = precioBase * 0.05;
        }
        return precioBase - descuentoPromocional - extra;
    }
};

class ProductoPremium : public ProductoEnvasado {
public:
    ProductoPremium(string nombre, float precioBase, float pesoKg)
        : ProductoEnvasado(nombre, precioBase, pesoKg) {
    }

    float calcularPrecioFinal() override {
        float base = precioBase * 1.10 + (pesoKg * 2);
        return base * 1.15;
    }
};

class ListaProductos {
private:
    Producto** productos;
    int tamanio;
    int indice;

public:
    ListaProductos(int tamanio) {
        this->tamanio = tamanio;
        this->indice = 0;
        productos = new Producto * [tamanio];
    }

    void agregar(Producto* p) {
        if (indice < tamanio) {
            productos[indice++] = p;
        }
    }

    void mostrarEnRango(float min, float maxRango) {
        cout << "Productos en rango [" << min << " - " << maxRango << "]: " << endl;
        for (int i = 0; i < indice; i++) {
            float precio = productos[i]->calcularPrecioFinal();
            if (precio >= min && precio <= maxRango) {
                cout << productos[i]->getNombre()
                    << " - " << precio << endl;
            }
        }
    }

    float promedioPrecios() {
        if (indice == 0) return 0;
        float suma = 0;
        for (int i = 0; i < indice; i++) {
            suma = suma + productos[i]->calcularPrecioFinal();
        }
        return suma / indice;
    }
};

class Supermercado {
private:
    string nombre;
    string ubicacion;
    ListaProductos lista;

public:
    Supermercado(string nombre, string ubicacion, int maxProd = 20)
        : lista(maxProd) {
        this->nombre = nombre;
        this->ubicacion = ubicacion;
    }

    void agregarProducto(Producto* p) {
        lista.agregar(p);
    }

    void mostrarDatos() {
        cout << nombre << " - " << ubicacion << endl;
        cout << "Promedio precios: " << lista.promedioPrecios() << endl;
    }

    bool tieneMayorPrecioPromedioQue(Supermercado* otro) {
        return lista.promedioPrecios() > otro->lista.promedioPrecios();
    }

    void mostrarProductosEnRango(float min, float tamanio) {
        lista.mostrarEnRango(min, tamanio);
    }
};

int main() {
    Supermercado* s1 = new Supermercado("Super A", "Ciudad X");
    Supermercado* s2 = new Supermercado("Super B", "Ciudad Y");
    s1->agregarProducto(new ProductoFresco("Leche", 50, 3));
    s1->agregarProducto(new ProductoEnvasado("Arroz", 40, 2));
    s1->agregarProducto(new ProductoPromocional("Galletas", 50, 5, 6));
    s2->agregarProducto(new ProductoPremium("Queso Premium", 60, 1.5));
    s2->agregarProducto(new ProductoFresco("Yogurt", 45, 6));
    cout << "SUPERMERCADO A" << endl;
    s1->mostrarProductosEnRango(30, 100);
    cout << endl;
    cout << "SUPERMERCADO B" << endl;
    s2->mostrarProductosEnRango(30, 100);
    cout << endl;
    cout << "Supermercado con mayor precio promedio: " << endl;
    if (s1->tieneMayorPrecioPromedioQue(s2)) {
        s1->mostrarDatos();
    }
    else {
        s2->mostrarDatos();
    }
}