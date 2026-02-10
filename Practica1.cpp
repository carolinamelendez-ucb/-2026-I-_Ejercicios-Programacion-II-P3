#include <iostream>
#include <string>
using namespace std;

class Cuenta {
private:
    string titular;
    int  cantidad;
public:
    Cuenta(string titular, int cantidad) {
        this->titular = titular;
        this->cantidad = cantidad;
    }
    Cuenta(string titular) {
        this->titular = titular;
        this->cantidad = 0;
    }
    void setCantidad(int newCantidaad) { this->cantidad = newCantidad; }
    int getcantidad() { return cantidad; }
    void setTitular(int newTitular) { this->titular = newTitular; }
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
        int restante = cantidad - cantidadRetirada;
        if (restante < 0) {
            ;
        }
    }
    
};

int main()
{
    
}
