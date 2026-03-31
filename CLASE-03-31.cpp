#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout << "Sonido del Animal: " << endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() {
        Animal::hacerSonido();
        cout << "Guau Guau" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() {
        Animal::hacerSonido();
        cout << "Miau Miau" << endl;
    }
};


int main()
{
    Animal* animales[3];
    animales[0] = new Perro();
    animales[0]->hacerSonido();
    animales[1] = new Gato();
    animales[1]->hacerSonido();
}

