// Practica_de_clase.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
class Cuenta
{
private:
	string titular;
	int cantidad;

public:
	Cuenta(string titular, int cantidad)
	{
		this->titular = titular;
		this->cantidad = cantidad;
	}
	Cuenta(string titular)
	{
		this->titular = titular;
		this->cantidad = 0;
	}
	
	void setCantiad(int NuevaCantidad)
	{
		this->cantidad = NuevaCantidad;
	}
	int getCantidad()
	{
		return cantidad;
	}
	void setTitular(int NuevoTitular)
	{
		this->titular = NuevoTitular;
	}
	string getTitular()
	{
		return titular;
	}

	void mostrar()
	{
		cout << "Titular: " << titular << endl;
		cout << "Cantidad: " << cantidad << endl;
	}
	void ingresar(int cantidadIngresada)
	{
		if (cantidadIngresada >= 0)
		{
			cantidad = cantidad + cantidadIngresada;
		}
	}
	void retirar(int cantidadRetirada)
	{
		int restante = cantidad - cantidadRetirada;
		if (restante <= 0)
		{
			this->cantidad = 0;
		}
	}
};

int main()
{
	Cuenta micuenta = Cuenta("Mateo", 2000);
	micuenta.mostrar();
	cout << "Se ingreso: " << endl;
	micuenta.ingresar(400);
	micuenta.mostrar();
}
