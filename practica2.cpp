// practica2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
using namespace std;

class Cuenta {
private:
    string titular;
    int cantidad;

public:
    // Constructor con titular y cantidad
    Cuenta(string titular, int cantidad) {
        this->titular = titular;
        this->cantidad = cantidad;
    }

    // Constructor solo con titular
    Cuenta(string titular) {
        this->titular = titular;
        this->cantidad = 0;
    }

    void setCantidad(int nuevaCantidad) {
        if (nuevaCantidad >= 0) {
            this->cantidad = nuevaCantidad;
        }
    }

    void setTitular(string nuevoTitular) {
        this->titular = nuevoTitular;
    }

    string getTitular() {
        return titular;
    }

    int getCantidad() {
        return cantidad;
    }

    void ingresar(int cantidadIngresada) {
        if (cantidadIngresada >= 0) {
            this->cantidad += cantidadIngresada;
        }
    }

    void retirar(int cantidadRetirada) {
        if (cantidad - cantidadRetirada < 0) {
            this->cantidad = 0;
        }
        else {
            this->cantidad -= cantidadRetirada;
        }
    }

    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "Saldo: " << cantidad << endl;
    }
};

int main() {
    Cuenta cuenta1("Juan Perez", 15000);
    Cuenta cuenta2("Maria Lopez");

    cuenta1.ingresar(2500);
    cuenta1.retirar(1500);

    cuenta1.mostrar();

    cuenta1.setTitular("Maria Lopez");
    cuenta1.setCantidad(2000);

    cout << endl << "Cuenta actualizada:" << endl;
    cuenta1.mostrar();

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
