// Ejercicio de clase punteros 24-02.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

const int MAYOR_EDAD = 18;
class Propietario
{
private:
    string nombre;
    int dni;
    int edad;
public:
    Propietario()
    {
        nombre = "";
        dni = 0;
        edad = 0;
    }
    Propietario(string nombre, int dni, int edad)
    {
        this->nombre = nombre;
        this->dni = dni;
        this->edad = edad;
    }
    int getEdad()
    {
        return edad;
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << dni << endl;
        cout << "Edad: " << edad << endl;

    }
};
class Casa
{
private:
    string direccion;
    int precio;
    Propietario *propietario;

public:
    Casa(string direccion, int precio, Propietario *propietario)
    {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }
    bool esPropietarioValido()
    {
        int edadpropietario = propietario->getEdad();
        return edadpropietario >= MAYOR_EDAD;
    }
    void mostrarTitularidad()
    {
        if (esPropietarioValido())
        {
            cout << "La titularidad es valida" << endl;
        }
        else
        {
            cout << "La titularidad es invalida" << endl;
        }
    }
    void mostrar()
    {
        propietario->mostrar();
        cout << "direccion: " << direccion << endl;
        cout << "precio: " << precio << endl;
    }
};
void ejercicio4()
{
    Propietario* p1 = new Propietario("pedro", 3455, 19);
    Casa* casa1 = new Casa("Av.america", 2000, p1);
    casa1->mostrar();
    casa1->mostrarTitularidad();
}
int main()
{
    ejercicio4();
}

