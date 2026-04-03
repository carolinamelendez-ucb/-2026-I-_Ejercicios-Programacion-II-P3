#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    int edad;
    string nombre;
public:
    Animal(int edad, string nombre)
    {
        this->edad = edad;
        this->nombre = nombre;
    }
    virtual void hacerSonido()
    {
        cout << "Sonido propio del animal" << endl;
    }
    virtual ~Animal() {}
};

class Perro : public Animal
{
private:
    string raza;
public:
    Perro(int edad, string nombre, string raza): Animal(edad, nombre)
    {
        this->raza = raza;
    }
    void hacerSonido()
    {
        cout <<"Guau guau" << endl;
    }
};

class Gato : public Animal
{
private:
    string raza;
public:
    Gato(int edad, string nombre, string raza): Animal(edad, nombre)
    {
        this->raza = raza;
    }
    void hacerSonido()
    {
        cout << "Miau miau" << endl;
    }
};

int main()
{
    Animal* animales[2];

    animales[0] = new Perro(3, "Firulais", "Labrador");
    animales[1] = new Gato(2, "Michi", "Siames");

    for (int i = 0; i < 2; i++)
    {
        animales[i]->hacerSonido();
    }

    for (int i = 0; i < 2; i++)
    {
        delete animales[i];
    }
    return 0;
}