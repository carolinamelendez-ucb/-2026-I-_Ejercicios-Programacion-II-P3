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

    string getNombre() {
        return nombre;
    }

    int getDni() {
        return dni;
    }

    int getEdad() {
        return edad;
    }

    // ✅ Método para validar mayoría de edad
    bool esMayorDeEdad() {
        return edad >= 18;
    }
};

class Casa {
private:
    string Direccion;
    int precio;
    Propietario* propietario;

public:
    Casa(string Direccion, int precio, Propietario* propietario) {
        this->Direccion = Direccion;
        this->precio = precio;
        this->propietario = propietario;
    }

    void mostrarInformacion() {
        cout << "Direccion: " << Direccion << endl;
        cout << "Precio: " << precio << endl;
        cout << "Propietario: " << propietario->getNombre() << endl;

        // ✅ Validación de mayoría de edad
        if (propietario->esMayorDeEdad()) {
            cout << "El propietario es mayor de edad." << endl;
        } else {
            cout << "El propietario NO es mayor de edad." << endl;
        }
    }
};

int main() {
    Propietario p1("Juan Perez", 12345678, 45);
    Casa c1("Av. Siempre Viva 742", 150000, &p1);

    c1.mostrarInformacion();

    return 0;
}
