#include <iostream>
#include <string>
using namespace std;

class Propietario {
private:
    string nombre;
    string dni;
    int edad;

public:
    Propietario(string nombre, string dni, int edad) {
        this->nombre = nombre;
        this->dni = dni;
        this->edad = edad;
    }

    int getEdad() {
        return edad;
    }

    string getNombre() {
        return nombre;
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
        return propietario->getEdad() >= 18;
    }

    void mostrar() {
        cout << "Direccion: " << direccion << endl;
        cout << "Precio: " << precio << endl;
        cout << "Propietario: " << propietario->getNombre() << endl;
    }
};

int main() {

    Propietario* propietario = new Propietario("Carlos", "1238", 25);

    Casa casa1=Casa("Av. America", 150000, propietario);

    casa1.mostrar();

    if (casa1.esPropietarioValido()) {
        cout << "La titularidad es VALIDA." << endl;
    }
    else {
        cout << "La titularidad NO es valida." << endl;
    }

    return 0;
}