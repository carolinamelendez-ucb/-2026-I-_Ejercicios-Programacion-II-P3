// ejercicio4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
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
	int getedad() { return edad; }
};
class Casa {
private:
	string direccion;
	int precio;
	Propietario *propietario;
public:
	Casa(string direccion, int precio, Propietario* propietario) {
		this->direccion = direccion;
		this->precio = precio;
		this->propietario = propietario;
	}
	bool esPropietarioValido() {
		return propietario->getedad() >= 18;
	}
};

int main()
{
	Propietario* prop = new Propietario("Sebas", 8801939, 15);
	Casa* casa = new Casa("Carlos", 12000, prop);
	if(casa ->esPropietarioValido()){
		cout << "Es Valido" << endl;
	}
	else{
		cout << "No es valido" << endl;
	}
}
