using namespace std;
#include <iostream>
#include <string>


class Pedido {
private:
    int codigo;
    string producto;
    int cantidad;
    float precioUnitario;

public:

    Pedido(int c, string p, int C, float P) {
        codigo = c;
        producto = p;
        cantidad = C;
        precioUnitario = P;
    }
    
    void setCantidad(int c) {
        cantidad = c;
    }

    void setPrecioUnitario(float p) {
        precioUnitario = p;
    }


    float calcularTotal() {
        return cantidad * precioUnitario;
    }

    
    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio Unitario: " << precioUnitario << endl;
        cout << "Total: " << calcularTotal() << endl;

    }
};

int main() {

    int cantidad;
    float precio;
    Pedido p1(1, "Cuaderno", 0, 0);
    Pedido p2(2, "Lapiz", 0, 0);
    cout << "Cantidad pedido 1: ";
    cin >> cantidad;
    cout << "Precio unitario pedido 1: ";
    cin >> precio;
    p1.setCantidad(cantidad);
    p1.setPrecioUnitario(precio);

    cout << "Cantidad pedido 2: ";
    cin >> cantidad;
    cout << "Precio unitario pedido 2: ";
    cin >> precio;
    p2.setCantidad(cantidad);
    p2.setPrecioUnitario(precio);

    p1.mostrar();
    p2.mostrar();
    cout<<"modifica la cantidad del primer pedido: ";
    cin>>cantidad;
    p1.setCantidad(cantidad);
    p1.mostrar();
    p2.mostrar();
}