#include <iostream>
#include <string>

using namespace std;

class Propietario {
private:
    string nombre;
    string dni;
    int edad;

public:
    Propietario() {
        nombre = "";
        dni = "";
        edad = 0;
    }

    Propietario(string nombre, string dni, int edad) {
        this->nombre = nombre;
        this->dni = dni;
        this->edad = edad;
    }

    string getNombre() { return nombre; }
    string getDni() { return dni; }
    int getEdad() { return edad; }
};

class Casa {
private:
    string direccion;
    float precio;
    Propietario *propietario;

public:
    Casa() {
        direccion = "";
        precio = 0;
        propietario =  new Propietario();
    }

    Casa(string direccion, float precio, Propietario *propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }

    string getDireccion() { return direccion; }
    float getPrecio() { return precio; }

    bool esPropietarioValido() {
        return propietario->getEdad() >= 18;
    }
};

int main()
{
    Propietario* prop1 = new Propietario("Alejandro", "13384038", 18);

    Casa* cas1 = new Casa("Av. Beijing", 10000, prop1);

    cout << cas1->esPropietarioValido() << endl;
}