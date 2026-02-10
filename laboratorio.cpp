#include <iostream>
#include <string>

using namespace std;

class Cuenta {
private:
    string titular;
    int cantidad;

public:
    // Constructores
    Cuenta(string titular, int cantidad) {
        this->titular = titular;
        if (cantidad >= 0) {
            this->cantidad = cantidad;
        }
        else {
            this->cantidad = 0;
        }
    }

    Cuenta(string titular) {
        this->titular = titular;
        this->cantidad = 0;
    }

    // Getters y Setters
    void setCantidad(int nuevaCantidad) {
        if (nuevaCantidad >= 0) {
            this->cantidad = nuevaCantidad;
        }
    }

    int getCantidad() {
        return cantidad;
    }

    void setTitular(string nuevoTitular) { 
        this->titular = nuevoTitular;    
    }

    string getTitular() { 
        return titular;
    }

    // Metodos para operaciones bancarias
    void ingresar(int monto) {
        if (monto > 0) {
            cantidad += monto;
            cout << "Se han ingresado " << monto << " euros." << endl;
        }
        else {
            cout << "Error: El monto a ingresar debe ser positivo." << endl;
        }
    }

    void retirar(int monto) {
        if (monto > 0) {
            if (monto <= cantidad) {
                cantidad -= monto;
                cout << "Se han retirado " << monto << " euros." << endl;
            }
            else {
                cout << "Error: Fondos insuficientes. Solo tienes " << cantidad << " euros." << endl;
            }
        }
        else {
            cout << "Error: El monto a retirar debe ser positivo." << endl;
        }
    }

    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << " euros" << endl;
    }
};

int main() {
    cout << "=== EJEMPLO DE USO DE LA CLASE CUENTA ===" << endl << endl;

    // Crear cuentas usando diferentes constructores
    cout << "1. Creando cuentas:" << endl;
    Cuenta cuenta1("Juan Pérez", 1000);
    Cuenta cuenta2("María López");

    cout << "Cuenta 1 creada:" << endl;
    cuenta1.mostrar();
    cout << endl;

    cout << "Cuenta 2 creada:" << endl;
    cuenta2.mostrar();
    cout << endl;

    // Usar metodos setter
    cout << "2. Modificando datos:" << endl;
    cuenta1.setTitular("Juan Pérez González");
    cuenta2.setCantidad(500);

    cout << "Después de modificar:" << endl;
    cout << "Cuenta 1: " << endl;
    cuenta1.mostrar();
    cout << endl;

    cout << "Cuenta 2: " << endl;
    cuenta2.mostrar();
    cout << endl;

    // Usar metodos getter
    cout << "3. Obteniendo datos con getters:" << endl;
    cout << "Titular de cuenta1: " << cuenta1.getTitular() << endl;
    cout << "Cantidad de cuenta1: " << cuenta1.getCantidad() << " euros" << endl;
    cout << endl;

    cout << "4. Operaciones de ingreso:" << endl;
    cuenta1.ingresar(500);
    cout << "Saldo actual cuenta1: " << cuenta1.getCantidad() << " euros" << endl;

    cuenta1.ingresar(-100);
    cout << endl;

    cout << "5. Operaciones de retiro:" << endl;
    cuenta1.retirar(300);
    cout << "Saldo actual cuenta1: " << cuenta1.getCantidad() << " euros" << endl;

    cuenta1.retirar(2000);
    cout << "Saldo actual cuenta1: " << cuenta1.getCantidad() << " euros" << endl;

    cuenta1.retirar(-50);
    cout << endl;

    cout << "6. Secuencia completa en cuenta2:" << endl;
    cuenta2.mostrar();
    cuenta2.ingresar(1000);
    cuenta2.retirar(300);
    cuenta2.ingresar(200);
    cuenta2.retirar(1500);
    cuenta2.mostrar();

    cout << endl << "7. Creando cuenta con cantidad inicial negativa:" << endl;
    Cuenta cuenta3("Carlos Ruiz", -500);
    cuenta3.mostrar();

    return 0;
}