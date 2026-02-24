using namespace std;
#include <iostream>
#include<string>
class Propietario {
private:
    string nombre;
    int dni;
    int edad;
public:
    Propietario() {
        nombre = "";
        dni = 0000;
        edad = 18;
    }
    Propietario(string nombre, int dni, int edad) {
        this->nombre = nombre;
        this->dni = dni;
        this->edad = edad;
    }
    int getedad() { return edad; }

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
    bool espropietariovalido() {
        if (propietario.getedad() >= 18)
        {
            return true;

        }
        else {
            return false;
        }
    }
    void mostrar() {
        if (!espropietariovalido)
        {
            cout << "es valido" << endl;
        }
        else {
            cout << "no es valido" << endl;
        }
        
    }

};

int main()
{
    Propietario* propietario1= new Propietario("messi",19,20);
    Casa* casa1 = new Casa("villa", 1000, propietario1);
    Casa->mostrar();

}
