#include <iostream>
#include <string>
using namespace std;
class Propietario {
private:
    string nombre;
    int dni;
    int edad;
    
public:
    Propietario() {
        nombre = "";
        edad = 0;
        dni = 0;
    }
    Propietario(string nom, int dni, int edad) {
   
        this->nombre = nom;
        this->dni = dni;
        this->edad = edad;
        
    }
    int getEdad() { return edad; }
};

class Casa {
private:
    string direccion;
    int precio;
    Propietario *propietario;
public:
    Casa(string direccion, int precio, Propietario* prop) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = prop;
    }
    bool esPvalido() {
        return propietario->getEdad() >= 18;
    }
};
int main()
{
    Propietario* prope = new Propietario("Benji", 1, 891823);
    Casa* casa = new Casa("Libertador", 1111, prope);
    if (casa->esPvalido()) {
        cout << "Es Valido" << endl;
    }
    else {
        cout << "No es valido" << endl;
    }
};


