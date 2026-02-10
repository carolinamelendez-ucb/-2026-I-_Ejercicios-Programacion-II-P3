// clase-10-02-2026.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
/*
class Casa {
private:
    int nroHabitaciones;
    int precio;
    string ubicacion;
    string material;
    bool estaDisponible;

public:
    string getDisponibilidad() {
        if (estaDisponible) {
            return "DISPONIBLE";
        }
        return "NO DISPONIBLE";
    }
    int getNroHabitaciones() {
        return nroHabitaciones;
    }
    int getPrecio() { return precio; }
    

    Casa(int nroHabitaciones, int precio, string ubicacion) {
        this->nroHabitaciones = nroHabitaciones;
        this->precio = precio;
        this->ubicacion = ubicacion;
        this->material = "";
    }
    Casa(int nroHabitaciones, int precio, string ubicacion) {
        this->nroHabitaciones = nroHabitaciones;
        this->precio = 0;
        this->ubicacion = ubicacion;
        this->material = "";
    }
    Casa(int nroHabitaciones, int precio, string ubicacion) {
        this->nroHabitaciones = 0;
        this->precio = 0;
        this->ubicacion = ubicacion;
    }
    void mostrar() {
        cout << "nro Habitaciones: " << nroHabitaciones << endl;
        cout << "precio: " << precio << endl;
        cout << "ubicacion: " << ubicacion << endl;
        cout << endl;
    }
};*/
class Cuenta {
private:
    string titular;
    double cantidad;

public:
    // constructor: titular obligatorio, cantidad opcional (inicia en 0)
    Cuenta(string titular) {
        this->titular = titular;
        this->cantidad = 0;
    }

    // constructor: titular + cantidad inicial
    Cuenta(string titular, double cantidad) {
        this->titular = titular;
        this->cantidad = cantidad;
    }

    // setters
    void setTitular(string nuevoTitular) {
        this->titular = nuevoTitular;
    }

    void setCantidad(double nuevaCantidad) {
        this->cantidad = nuevaCantidad;
    }

    // getters
    string getTitular() {
        return titular;
    }

    double getCantidad() {
        return cantidad;
    }

    void mostrar()
    {
        cout << "TITULAR: " << titular << endl;
        cout << "CANTIDAD: " << cantidad << endl;
    }

    // ingresar: si es negativa, no hace nada
    void ingresar(double monto) {
        if (monto > 0) {
            this->cantidad = this->cantidad + monto;
        }
    }

    // retirar: si queda negativo, pasa a 0
    void retirar(double monto) {
        if (monto < 0) {
            return; // si te pasan negativo, no hacemos nada
        }

        if (this->cantidad - monto < 0) {
            this->cantidad = 0;
        }
        else {
            this->cantidad = this->cantidad - monto;
        }
    }
};


int main()
{
   /* Casa miCasa = Casa(20, 850, "Av. Circunvalacion");
    cout<<"-- PRECIO:"<<miCasa.getPrecio
    miCasa.mostrar();*/
    Cuenta cuenta1 = Cuenta("Juan Perez");
    Cuenta cuenta2 = Cuenta("Maria Lopez", 500.5);

    cout << "---- ESTADO INICIAL ----" << endl;
    cuenta1.mostrar();
    cout << "------------------------" << endl;
    cuenta2.mostrar();

    // operaciones en cuenta1
    cuenta1.ingresar(200);
    cuenta1.ingresar(-50); // no hace nada
    cuenta1.retirar(80);
    cuenta1.retirar(500);  // queda en 0

    // operaciones en cuenta2
    cuenta2.ingresar(100.75);
    cuenta2.retirar(50.25);

    cout << "\n---- ESTADO FINAL ----" << endl;
    cuenta1.mostrar();
    cout << "----------------------" << endl;
    cuenta2.mostrar();

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
