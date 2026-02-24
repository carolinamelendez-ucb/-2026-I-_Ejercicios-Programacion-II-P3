#include <iostream>
#include <string>

using namespace std;

class Propietario
{
    private:
    string nombre;
    int dni;
    int edad;
    public:

    Propietario(string _nombre , int _dni , int _edad)
    {

        this -> nombre = _nombre;
        this ->edad = _edad;
        this ->dni = _dni;
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
    Propietario *propietario;

    public:

    Casa(string _direccion , int _precio, Propietario *_propietario)
    {
        this ->direccion =_direccion;
        this ->precio =_precio;
        this ->propietario =_propietario;
    }

    bool esPropietarioValido()
    {
        if(propietario->getEdad()<18)
        {
            return false;

        }
        else 
        {
            return true;
        }
    }




};

int main()
{

    Propietario* propietario1 = new Propietario("fer", 12345 , 15);

    Casa* casa1 = new Casa("Av. America", 120000 , propietario1);
    
    if (casa1->esPropietarioValido())
    {
        cout <<" El duenio es valido" << endl;

    }
    else 
    {
        cout << " El propietario no es valido " << endl;
    }

    return 0;
}