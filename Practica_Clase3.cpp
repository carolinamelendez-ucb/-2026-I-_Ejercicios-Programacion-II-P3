

#include <iostream>
#include <string>

using namespace std;

class Cuenta {
private:
    string titular;
    double cantidad;

public:
    // Constructor 1 (solo titular)
    Cuenta(string t) {
        titular = t;
        cantidad = 0;
    }

    // Constructor 2 (titular y cantidad)
    Cuenta(string t, double c) {
        titular = t;
        if (c < 0)
            cantidad = 0;
        else
            cantidad = c;
    }

    // GETTERS
    string getTitular() {
        return titular;
    }

    double getCantidad() {
        return cantidad;
    }

    // SETTERS
    void setTitular(string t) {
        titular = t;
    }

    void setCantidad(double c) {
        if (c >= 0)
            cantidad = c;
    }

    // Mostrar datos
    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << endl;
    }

    // Metodo ingresar
    void ingresar(double c) {
        if (c > 0)
            cantidad += c;
    }

    // Metodo retirar
    void retirar(double c) {
        if (c > cantidad)
            cantidad = 0;
        else
            cantidad -= c;
    }
};

int main() {
    Cuenta c1("Carlos", 500);

    c1.mostrar();

    cout << " Ingresando 200... ";
    c1.ingresar(200);
    c1.mostrar();

    cout << " Retirando 800... ";
    c1.retirar(800);
    c1.mostrar();

    return 0;
}
