#include <string>
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

    int getEdad() {
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
        if (propietario->getEdad() >= 18) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Propietario* dueñoPtr = new Propietario("Juan Perez", "8765432", 25);

    Casa* casaPtr = new Casa("Av. America 123", 150000, dueñoPtr);

    if (casaPtr->esPropietarioValido()) {
        cout << "La titularidad es valida (Es mayor de edad)." << endl;
    }
    else {
        cout << "La titularidad no es valida (Es menor de edad)." << endl;
    }

    return 0;
}