#include <iostream>
#include <string>
using namespace std;
class Cuenta
{
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

    void setTitular(int nuevoTitular)
    {
        this->titular = nuevoTitular;
    }
    string getTitular()
    {
        return titular;
    }
    void setCantidad(int nuevaCantidad)
    {
        this->cantidad = nuevaCantidad;
    }
    int getCantidad()
    {
        return cantidad;
    }

    void mostrar()
    {
        cout << "TITULAR: " << titular << endl;
        cout << "CANTIDAD: " << cantidad << endl;
    }

    void ingresar(int cantidadIngresada)
    {
        if (cantidadIngresada >= 0)
        {
            this->cantidad = this->cantidad + cantidadIngresada;
        }
    }

    void retirar(int cantidadRetirada)
    {
        int restante = cantidad - cantidadRetirada;
        if (restante < 0)
        {
            this->cantidad = 0;
        }
    }
};

int main()
{
    Cuenta cuenta1 = Cuenta("Pablo", 1200);
    cuenta1.mostrar();
    cout << "CANTIDAD: " << cuenta1.getCantidad() << endl;
    cuenta1.getCantidad();
    cuenta1.ingresar(1000);
    cuenta1.mostrar();
    cuenta1.retirar(200);
    cuenta1.mostrar();
}
