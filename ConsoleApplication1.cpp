#include <iostream>
#include <string>
using namespace std;
class Banco {
protected:
    string nombre;
    int numeroCuenta;
    float balance;
    string historial[25];
    int contador;
public:
    Banco(const string& nombre, int numeroCuenta, float balance)
        : nombre(nombre), numeroCuenta(numeroCuenta), balance(balance)
    {
        contador = 0;
    }
    void depositar(float monto) {
        balance = balance + monto;
        historial[contador] = "Deposito hecho";
        contador++;
    }
    void retirar(float monto) {
        if (monto <= balance) {
            balance = balance - monto;
            historial[contador] = "Retiro hecho";
            contador;
        }
        else {
            cout << "Fondo insuficiente" << endl;
        }
    }
    void mostrarCuenta() {
        cout << "Nombre: " << nombre << endl;
        cout << "Cuenta: " << numeroCuenta << endl;
        cout << "Balance: " << balance << endl;
        cout << "Historial: ";
        for (int i = 0; i < contador; i++) {
            cout << historial[i] << endl;
        }
    }
};

class CuentaCorriente : public Banco {
public:
    CuentaCorriente(string nombre, int numeroCuenta, float balance)
        : Banco(nombre, numeroCuenta, balance) {
    }
};

class CuentaTransacional : public Banco {
public:
    CuentaTransacional(string nombre, int numeroCuenta, float balance)
        : Banco(nombre, numeroCuenta, balance) {
    }
    void retirar(float monto) {
        float comision = monto * 0.003;
        float total = monto + comision;
        if (total <= balance) {
            balance = balance - total;
            historial[contador] = "Retiro con comision aplicado";
            contador++;
        }
        else {
            cout << "Fondos insuficientes" << endl;
        }
    }
};

class CuentaJoven : public Banco {
public:
    CuentaJoven(string nombre, int numeroCuenta, float balance)
        : Banco(nombre, numeroCuenta, balance) {
    }
    void retirar(float monto) {
        if (monto > 1000) {
            cout << "Maximo retiro permitido (Bs. 1000)" << endl;
            return;
        }
        if (monto <= balance) {
            balance = balance - monto;
            historial[contador] = "Retiro permitido";
            contador++;
        }
        else {
            cout << "Fondos insufientes" << endl;
        }
    }
};
int main()
{
    CuentaCorriente clienteCC1("Sofia", 3427, 3000);
    CuentaTransacional clienteCT2("Julian", 9360, 2050);
    CuentaJoven clienteCJ3("Rebeca", 7841, 1930);

    clienteCC1.depositar(420);
    clienteCC1.retirar(600);
    clienteCC1.depositar(250);

    clienteCT2.depositar(320);
    clienteCT2.retirar(800);

    clienteCJ3.depositar(150);
    clienteCJ3.retirar(550);
    clienteCJ3.depositar(200);

    clienteCC1.mostrarCuenta();
    clienteCT2.mostrarCuenta();
    clienteCJ3.mostrarCuenta();
    return 0;
}
