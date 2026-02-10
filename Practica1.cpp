// Practica1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

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
    void setCantidad(int nuevaCantidad)
    {
        this->cantidad = nuevaCantidad;
    }
    int getCantidad() { return cantidad; }
    void setTitular(int nuevoTitular) { this->cantidad = nuevoTitular; }
    string getTitular() { return titular; }
    void mostrar() {
        cout "Titular: " << titular << endl;
        cout "Cantidad: " << cantidad << endl;
    }
    void ingresar(int cantidadIngresada) {
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
    
}
