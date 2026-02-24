// Ejercicio clase 24-02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Propietario{
private:
    string nombre;
    int dni;
    int edad;
public:
    Propietario(){}
    Propietario (string nombre, int dni, int edad){
        this ->nombre = nombre;
        this -> dni = dni;
        this -> edad = edad;
    }
    int getEdad (){
        return edad;
    }
};

class Casa{
private:
    string direccion;
    int precio;
    Propietario *propietario;
public:
    Casa(){}
    Casa (string direccion, int precio, Propietario* propietario){
        this -> direccion = direccion;
        this -> precio = precio;
        this -> propietario = propietario;
    }
    int esPropietarioValido (){
        return propietario->getEdad() > 18; 
    }
};

int main()
{
    Propietario* jose = new Propietario("Jose", 123, 20);
    Casa* casa1 = new Casa("Prado", 250, jose);
    if(casa1->esPropietarioValido()){
     cout<<"es Valido"<<endl;
    }
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
