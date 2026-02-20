#include <iostream>
#include <string>

using namespace std;

class Pedido
{
private:
    string codigo;
    string producto;
    int cantidad;
    int precioUnitario;
public:
    Pedido(string codigo, string producto, int cantidad, int precioUnitario) {
        this->codigo = codigo;
        this->producto = producto;
        this->cantidad = cantidad;
        this->precioUnitario = precioUnitario;
    }

    void setCantidad(int nuevaCantidad) {
        this->cantidad = nuevaCantidad;
    }

    void setPrecioUnitario(int nuevoPrecio) {
        this->precioUnitario = nuevoPrecio;
    }

    double calcularTotal() {
        return cantidad * precioUnitario;
    }

    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio Unitario: " << precioUnitario << endl;
        cout << "Total del pedido: " << calcularTotal() << endl;
        cout << "================================" << endl;
    }
};

int main()
{
    Pedido pedido1("P001", "Laptop", 1, 0.0);
    Pedido pedido2("P002", "Mouse", 2, 0.0);

    int cantidad;
    int precio;

    cout << " INGRESAR DATOS DE PEDIDOS " << endl;

    cout << "Pedido: Laptop (Codigo: P001)" << endl;
    cout << "Ingrese cantidad: ";
    cin >> cantidad;
    cout << "Ingrese precio unitario: ";
    cin >> precio;

    pedido1.setCantidad(cantidad);
    pedido1.setPrecioUnitario(precio);
    cout << endl;

    cout << "Pedido: Mouse (Codigo: P002)" << endl;
    cout << "Ingrese cantidad: ";
    cin >> cantidad;
    cout << "Ingrese precio unitario: ";
    cin >> precio;

    pedido2.setCantidad(cantidad);
    pedido2.setPrecioUnitario(precio);
    cout << endl;

    cout << " DETALLE DE PEDIDOS " << endl;
    pedido1.mostrar();
    pedido2.mostrar();

    cout << "Modificar cantidad del pedido P001 (Laptop):" << endl;
    cout << "Ingrese nueva cantidad: ";
    cin >> cantidad;
    pedido1.setCantidad(cantidad);
    cout << "Cantidad actualizada!" << endl << endl;

    cout << " PEDIDOS ACTUALIZADOS " << endl;
    cout << "Verificando que el total se actualizo..." << endl;
    pedido1.mostrar();
    pedido2.mostrar();

    return 0;
}