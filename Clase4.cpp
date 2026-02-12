

#include <iostream>
#include <string>

using namespace std;

//Ejercicio 6
class Cliente {
private:
	string nombre;
	string tipo;
	int antiguedad;

public:
	Cliente(string nombre, string tipo, int antiguedad) {
		this->nombre = nombre;
		this->tipo = tipo;
		this->antiguedad = antiguedad;
	}
};
class Factura {
private:
	int numero;
	int montoBase;
	Cliente cliente;

public:
	Factura(int numero, int nomtoBase, Cliente cliente) {
		this->numero = numero;
		this->montoBase = montoBase;
		this->cliente = cliente;
	}
	void calcularTotal() {

	}
};


int main()
{

}
