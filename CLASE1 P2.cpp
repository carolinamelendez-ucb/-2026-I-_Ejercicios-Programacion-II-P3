// CLASE1 P2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;
class bicicleta
{
private:
    int velocidad;
    string color;
    string tipo;
    string marca;

public:
    bicicleta(int velo, string color, string tipo, string marca)
    {
        velocidad = velo;
        this->color = color;
        this->tipo = tipo;
        this->marca = marca;
    }

    //metodos
    void mostrar()
    {
        cout << velocidad<<endl;
        cout << color << endl;
        cout << tipo << endl;
        cout << marca << endl;
    }

    void avanzar() 
    {
        cout << "bicicleta avanza.....";
    }
    void detener()
    {
        cout << "bicicleta se detiene.....";
    }
    void desmantelar()
    {
        cout << "bicicleta desmantela.....";
    }
    void cambiarcaja()
    {
        cout << "bicicleta cambia de caja.....";
    }
};

class Auto
{
private:
    string modelo;
    string marca;
    int placa;
   // int anio;
    string color;
public:
    //los argumrntos del constructor solo tienen alcanze dentro
    Auto()
    {

    }
    Auto(string modelo,string marca,int placa,string color)
    {
        this->modelo = modelo;
        this->marca = marca;
        this->placa = placa;
        //this->anio = anio;
        this->color = color;
    }
    void mostrar()
    {
        cout << modelo;
        cout << marca;
        cout << placa;
        //cout << anio;
        cout << color;
    }
    void setColor(string colorN)
    {
        this->color = colorN;
    }
};
int main()
{
    Auto auto1;
    Auto auto2 = Auto("2019", "bmw", 19, "rojo");
    auto2.setColor("negro");

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
