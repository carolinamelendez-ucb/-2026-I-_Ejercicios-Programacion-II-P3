#include <iostream>
#include <string>
using namespace std;

class CuentasBancarias {
protected: 
	string nombre;
	int numeroCuenta;
	float balance;
	string historial[100];
	int contador;
public:
	CuentasBancarias(const string& nombre, int numeroCuenta, float balance)
		: nombre(nombre), numeroCuenta(numeroCuenta), balance(balance)
	{
		this->contador = 0;
	}
	void depositar(float cantidad) {
		balance = balance + cantidad;
		historial[contador] = "Deposito de: bs " + to_string(cantidad);
		contador++;
	}
	void retirar(float cantidad) {
		if (cantidad <= balance) {
			balance = balance - cantidad;
			historial[contador] = "Deposito de: bs " + to_string(cantidad);
			contador++;
		}
		else {
			cout << "No hay suficiente dinero, error!" << endl;
		}
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Numero de Cuenta: " << numeroCuenta << endl;
		cout << "Balance Actual: " << balance << endl;
		cout << "Historial de Movimientos: " << endl;

		for (int i = 0; i < contador; i++) {
			cout<<i+1<<": " << historial[i] << endl;
		}
	}
};

class CuentaCorriente: public CuentasBancarias {
public:
	CuentaCorriente(const string& nombre, int numeroCuenta, float balance)
		:CuentasBancarias(nombre, numeroCuenta, balance)
	{
	}

};

class CuentaTransaccional: public CuentasBancarias{
public:
	CuentaTransaccional(const string& nombre, int numeroCuenta, float balance)
		:CuentasBancarias(nombre, numeroCuenta, balance)
	{
	}
	
	void retirar(float cantidad) {
		if (cantidad <= balance) {
			
			cantidad = cantidad * 0.997;
			balance = balance - cantidad;
			historial[contador] = "Deposito de: bs " + to_string(cantidad);
			contador++;
		}
		else {
			cout << "No hay suficiente dinero, error!" << endl;
		}
	}
};

class CuentaJoven: public CuentasBancarias {
public:
	CuentaJoven(const string& nombre, int numeroCuenta, float balance)
		:CuentasBancarias(nombre, numeroCuenta, balance)
	{
	}
	void retirar(float cantidad) {
		if (cantidad <= balance) {
			if (cantidad <= 1000) {
				balance = balance - cantidad;
				historial[contador] = "Retiro de: bs " + to_string(cantidad);
				contador++;
			}
			else {
				cout << "No es  posible retirar mas de 1000 bs, error!" << endl;
			}
		}
		else {
			cout << "No hay suficiente dinero, error!" << endl;
		}
	}

};

int main() {
	CuentaCorriente corriente = CuentaCorriente("Cuenta Corriente", 1, 5000);
	CuentaTransaccional transaccional = CuentaTransaccional("Cuenta  Transaccional", 2, 120);
	CuentaJoven joven = CuentaJoven("Cuenta Joven", 3, 400);

	corriente.depositar(100);
	transaccional.retirar(20);
	joven.retirar(5000);

	corriente.retirar(2000);
	transaccional.retirar(300);
	joven.retirar(300);

	cout << endl;
	corriente.mostrar();
	cout << endl;
	transaccional.mostrar();
	cout << endl;
	joven.mostrar();
}
