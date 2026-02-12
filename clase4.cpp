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

    Propietario(string nom, int dni, int edad) {
        this->nombre = nom;
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
    Propietario propietario;
public:
    Casa() {
        direccion = "";
        precio = 0;
    }

    Casa(string direccion, int precio, Propietario propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }

    bool esPropietario() {
        return propietario.getEdad() >= 18;
    }

    void mostrarTitulat() {
        if (esPropietario()) {
            cout << "La titularidad es valida" << endl;
        }
        else {
            cout << "La titularidad es NO valida" << endl;
        }
    }
};

void ejer4() {
    Propietario propietario1("Luis", 123, 25);
    Casa casa1("Av Libertador", 250, propietario1);
    casa1.mostrarTitulat();
}

class Cliente {
private:
    string nombre;
    string tipo;
    int antiguedad;
public:
    Cliente() {
        nombre = "";
        tipo = "";
        antiguedad = 0;
    }

    Cliente(string nombre, string tipo, int antiguedad) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguedad = antiguedad;
    }

    string getTipo() {
        return tipo;
    }

    int getAntiguedad() {
        return antiguedad;
    }
};

class Factura {
private:
    int numero;
    double montoBase;
    Cliente cliente;
public:
    Factura() {
        numero = 0;
        montoBase = 0;
    }

    Factura(int numero, double montoBase, Cliente cliente) {
        this->numero = numero;
        this->montoBase = montoBase;
        this->cliente = cliente;
    }

    double calcularTotal() {
        if (cliente.getTipo() == "frecuente" && cliente.getAntiguedad() > 2) {
            return montoBase * 0.90;
        }
        return montoBase;
    }

    void mostrarTotal() {
        cout << "Total a pagar: " << calcularTotal() << endl;
    }
};

void ejer5() {
    Cliente cliente1("Pepe", "frecuente", 4);
    Factura fact1(101, 1000, cliente1);
    fact1.mostrarTotal();
}

int main() {
    ejer4();
    ejer5();
    return 0;
}

