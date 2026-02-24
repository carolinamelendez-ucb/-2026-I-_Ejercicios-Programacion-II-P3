
// Ejercicio 24-02.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

class Propietario {
private:
    string nombre;
    int dni;
    int edad;

public:
    Propietario() {}
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
    Casa(){}
    string direccion;
    int precio;
    Propietario *propietario;

public:
    Casa(string direccion, int precio, Propietario *propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }

    int propietarioValido() {
        return propietario->getEdad() > 18;
    }
};



int main()
{
    Propietario* pedro = new Propietario("Pedro", 123, 20);
    Casa* casa1 = new Casa("Circunvalacion", 123, pedro);
    if (casa1->propietarioValido()) {
        cout << "es Valido" << endl;
    }

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
