
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
    Propietario* propietario;  

public:
    Casa() {
    }
    Casa(string direccion, double precio, Propietario* propietario) {
        this->direccion = direccion;
        this->precio = precio;
    }

    bool esPropietarioValido() {
        return propietario->getEdad() >= 18;
    }
    void mostrarEstado() {
        if (esPropietarioValido()) {
            cout << "La titularidad es válida." << endl;
        }
        else {
            cout << "La titularidad NO es válida." << endl;
        }
    }
};

int main() {

    Propietario* p1= new Propietario("Carlos ", "1234", 20);
    Casa* casa1=new Casa("Av. America", 250, p1);

    casa1->mostrarEstado();
}