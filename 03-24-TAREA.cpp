#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
protected:
    string nombre;
    int NdeCuenta;
    int balance;

public:
    CuentaBancaria(string nombre, int NdeCuenta, int balance) {
        this->nombre = nombre;
        this->NdeCuenta = NdeCuenta;
        this->balance = balance;
    }

    void depositar(int monto) {
        balance = balance + monto;
        cout << "Deposito realizado, nuevo balance: " << balance << endl;
    }

    virtual void retirar(int monto) {
        if (monto <= balance) {
            balance = balance - monto;
            cout << "Retiro realizado, nuevo balance: " << balance << endl;
        }
        else {
            cout << "Fondos insuficientes" << endl;
        }
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Numero de cuenta: " << NdeCuenta << endl;
        cout << "Balance final: " << balance << endl;
    }
};

class CuentaCorriente : public CuentaBancaria {
public:
    CuentaCorriente(string nombre, int NdeCuenta, int balance)
        : CuentaBancaria(nombre, NdeCuenta, balance) {
    }
};

class CuentaTransaccional : public CuentaBancaria {
public:
    CuentaTransaccional(string nombre, int NdeCuenta, int balance)
        : CuentaBancaria(nombre, NdeCuenta, balance) {
    }

    void retirar(int monto) override {
        float comision = monto * 0.003; 
        int total = monto + comision;

        if (total <= balance) {
            balance = balance - total;
            cout << "Retiro con comision, nuevo balance: " << balance << endl;
        }
        else {
            cout << "Fondos insuficientes" << endl;
        }
    }
};

class CuentaJoven : public CuentaBancaria {
public:
    CuentaJoven(string nombre, int NdeCuenta, int balance)
        : CuentaBancaria(nombre, NdeCuenta, balance) {
    }

    void retirar(int monto) override {
        if (monto > 1000) {
            cout << "No puede retirar mas de 1000" << endl;
        }
        else if (monto <= balance) {
            balance = balance - monto;
            cout << "Retiro realizado, nuevo balance: " << balance << endl;
        }
        else {
            cout << "Fondos insuficientes" << endl;
        }
    }
};

int main() {
    CuentaCorriente c1("Juan", 1, 2000);
    CuentaTransaccional c2("Ana", 2, 2000);
    CuentaJoven c3("Luis", 3, 2000);
    cout << "--- Cuenta Corriente ---" << endl;
    c1.depositar(500);
    c1.retirar(200);
    c1.mostrar();
    cout << endl << "--- Cuenta Transaccional ---" << endl;
    c2.depositar(300);
    c2.retirar(200);
    c2.mostrar();
    cout << endl << "--- Cuenta Joven ---" << endl;
    c3.depositar(400);
    c3.retirar(1500);
    c3.retirar(500);
    c3.mostrar();
}
