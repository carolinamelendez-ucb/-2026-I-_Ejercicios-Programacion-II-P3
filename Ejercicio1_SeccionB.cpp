#include <iostream>
#include <string>
using namespace std;
class Cuenta {
private:
	string titular;
	int cantidad;
public:
	Cuenta(string titular, int cantidad) {
		this->cantidad = cantidad;
		this->titular = titular;
	}
	Cuenta(string titular) {
		this->cantidad = 0;
		this->titular = titular;
	}
	void setCantidad(int nuevoCantidad) {
		this->cantidad = nuevoCantidad;
	}
	int getCantidad() {
		return cantidad;
	}
	void setTItular(int nuevoTitular) {
		this->titular = nuevoTitular;
	}
	string getTitular() {
		return titular;
	}
	void mostrar() {
		cout << "Titular: " << titular << endl;
		cout << "Cantidad: " << cantidad << endl;
	 }
	void ingresar(int cantidadIngresada) {
		if (cantidadIngresada >= 0) {
			this->cantidad = this->cantidad + cantidadIngresada;
		}
	}
	void retirar(int cantidadRetirada) {
		int restante = cantidad - cantidadRetirada;
		if (restante < 0) {
			this->cantidad = 0;
		}
	}
};
int main()
{
	Cuenta cuenta1 = Cuenta("javier", 3000);
	Cuenta cuenta2 = Cuenta("alan");
	cout << "Lista de cuentas: " << endl;
	cuenta1.mostrar();
	cuenta2.mostrar();
	cout << "Datos de la cuenta a retirar" << endl;
	cuenta1.mostrar();
	cuenta1.retirar(2000);
	cout << "Cantidad acutal: ";
	cuenta1.getCantidad();
	cout << "Datos de la cuenta a depositar" << endl;
	cuenta2.mostrar();
	cuenta2.ingresar(5000);
	cout << "Cantidad acutal: ";
	cuenta2.getCantidad();

}