using namespace std;
#include <iostream>
#include <string>
using namespace std;
class CuentaBanco {
protected:
    string nombre;
    int numeroCuenta;
    float balance;
    string historial[100];
    int contador;
public:
    CuentaBanco(const string& nombre, int numeroCuenta, float balance)
        : nombre(nombre), numeroCuenta(numeroCuenta), balance(balance)
    {
        contador = 0;
    }
    void depositar(float monto) {
        balance = balance + monto;
        historial[contador] = monto;
        contador++;
    }
    void retirar(float monto) {
        if (monto <= balance) {
            balance = balance - monto;
            historial[contador] = monto;
            contador++;
        }
        else {
            cout << "Fondo insuficiente" << endl;
        }
    }
    void mostrarCuenta() {
        cout << "Nombre: " << nombre << endl;
        cout << "Cuenta: " << numeroCuenta << endl;
        cout << "Balance: " << balance << endl;
        for (int i = 0; i < contador; i++) {
            cout << historial[i] << endl;
        }
    }
};

class CuentaCorriente : public CuentaBanco {
public:
    CuentaCorriente(string nombre, int numeroCuenta, float balance)
        : Banco(nombre, numeroCuenta, balance) {
    }
};

class CuentaTransacional : public CuentaBanco {
public:
    CuentaTransacional(string nombre, int numeroCuenta, float balance)
        : Banco(nombre, numeroCuenta, balance) {
    }
    void retirar(float monto) {
        float comision = monto * 0.003;
        float total = monto - comision;
        if (total <= balance) {
            balance = balance - monto;
            contador++;
        }
        else {
            cout << "Fondos insuficientes" << endl;
        }
    }
};

class CuentaJoven : public CuentaBanco {
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
	

}
