#include <iostream>
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


    string getNombre() {
        return this->nombre;
    }

    string getDni() {
        return this->dni;
    }

    int getEdad() {
        return this->edad;
    }
};

class Casa {
private:
    string direccion;
    double precio;
    Propietario* propietario;

public:

    Casa(string direccion, double precio, Propietario* propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }

    bool esPropietarioValido() {
        return this->propietario->getEdad() >= 18;
    }


    string getDireccion() {
        return this->direccion;
    }

    double getPrecio() {
        return this->precio;
    }

    Propietario* getPropietario() {
        return this->propietario;
    }
};

int main() {

    Propietario* prop1 = new Propietario("Juan Perez", "1234567", 25);

    Casa* casa1 = new Casa("Calle Principal 123", 250000.50, prop1);

    cout << "=== INFORMACIÓN DE LA CASA ===" << endl;
    cout << "Direccion: " << casa1->getDireccion() << endl;
    cout << "Precio: $" << casa1->getPrecio() << endl;
    cout << "Propietario: " << casa1->getPropietario()->getNombre() << endl;
    cout << "DNI: " << casa1->getPropietario()->getDni() << endl;
    cout << "Edad: " << casa1->getPropietario()->getEdad() << " anios" << endl;

    if (casa1->esPropietarioValido()) {
        cout << "El propietario es valido (mayor de edad)" << endl;
    }
    else {
        cout << "El propietario NO es valido (menor de edad)" << endl;
    }

    delete prop1;
    delete casa1;

    return 0;
}