// CLASE-03-31-TAREA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string Especie;


public:

    Animal (const string& Especie)
        : Especie (Especie)
    {
    }

    virtual void mostrar() = 0;
};

class Perro : public Animal {

    public:

    Perro () : Animal ("Perro")
    {
    }

    void mostrar (){
        cout<<"Especie: " << Especie << endl;
        cout<< "Guau Guau" << endl;
    }
};

class Gato : public Animal {

    public:

    Gato () : Animal ("Gato")
    {
    }

    void mostrar (){
        cout << "Especie: " << Especie << endl;
        cout << "Miau Miau" << endl;
    }
};

int main()
{
    Animal** listaAnimales = new Animal* [10];

    listaAnimales[0] = new Perro();
    listaAnimales[1] = new Gato();

    for(int i = 0; i < 2; i++){
        listaAnimales[i]->mostrar();
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
