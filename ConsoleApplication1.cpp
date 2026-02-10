#include <iostream>
#include <string>
using namespace std;

class cuenta 
{
private: 
	string titular;
	int cantidad;
public:
	cuenta(string titular, int cantidad)
	{
		this->titular = titular;
		this->cantidad = cantidad;
	}

	cuenta(string titular)
	{
		this->titular = titular;
		this->cantidad = 0;
	}

	void setcantidad(int nuevac)
	{
		this->cantidad = nuevac;
	}

	int getcantidad()
	{
		return cantidad;
	}

	void settitular(int nuevat)
	{
		this->titular = nuevat;
	}

	string gettitular()
	{
		return titular;
	}

	void mostrar()
	{
		cout << "titular: " << titular << endl;
		cout << "cantidad: " << cantidad << endl;
	}

	void ingresar(int cantidadi)
	{
		if (cantidadi >= 0)
		{
			cantidad = cantidad + cantidadi;
		}
	}

	void retirar(int cantidadr)
	{
		int restante = cantidad - cantidadr;
		if (restante < 0)
		{
			this->cantidad = 0;
		}
	}
};

int main()
{
	cuenta c1 = cuenta("mano", 200);
	cout << "titular" << c1.gettitular << endl;
	cout << "cantidad" << c1.getcantidad << endl;
}