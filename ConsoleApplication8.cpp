#include <iostream>
#include <string>

using namespace std;

class Cuenta {
private:
    string titular;
    int cantidad;

public:
    Cuenta(string titular, int cantidad) {
        this->titular = titular;
        this->cantidad = cantidad;
    }

    Cuenta(string titular) {
        this->titular = titular;
        this->cantidad = 0;
    }

    int getCantidad() {
        return cantidad;
    }

    void setCantidad(int nuevaCantidad) {
        cantidad = nuevaCantidad;
    }

    string getTitular() {
        return titular;
    }

    void setTitular(string nuevoTitular) {
        titular = nuevoTitular;
    }

    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << endl;
    }

    void ingresar(int cantidadIngresada) {
        if (cantidadIngresada > 0) {
            cantidad += cantidadIngresada;
        }
    }

    void retirar(int cantidadRetirada) {
        if (cantidadRetirada > 0) {
            if (cantidad - cantidadRetirada < 0)
                cantidad = 0;
            else
                cantidad -= cantidadRetirada;
        }
    }
};

int main() {
    Cuenta cuenta1("Jorge", 500);
    cuenta1.mostrar();
    cout << "ingresando dinero" << endl;
    cuenta1.ingresar(200);
    cuenta1.mostrar();
    cout << "retirando dinero" << endl;
    cuenta1.retirar(800);
    cuenta1.mostrar();

    Cuenta cuenta2("Maria");
    cuenta2.mostrar();
    cout << "Ingresando dinero"<<endl;
    cuenta2.ingresar(1000);
    cuenta2.mostrar();

    return 0;
}