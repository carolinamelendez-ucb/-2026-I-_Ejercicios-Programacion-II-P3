#include <iostream>
#include <string>
using namespace std;

class cliente
{
private:
    string nombre;
    string tipo;
    int antiguo;

public:
    cliente(string nombre, string tipo, int antiguo)
    {
        this->nombre = nombre;
        this->tipo = tipo;
        this->antiguo = antiguo;
    }
};

class factura
{
    int numerob;
    float monto;
    string objetoc;
public:
    factura(int numerob, float monto, string objetoc)
    {
        this->numerob = numerob;
        this->monto = monto;
        this->objetoc = objetoc;
    }
};