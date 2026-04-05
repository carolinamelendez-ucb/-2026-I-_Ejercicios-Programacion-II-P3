#include <iostream>
#include <string>
using namespace std;


class Producto
{
protected:
    string nombre;
    float precioBase;

public:
    Producto(string nombre, float precioBase)
    {
        this->nombre = nombre;
        this->precioBase = precioBase;
    }
    string getNombre()
    {
        return nombre;
    }
    virtual float calcularPrecioFinal() = 0;

    virtual ~Producto() {}
};



class ProductoFresco : public Producto
{
private:
    int diasRestantes;
public:
    ProductoFresco(string nombre, float precioBase, int diasRestantes)
        : Producto(nombre, precioBase)
    {
        this->diasRestantes = diasRestantes;
    }

    float calcularPrecioFinal()
    {
        float descuento = 0.05 * (7 - diasRestantes);
        if (descuento > 0.3) descuento = 0.3;
        return precioBase * (1 - descuento);
    }
};

class ProductoEnvasado : public Producto
{
protected:
    float pesoKg;
public:
    ProductoEnvasado(string nombre, float precioBase, float pesoKg)
        : Producto(nombre, precioBase)
    {
        this->pesoKg = pesoKg;
    }
    float calcularPrecioFinal()
    {
        return precioBase * 1.10 + (pesoKg * 2);
    }
};

class ProductoPromocional : public Producto
{
private:
    float descuentoPromocional;
    int cantidad;
public:
    ProductoPromocional(string nombre, float precioBase, float descuentoPromocional, int cantidad)
        : Producto(nombre, precioBase)
    {
        this->descuentoPromocional = descuentoPromocional;
        this->cantidad = cantidad;
    }
    float calcularPrecioFinal()
    {
        float extra = (cantidad > 5) ? (precioBase * 0.05) : 0;
        return precioBase - descuentoPromocional - extra;
    }
};
class ProductoPremium : public ProductoEnvasado
{
public:
    ProductoPremium(string nombre, float precioBase, float pesoKg)
        : ProductoEnvasado(nombre, precioBase, pesoKg)
    {
    }
    float calcularPrecioFinal()
    {
        float base = ProductoEnvasado::calcularPrecioFinal();
        return base * 1.15;
    }
};



class ListaProductos
{
private:
    Producto** productos;
    int tamanio;
    int indice;

public:
    ListaProductos(int tamanio)
    {
        this->tamanio = tamanio;
        indice = 0;
        productos = new Producto * [tamanio];
    }
    void agregar(Producto* p)
    {
        if (indice < tamanio)
        {
            productos[indice++] = p;
        }
    }
    void mostrarEnRango(float min, float max)
    {
        for (int i = 0; i < indice; i++)
        {
            float precio = productos[i]->calcularPrecioFinal();
            if (precio >= min && precio <= max)
            {
                cout << productos[i]->getNombre()
                    << " - Precio: " << precio << endl;
            }
        }
    }
    float promedioPrecios()
    {
        if (indice == 0) return 0;

        float suma = 0;
        for (int i = 0; i < indice; i++)
        {
            suma += productos[i]->calcularPrecioFinal();
        }
        return suma / indice;
    }
};



class Supermercado
{
private:
    string nombre;
    string ubicacion;
    ListaProductos* lista;
public:
    Supermercado(string nombre, string ubicacion)
    {
        this->nombre = nombre;
        this->ubicacion = ubicacion;
        lista = new ListaProductos(20);
    }
    void agregarProducto(Producto* p)
    {
        lista->agregar(p);
    }
    void mostrarProductosEnRango(float min, float max)
    {
        lista->mostrarEnRango(min, max);
    }
    float getPromedio()
    {
        return lista->promedioPrecios();
    }
    bool tieneMayorPrecioPromedioQue(Supermercado* otro)
    {
        return this->getPromedio() > otro->getPromedio();
    }
    void mostrarDatos()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Ubicacion: " << ubicacion << endl;
        cout << "Promedio precios: " << getPromedio() << endl;
    }
};



int main()
{
    Supermercado* s1 = new Supermercado("Hipermaxi", "La Paz");
    Supermercado* s2 = new Supermercado("IC Norte", "Cochabamba");

    s1->agregarProducto(new ProductoFresco("Lechuga", 50, 3));
    s1->agregarProducto(new ProductoEnvasado("Arroz", 80, 2));
    s1->agregarProducto(new ProductoPromocional("Galletas", 60, 10, 6));

    s2->agregarProducto(new ProductoPremium("Chocolate", 100, 1));
    s2->agregarProducto(new ProductoEnvasado("Fideos", 40, 1));
    s2->agregarProducto(new ProductoFresco("Tomate", 30, 5));

    cout << "Productos entre 50 y 100 (Hipermaxi): " << endl;
    s1->mostrarProductosEnRango(50, 100);

    cout << "\nEl supermercado con mayor precio promedio es:" << endl;
    if (s1->tieneMayorPrecioPromedioQue(s2))
    {
        s1->mostrarDatos();
    }
    else
    {
        s2->mostrarDatos();
    }
    return 0;
}