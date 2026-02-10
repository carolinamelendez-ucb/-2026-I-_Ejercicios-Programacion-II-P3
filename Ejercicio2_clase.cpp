// Ejercicio2_clase.cpp 

#include <iostream>
#include <string>
using namespace std;

class Cuenta
{
	string titular;
	int cantidad;
private:

public:
	Cuenta(string titular)
	{
		this->titular = titular;
		this->cantidad = cantidad;
	}
	Cuenta(string titular)
	{
		this->titular = titular;
		this->cantidad = 0;
	}

	void setCantidad(int nuevaCantidad) { cantidad = nuevaCantidad; }
	void setTitular(string nuevoTitular) { titular = nuevoTitular; }


	int getCantidad() { return cantidad; }


	void ingresar(int cantidad)
	{
		if (cantidad >= 0)
		{

		}

	}

	void retirar(int cantidadRetirada)
	{
		int restante = cantidad - cantidadRetirada;
		if (restante < 0)
		{
			this->cantidad = 0;
		}
	}
};

int main()
{
	Cuenta p1 = Cuenta("Saldo");

}

