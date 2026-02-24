#include <iostream>
using namespace std;

class Propietario {
private:
	string nombre;
	int dni;
	int edad;
public:
	Propietario() {
		nombre = "";
		dni = 0;
		edad = 0;
	}
	Propietario(string nombre, int dni, int edad) {
		this->nombre = nombre;
		this->dni = dni;
		this->edad = edad;
	}
	int getEdad() { return edad; }
};

class Casa {
private:
	string direccion;
	int precio;
	Propietario* propietario;
public:
	Casa(string direccion, int precio, Propietario* propietario) {
		this->direccion = direccion;
		this->precio = precio;
		this->propietario = propietario;
	}
	bool esPropietarioValido() {
		return propietario->getEdad() >= 18;
	}
};

int main()
{
	Propietario* prop1 = new Propietario("Reyes", 123, 21);
	Casa* casa1 = new Casa("Moliere 423", 200, prop1);

	cout << "Es propietario valido?: " << casa1->esPropietarioValido();
}
