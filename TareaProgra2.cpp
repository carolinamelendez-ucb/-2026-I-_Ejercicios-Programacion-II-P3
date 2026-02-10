#include <iostream>
using namespace std;

class Producto
{
private:
    string nombre;
    float precio;
    int stock;

public:
    Producto(string n, float p)
    {
        nombre = n;
        precio = p;
        stock = 0;
    }

    void setNombre(string n)
    {
        nombre = n;
    }

    void setPrecio(float p)
    {
        precio = p;
    }

    void setStock(int s)
    {
        stock = s;
    }

    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
    }
};

int main()
{
    Producto producto1("Teclado", 120.5);

    producto1.mostrar();

    cout << endl;

    producto1.setStock(10);
    producto1.setPrecio(110.0);

    producto1.mostrar();

    return 0;
}
