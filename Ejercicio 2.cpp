
#include <iostream>
#include <string>

using namespace std;

class Producto
{
private:
    string nombre;
    int precio;
    int stock;
public:

    Producto(string nombre, int precio) {
        this->nombre = nombre;
        this->precio = precio;
        this->stock = 0;
    }

    void setNombre(string nuevoNombre) {
        this->nombre = nuevoNombre;
    }

    void setPrecio(int nuevoPrecio) {
        this->precio = nuevoPrecio;
    }

    void setStock(int nuevoStock) {
        this->stock = nuevoStock;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << " unidades" << endl;
    }
};

int main()
{
    Producto producto1 = Producto("Laptop", 899.99);


    cout << "Producto inicial: " << endl;
    producto1.mostrar();
    cout << endl;

    cout << "Actualizando stock..." << endl;
    producto1.setStock(15);

    cout << "Actualizando precio..." << endl;
    producto1.setPrecio(849.99);
    cout << endl;

    cout << "Producto actualizado: " << endl;
    producto1.mostrar();

    return 0;
}