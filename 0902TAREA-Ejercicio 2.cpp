#include <iostream>

using namespace std;

class Producto
{
private:
    string nombre;
    int precio;
    int stock=0;

public:
    Producto(string nombreP,int precioP) { 
        nombre=nombreP;
        precio=precioP;
    }

    void mostrar()
    {
        cout << "DATOS DEL PRODUCTO" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
        cout << endl;
    }

    void setNombre(string nNombre)
    {
        nombre = nNombre;
    }

    void setPrecio(int nPrecio)
    {
        precio = nPrecio;
    }

    void setStock(int nStock)
    {
        stock = nStock;
    }
};


int main()
{
    Producto P1 = Producto("Coca Cola",12);

    P1.mostrar();
    P1.setStock(20);
    P1.setPrecio(14);
    P1.mostrar();
}

