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

    
    void ingresar(int cantidad) {
        if (cantidad > 0) {
            this->cantidad += cantidad;
        }
    }

    
    void retirar(int cantidad) {
        if (cantidad > 0) {
            this->cantidad -= cantidad;
        }
        if (this->cantidad < 0) {
            this->cantidad = 0;
        }
    }

    
    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
};

int main() {
    Cuenta cuenta1("Juan", 1000);

    cuenta1.mostrar();

    cuenta1.ingresar(500);
    cout << " Despues de ingresar: ";
    cuenta1.mostrar();

    cuenta1.retirar(2000);
    cout << " Despues de retirar: ";
    cuenta1.mostrar();

    return 0;
}
