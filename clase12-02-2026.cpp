// clase12-02-2026.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

const float DESCUENTO_FRECUENTE = 0.10;
const int ANTIGUEDAD_MINIMA = 2;

class Cliente {
private:
    string nombre;
    string tipo;
    int antiguedad;
public:
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

    string getNombre() {
        return nombre;
    }
};
class Factura {
private:
    int numero;
    int montoBase;
    Cliente cliente;
public:
    Factura(int numero, float montoBase, Cliente cliente) : cliente(cliente) {
        this->numero = numero;
        this->montoBase = montoBase;
    }

    float calcularTotal() {
        bool esFrecuente = cliente.getTipo() == "frecuente";
        bool cumpleAntiguedad = cliente.getAntiguedad() > ANTIGUEDAD_MINIMA;

        if (esFrecuente && cumpleAntiguedad) {
            return montoBase - (montoBase * DESCUENTO_FRECUENTE);
        }
        return montoBase;
    }

    void mostrarFactura() {
        cout << "Factura Nro: " << numero << endl;
        cout << "Cliente: " << cliente.getNombre() << endl;
        cout << "Monto base: " << montoBase << endl;
        cout << "Total a pagar: " << calcularTotal() << endl;
    }
};
//ejercicio2
void ejercicio2() {
    Cliente cliente1 = Cliente("Ana", "frecuente", 4);
    Factura factura1 = Factura(101, 500, cliente1);

    factura1.mostrarFactura();
}
//ejercicio4
/*

const int MAYOR_DE_EDAD = 18;

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
    int getEdad(){
        return edad;
    }
};
class Casa {
private:
    string direccion;
    int precio;
    Propietario propietario;
public:
    Casa(string direccion, int precio, Propietario propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }
    bool esPropietarioValido() {
        int edadPropietario = propietario.getEdad();
        return edadPropietario >= MAYOR_DE_EDAD;
    }
    void mostrarTitularidadValida() {
        if (esPropietarioValido()) {
            cout << "La titularidad es valida" << endl;
        }
        else {
            cout << "la titularidad es invalida" << endl;
        }
    }
};

void ejercicio4() {
    Propietario propietario1 = Propietario("Miguel", 123, 25);
    Casa casa1 = Casa("Av. Livertador", 250, propietario1);
    casa1.mostrarTitularidadValida();
}
*/
int main()
{
    ejercicio2();
    //ejercicio4();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
