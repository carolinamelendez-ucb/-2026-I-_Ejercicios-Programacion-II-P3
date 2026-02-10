#include <iostream>
#include <string>

using namespace std;

class Cuenta {
private:
    string titular;
    double cantidad;

public:
    Cuenta(string titular) {
        this->titular = titular;
        this->cantidad = 0.0;
    }
    Cuenta(string titular, double cantidad) {
        this->titular = titular;
        if (cantidad >= 0)
            this->cantidad = cantidad;
        else
            this->cantidad = 0.0;
    }
    string getTitular() {
        return titular;
    }

    double getCantidad() {
        return cantidad;
    }
    void setTitular(string titular) {
        this->titular = titular;
    }

    void setCantidad(double cantidad) {
        if (cantidad >= 0)
            this->cantidad = cantidad;
    }
    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
    void ingresar(double cantidad) {
        if (cantidad > 0) {
            this->cantidad += cantidad;
        }
    }
    void retirar(double cantidad) {
        if (this->cantidad - cantidad < 0) {
            this->cantidad = 0;
        }
        else {
            this->cantidad -= cantidad;
        }
    }
};

int main() {
    Cuenta c1("Juan Perez");
    c1.mostrar();
    cout << "------------------" << endl;
    c1.ingresar(500.50);
    c1.mostrar();
    cout << "------------------" << endl;
    c1.retirar(200);
    c1.mostrar();
    cout << "------------------" << endl;
    c1.retirar(500);
    c1.mostrar();
    cout << "------------------" << endl;
    Cuenta c2("Maria Lopez", 1000);
    c2.mostrar();
    return 0;
}

