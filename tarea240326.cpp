#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
protected:
    string nombre;
    string numeroCuenta;
    double balance;
    string historial[100];
    int contadorHistorial;

public:
    CuentaBancaria(string nom, string num, double bal) {
        nombre = nom;
        numeroCuenta = num;
        balance = bal;
        contadorHistorial = 0;
    }

    void depositar(double monto) {
        if (monto > 0) {
            balance += monto;
            historial[contadorHistorial] = "Deposito: +" + to_string(monto) + " | Nuevo balance: " + to_string(balance);
            contadorHistorial++;
        }
    }

    void retirar(double monto) {
        if (monto > 0 && monto <= balance) {
            balance -= monto;
            historial[contadorHistorial] = "Retiro: -" + to_string(monto) + " | Nuevo balance: " + to_string(balance);
            contadorHistorial++;
        }
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Numero de cuenta: " << numeroCuenta << endl;
        cout << "Balance actual: " << balance << endl;
        cout << "Historial de transacciones:" << endl;
        for (int i = 0; i < contadorHistorial; i++) {
            cout << "  " << historial[i] << endl;
        }
        cout << "------------------------" << endl;
    }
};

class CuentaCorriente : public CuentaBancaria {
public:
    CuentaCorriente(string nom, string num, double bal) : CuentaBancaria(nom, num, bal) {
    }
};

class CuentaTransaccional : public CuentaBancaria {
public:
    CuentaTransaccional(string nom, string num, double bal) : CuentaBancaria(nom, num, bal) {
    }

    void retirar(double monto) {
        if (monto > 0 && monto <= balance) {
            double comision = monto * 0.003;
            double totalRetiro = monto + comision;
            if (totalRetiro <= balance) {
                balance -= totalRetiro;
                historial[contadorHistorial] = "Retiro: -" + to_string(monto) + " (comision 0.3%: " + to_string(comision) + ") | Nuevo balance: " + to_string(balance);
                contadorHistorial++;
            }
        }
    }
};

class CuentaJoven : public CuentaBancaria {
public:
    CuentaJoven(string nom, string num, double bal) : CuentaBancaria(nom, num, bal) {
    }

    void retirar(double monto) {
        if (monto > 0 && monto <= 1000 && monto <= balance) {
            balance -= monto;
            historial[contadorHistorial] = "Retiro: -" + to_string(monto) + " | Nuevo balance: " + to_string(balance);
            contadorHistorial++;
        }
    }
};

int main() {
    CuentaCorriente cc("Mario Arandia", "1001", 5000);
    CuentaTransaccional ct("Sara Medina", "2002", 3000);
    CuentaJoven cj("Carlos Ruiz", "3003", 1500);

    cc.depositar(1000);
    cc.retirar(500);
    cc.depositar(200);
    cc.retirar(300);
    cc.retirar(1000);

    ct.depositar(800);
    ct.retirar(400);
    ct.depositar(150);
    ct.retirar(200);
    ct.retirar(100);

    cj.depositar(500);
    cj.retirar(300);
    cj.depositar(200);
    cj.retirar(800);
    cj.retirar(400);

    cc.mostrar();
    ct.mostrar();
    cj.mostrar();

    return 0;
}