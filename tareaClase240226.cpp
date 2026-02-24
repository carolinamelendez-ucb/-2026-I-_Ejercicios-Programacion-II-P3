// Ejercicio 4: Relacion casa - propietario
#include <iostream>
#include <string>
using namespace std;

class Propietario {
public:
    string nombre;
    string dni;
    int edad;

    Propietario(string nombre, string dni, int edad) {
        nombre = nombre;
        dni = dni;
        edad = edad;
    }
};

class Casa {
public:
    string direccion;
    float precio;
    Propietario* propietario;

    Casa(string direccion, float precio, Propietario* propietario, string copropietario) {
        direccion = direccion;
        precio = precio;
        propietario = propietario;
    }

    bool esPropietarioValido() {
        return propietario->edad >= 18;
    }
};

int main() {
    // Crear un propietario
    Propietario* prop1 = new Propietario("Juan Perez", "12345678A", 25);

    // Crear una casa con el propietario (usando puntero)
    Casa* casa1 = new Casa("Calle Principal 123", 250000.50, prop1);

    // Mostrar informacion
    cout << "=== INFORMACION DE LA CASA ===" << endl;
    cout << "Direccion: " << casa1->direccion << endl;
    cout << "Precio: $" << casa1->precio << endl;
    cout << "Propietario: " << casa1->propietario->nombre << endl;
    cout << "DNI: " << casa1->propietario->dni << endl;
    cout << "Edad: " << casa1->propietario->edad << " anios" << endl;

    // Verificar si el propietario es valido
    if (casa1->esPropietarioValido()) {
        cout << "La titularidad es VALIDA (propietario mayor de edad)" << endl;
    }
    else {
        cout << "La titularidad NO es valida (propietario menor de edad)" << endl;
    }

    // Liberar memoria
    delete prop1;
    delete casa1;

    return 0;
}