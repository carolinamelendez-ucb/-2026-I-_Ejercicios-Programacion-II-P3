#include <iostream>
#include <string>

using namespace std;

class Cuenta {
private:
    string titular;
    int cantidad;
public:
    Cuenta(string titular, int cantidad)
    {
        this->titular = titular;
        this->cantidad = cantidad;
    }
    Cuenta(string titular)
    {
        this->titular = titular;
        this->cantidad = 0;
    }

    void setCantidad(int nuevaCantidad)
    {
        this->cantidad = nuevaCantidad;
    }
    int getCantidad() { return cantidad; }

    void setTitular(string nuevoTitular)
    {
        titular = nuevoTitular;
    }
    string getTitular() { return titular; }

    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << endl;
    }

    void ingresar(int cantidadIngresada)
    {
        if (cantidadIngresada >= 0) {
            cantidad = cantidad + cantidadIngresada;
        }
    }

    void retirar(int cantidadRetirada) {
        cantidad -= cantidadRetirada;
        if (cantidad < 0)
        {
            this->cantidad = 0;
        }
    }

};

int main()
{
    Cuenta miCuenta = Cuenta("Alejandro", 40);
    miCuenta.mostrar();
    cout << "El titular es: " << miCuenta.getTitular() << endl;
    miCuenta.setCantidad(50);
    miCuenta.setTitular("Juan");
    cout << "Despues de usar el set" << endl;
    miCuenta.mostrar();
    miCuenta.ingresar(25);
    cout << endl << "La cantidad es: " << miCuenta.getCantidad() << endl;
    miCuenta.retirar(50);
    cout << endl << "La cantidad es: " << miCuenta.getCantidad() << endl;

}