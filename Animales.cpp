#include <iostream>
#include <string>

using namespace std;

class Animal
{
    public:

    virtual void hacerSonido() = 0;

};

class Perro : public Animal
{
    public:
    void hacerSonido() 
    {
        cout << " GUAU GUAU" << endl;
    }

};

class Gato : public Animal
{
    public:
    void hacerSonido() 
    {
        cout << " MIAU MIAU" << endl;
    }

};



int main()
{

    Animal** animales = new Animal *[5];

    
    animales[1] = new Perro();
    animales[2] = new Gato();

    animales[1]->hacerSonido();  
    animales[2]->hacerSonido();  


    return 0;
}