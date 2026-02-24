// ConsoleApplication2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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
		Propietario(string nombre, int dni, int edad) {
			this->nombre = nombre;
			this->dni = dni;
			this->edad = edad;
		}
		int getedad()
		{
			return edad;
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
			return propietario->getedad() >= 18;
		}
	};

	int main(){
		Propietario* sara = new Propietario("sara", 123, 45);
		Casa* casa1 = new Casa("Junin", 3000, sara);


		cout << "El propietario es valido" << (casa1->esPropietarioValido() ? "si" : "no") << endl;
		cout << "Hola mundo" << endl;
	}


