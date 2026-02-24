// EJERCICIO_CLASE0224.cpp : 

#include <iostream>
#include <string>
using namespace std;

const int MAYOR_EDAD = 18;

class Propietario
{
private:
    string nombre;
    int DNI;
    int edad;
public:
    Propietario(string nombre, int DNI, int edad)
    {
        this->nombre=nombre;
        this->DNI = DNI;
        this->edad = edad;
    }
    string getNombre()
    {
        return nombre;
    }
    int getEdad()
    {
        return edad;
    }
};

class Casa
{
private:
    string direccion;
    int precio;
    Propietario* propietario;

public:
    Casa(string dierccion, int precio, Propietario* propietario)
    {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }

    bool propietarioValido()
    {
        if (propietario->getEdad() >= MAYOR_EDAD)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void mostrar()
    {
        cout << "Nombre: " << propietario->getNombre() << endl;
        cout << "Propietario valido: " << (propietarioValido() ? "Si" : "No") << endl;
    }
};

int main()
{
    Propietario* P1 = new Propietario("Sara", 123, 23);
    Casa* c1 = new Casa("Av. Galindo", 245, P1);

    c1->mostrar();
}

