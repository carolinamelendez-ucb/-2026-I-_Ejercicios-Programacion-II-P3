
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
    double precio;
    Propietario *propietario;  

public:
    Casa() {
    }
    Casa(string direccion, double precio, Propietario* propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }

    bool esPropietarioValido() {
        return propietario->getEdad() >= 18;
    }

};

int main() {

    Propietario* p1= new Propietario("Carlos ", "1234", 20);
    Casa* casa1=new Casa("Av. America", 250, p1);
    if (casa1->esPropietarioValido()) {
        cout << "Es valido" << endl;
    }
}