// Practica Ejercicios Aniamal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    virtual void hacerSonido()
    {
        cout << "el animal hace un sonido" << endl;
    }
};
class Perro: public Animal
{

public:
    void  hacerSonido()
    {
        cout<< "El perro hace: ";
        cout << "guau guau" << endl;
    }
};

class Gato : public Animal
{
public:
    void hacerSonido()
    {
        cout << "El gato hace: ";
        cout << "Miau Miau" << endl;
    }

};

int main()
{
    //lista
    Animal** animal = new Animal*[50];
    
    animal[1] = new Perro();
    animal[2] = new Gato;

    animal[1]->hacerSonido();
    animal[2]->hacerSonido();
}

