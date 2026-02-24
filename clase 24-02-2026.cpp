#include <iostream>
#include <string>
using namespace std;

class Propietario {
private:
	string nombre;
	int dni;
	int edad;
public:
	Propietario() {}
	Propietario(string nombre, int dni, int edad) {
		this->nombre = nombre;
		this->dni = dni;
		this->edad = edad;
	}
	int getEdad() {
		return edad;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Dni: " << dni << endl;
		cout << "Edad: " << edad << endl;
	}
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
		return propietario->getEdad() > 18;
	}
	void mostrar() {
		cout << "Direccion: " << direccion << endl;
		cout << "Precio: " << precio << endl;
		propietario->mostrar();
		cout << "Propietario Valido: " << esPropietarioValido() << endl;
	}
};


int main()
{
	cout << boolalpha;
	Propietario* p1 = new Propietario("Sara", 123, 34);
	Propietario* p2 = new Propietario("Carlos", 456, 12);
	Casa casas[2] = {
		Casa("Sucre", 2321, p1),
		Casa("Colombia", 2342,p2)
	};
	casas[0].mostrar();
	casas[1].mostrar();
	cout << endl;
}