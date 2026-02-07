// Objeto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
//caracteristicas de una biclicleta
// estado del objeto
#include <iostream>
#include <string>
using namespace std;
//notacion --> Pascal MASE --> MiPrimeraPalabra
//notacion --> Camel MASE --> MiPrimeraPalabra
class Automovil {
private:
    //Atributos
    string marca;
    string modelo;
    string color;
    int anio;
    string combustible;
public:
    Automovil(string marcaA, int anioA, string combustibleA) {
        marca = marcaA;
        anio = anioA;
        combustible = combustibleA;
    };
    void mostrar() {
        cout << "MARCA :" << marca << endl;
        cout << "Año: " << anio << endl;
        cout << "Combustible: " << combustible << endl;


    }
    //Modelos
    void encender() {
        cout << "El auto esta encendido" << endl;
    }
    void acelerar() {
        cout << "El auto esta acelerando" << endl;
    }
    void frenar() {
        cout << "El auto esta frenando" << endl;
    }
    void girar() {
        cout << "El auto esta girando" << endl;
    }
    void apagar() {
        cout << "El auto esta apagado" << endl;
    }
};

int main()
{
    Automovil alumno1("Toyota", 2005, "Gasolina");
    Automovil auto2("IMCRUZ", 2025, "Diesel");
        alumno1.mostrar();
    auto2.mostrar();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
